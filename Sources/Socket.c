#include "SocketServer.h"
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>
#include <netdb.h>
#include <fcntl.h>
#include <assert.h>
#include <stdio.h>
#include <sys/ioctl.h>

#define SA struct sockaddr
#define MAX_CONNECTIONS_PER_SERVER 1024

typedef struct CloseConnStruct_t {
  PSocketServer self;
  Connection conn;
  size_t index;
} CloseConnStruct;

typedef CloseConnStruct *PCloseConnStruct;

uint8_t _sock_StartConnections(PSocketServer self);

void sigpipe_handler(int signum) {
  return ;
}

PSocketServer sock_Create(uint16_t port) {
  PSocketServer server = malloc(sizeof(SocketServer));
  memset(server, 0, sizeof(SocketServer));
  server->connections = vct_Init(sizeof(Connection));
  server->port = port;
  server->maxActiveConnections = 16;
  server->maxBytesPerReadConnection = 1024 * 1024 * 10; /* 10 megabytes of reading per socket of total bytes */
  server->inputReads = vct_Init(sizeof(DataFragment));
  server->outputCommands = vct_Init(sizeof(DataFragment));
  if(!_sock_StartConnections(server)) {
    sock_Delete(server);
    return NULL;
  }
  return server;
}

void _sock_CloseConnection(void *buffer) {
  PCloseConnStruct conn = buffer;
  close(conn->conn.fd);
  // printf("Closing connection in fd %d with index %ld!\n", conn->conn.fd, conn->index);
  vct_RemoveElement(conn->self->connections, conn->index);
  free(buffer);
}

void sock_PushCloseConnMethod(PSocketServer self, Connection conn, size_t index) {
  if(!self->timeServer.timeServer) {
    return ;
  }
  PCloseConnStruct closeCmd = malloc(sizeof(CloseConnStruct));
  closeCmd->conn = conn;
  closeCmd->self = self;
  closeCmd->index = index;
  TimeMethod timeFragment = (TimeMethod) {
    .method = (void *)_sock_CloseConnection,
    .buffer = closeCmd
  };
  tf_ExecuteAfter(self->timeServer.timeServer, timeFragment, self->timeServer.timeout);
}

void sock_SetMaxConnections(PSocketServer self, int32_t maxActiveConnections) {
  assert(maxActiveConnections < MAX_CONNECTIONS_PER_SERVER);
  self->maxActiveConnections = maxActiveConnections;
}

void sock_Write_Push(PSocketServer self, DataFragment *dt) {
  char *memory = dt->data;
  if(dt->persistent) {
    memory = malloc(dt->size);
    memcpy(memory, dt->data, dt->size);
  }
  DataFragment newDt = *dt;
  newDt.data = memory;
  vct_Push(self->outputCommands, &newDt);
}

uint8_t _sock_StartConnections(PSocketServer self) {
  int32_t sockfd;
  struct sockaddr_in servaddr;
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    return 0;
  }
  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(self->port);
  signal(SIGPIPE, sigpipe_handler);
  const int32_t trueFlag = 1;
  if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &trueFlag, sizeof(int)) < 0) {
    return 0;
  }
  if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) {
    return 0;
  }
  if ((listen(sockfd, 5)) != 0) {
    return 0;
  }
  self->serverFD.fd = sockfd;
  fcntl(sockfd, F_SETFL, fcntl(sockfd, F_GETFL, 0) | O_NONBLOCK);
  return 1;
}

static inline void sock_ExecuteMetaMethod(Connection *conn, PSocketMethod routine) {
  if(!routine) {
    return ;
  }
  void (*method)(Connection, void *) = routine->method;
  method(*conn, routine->mirrorBuffer);
}

static inline void sock_ExecuteOnReceiveMethod(DataFragment *dataFragment, PSocketMethod routine) {
  if(!routine) {
    return ;
  }
  void (*method)(DataFragment *, void *) = routine->method;
  method(dataFragment, routine->mirrorBuffer);
}

void sock_AddConnectionTimeout(PSocketServer self, int64_t expireAfter) {
  self->timeServer.timeServer = tf_Create();
  self->timeServer.timeout = expireAfter;
}

static inline void sock_OnReceiveMessage(PSocketServer self, Connection *conn, size_t index) {
  int32_t count = 0;
  int32_t error = ioctl(conn->fd, FIONREAD, &count);
  if(!count || error == -1) {
    return ;
  }
  if(count >= self->maxBytesPerReadConnection) {
    sock_ExecuteMetaMethod(conn, self->onConnectionRelease);
    vct_RemoveElement(self->connections, index);
    return ;
  }
  void *buffer = malloc(count);
  (void)!read(conn->fd, buffer, count);
  DataFragment dt = (DataFragment) {
    .conn = *conn,
    .data = buffer,
    .persistent = 0,
    .size = count
  };
  sock_ExecuteOnReceiveMethod(&dt, self->onReceiveMessage);
  free(buffer);
}

