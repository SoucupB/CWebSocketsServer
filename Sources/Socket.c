#include "Socket.h"
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
  server->inputReads = vct_Init(sizeof(DataFragment));
  server->outputCommands = vct_Init(sizeof(DataFragment));
  if(!_sock_StartConnections(server)) {
    sock_Delete(server);
    return NULL;
  }
  return server;
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

static inline void sock_ExecuteMetaMethod(Connection conn, PSocketMethod routine) {
  if(!routine) {
    return ;
  }
  void (*method)(Connection, void *) = routine->method;
  method(conn, routine->mirrorBuffer);
}

static inline void sock_ExecuteOnReceiveMethod(DataFragment *dataFragment, PSocketMethod routine) {
  if(!routine) {
    return ;
  }
  void (*method)(DataFragment *, void *) = routine->method;
  method(dataFragment, routine->mirrorBuffer);
}

static inline void sock_OnReceiveMessage(PSocketServer self, Connection *conn) {
  int32_t count = 0;
  int32_t error = ioctl(conn->fd, FIONREAD, &count);
  if(!count || error == -1) {
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
    sock_OnReceiveMessage(self, &conn[i]);
  }
}

static inline void sock_AcceptConnectionsRoutine(PSocketServer self) {
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
  vct_Push(self->connections, &currentCon);
  sock_ExecuteMetaMethod(currentCon, self->onConnectionAquire);
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

void sock_ProcessWriteRequests_t(PSocketServer self, int32_t *markedForDeletionRequests, size_t *sz) {
  *sz = 0;
  DataFragment *dataFragments = self->outputCommands->buffer;
  for(size_t i = 0, c = self->outputCommands->size; i < c; i++) {
    if(write(dataFragments[i].conn.fd, dataFragments[i].data, dataFragments[i].size) < 0) {
      markedForDeletionRequests[(*sz)++] = dataFragments[i].conn.fd;
    }
  }
}

static inline void sock_ProcessWriteRequests(PSocketServer self)  {
  int32_t markedForDeletionRequests[MAX_CONNECTIONS_PER_SERVER];
  size_t sz = 0;
  sock_ProcessWriteRequests_t(self, markedForDeletionRequests, &sz);
  sock_WriteBufferCleanup(self);
}

static inline void sock_ClearConnections(PSocketServer self) {
  Connection *conn = self->outputCommands->buffer;
  for(size_t i = 0, c = self->outputCommands->size; i < c; i++) {
    close(conn[i].fd);
  }
}

void sock_OnFrame(PSocketServer self) {
  sock_AcceptConnectionsRoutine(self);
  sock_ProcessWriteRequests(self);
  sock_ProcessReadMessage(self);
}

void sock_Delete(PSocketServer self) {
  vct_Delete(self->inputReads);
  vct_Delete(self->outputCommands);
  vct_Delete(self->connections);
  close(self->serverFD.fd);
  sock_ClearConnections(self);
  free(self);
}