void sock_ProcessReadMessage(PSocketServer self) {
  Connection *conn = self->connections->buffer;
  for(size_t i = 0, c = self->connections->size; i < c; i++) {
    sock_OnReceiveMessage(self, &conn[i], i);
  }
}

static inline void sock_AcceptConnectionsRoutine(PSocketServer self) {
  if(self->maxActiveConnections <= self->connections->size) {
    return ;
  }
  struct sockaddr_in cli;
  socklen_t len;
  int32_t sockfd = self->serverFD.fd;
  len = sizeof( (struct sockaddr *) &len);
  int32_t connfd = accept(sockfd, (SA*)&cli, &len);
  if (connfd < 0) {
    return ;
  }
  Connection currentCon = (Connection) {
    .fd = connfd
  };
  sock_PushCloseConnMethod(self, currentCon, self->connections->size);
  vct_Push(self->connections, &currentCon);
  sock_ExecuteMetaMethod(&currentCon, self->onConnectionAquire);
}

static inline void sock_WriteBufferCleanup(PSocketServer self) {
  DataFragment *dataFragments = self->outputCommands->buffer;
  for(size_t i = 0, c = self->outputCommands->size; i < c; i++) {
    if(dataFragments[i].persistent) {
      free(dataFragments[i].data);
    }
  }
  vct_Clear(self->outputCommands);
}

PSocketMethod sock_Method_Create(void *method, void *mirrorBuffer) {
  PSocketMethod self = malloc(sizeof(SocketMethod));
  self->method = method;
  self->mirrorBuffer = mirrorBuffer;
  return self;
}

void sock_Method_Delete(PSocketMethod self) {
  free(self);
}

void sock_ProcessWriteRequests_t(PSocketServer self, Vector markedForDeletionRequests) {
  DataFragment *dataFragments = self->outputCommands->buffer;
  for(size_t i = 0, c = self->outputCommands->size; i < c; i++) {
    if(write(dataFragments[i].conn.fd, dataFragments[i].data, dataFragments[i].size) < 0) {
      vct_Push(markedForDeletionRequests, &i);
      sock_ExecuteMetaMethod(&dataFragments[i].conn, self->onConnectionRelease);
      close(dataFragments[i].conn.fd);
    }
  }
}

static inline void sock_ProcessWriteRequests(PSocketServer self)  {
  Vector markedForDeletionRequests = vct_Init(sizeof(size_t));
  sock_ProcessWriteRequests_t(self, markedForDeletionRequests);
  sock_WriteBufferCleanup(self);
  Vector prunnedArray = vct_RemoveElements(self->connections, markedForDeletionRequests);
  vct_Delete(self->connections);
  vct_Delete(markedForDeletionRequests);
  self->connections = prunnedArray;
}

static inline void sock_ClearConnections(PSocketServer self) {
  Connection *conn = self->outputCommands->buffer;
  for(size_t i = 0, c = self->outputCommands->size; i < c; i++) {
    close(conn[i].fd);
  }
}

PConnection sock_FindConnectionByIndex(PSocketServer self, size_t index) {
  if(index >= self->connections->size) {
    return NULL;
  }
  Connection *conn = self->connections->buffer;
  return conn + index;
}

static inline void sock_Time_OnFrame(PSocketServer self, uint64_t deltaMS) {
  if(self->timeServer.timeServer) {
    tf_OnFrame(self->timeServer.timeServer, deltaMS);
  }
}

void sock_OnFrame(PSocketServer self, uint64_t deltaMS) {
  sock_AcceptConnectionsRoutine(self);
  sock_ProcessWriteRequests(self);
  sock_ProcessReadMessage(self);
  sock_Time_OnFrame(self, deltaMS);
}

static inline void sock_Time_Delete(PSocketServer self) {
  if(self->timeServer.timeServer) {
    tf_Delete(self->timeServer.timeServer);
  }
}

int32_t _sock_Client_Conn(uint16_t port, char *ip) {
  int32_t sock;
  struct sockaddr_in server_addr;
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    return -1;
  }
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);

  if (inet_pton(AF_INET, ip, &server_addr.sin_addr) <= 0) {
    close(sock);
    return -1;
  }
  if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
    close(sock);
    return -1;
  }
  return sock;
}

PConnection sock_Client_Connect(uint16_t port, char *ip) {
  int32_t fd = _sock_Client_Conn(port, ip);
  if(fd == -1) {
    return NULL;
  }
  PConnection conn = malloc(sizeof(Connection));
  conn->fd = fd;
  return conn;
}

void sock_Client_SendMessage(PDataFragment frag) {
  (void)!write(frag->conn.fd, frag->data, frag->size);
}

void sock_Client_Free(PConnection conn) {
  close(conn->fd);
  free(conn);
}

void sock_Delete(PSocketServer self) {
  vct_Delete(self->inputReads);
  sock_ClearConnections(self);
  vct_Delete(self->outputCommands);
  vct_Delete(self->connections);
  close(self->serverFD.fd);
  sock_Time_Delete(self);
  free(self);
}