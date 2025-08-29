#include "WebSocketServer.h"
#include <string.h>
#include <openssl/sha.h>
#include <openssl/evp.h>

void wss_SetMethods(PWebSocketServer self);
void _wss_OnConnect(PConnection connection, void *buffer);
void _wss_OnReceive(PDataFragment dt, void *buffer);

PWebSocketServer wss_Create(uint16_t port) {
  PWebSocketServer self = malloc(sizeof(WebSocketServer));
  memset(self, 0, sizeof(WebSocketServer));
  self->socketServer = sock_Create(port);
  self->pendingConnections = vct_Init(sizeof(Connection));
  wss_SetMethods(self);
  return self;
}

void wss_SetMethods(PWebSocketServer self) {
  PSocketMethod _onConnect = sock_Method_Create(
    _wss_OnConnect,
    self
  );
  self->methodsBundle._onConnect = _onConnect;
  self->socketServer->onConnectionAquire = _onConnect;
  PSocketMethod _onReceive = sock_Method_Create(
    _wss_OnReceive,
    self
  );
  self->methodsBundle._onReceive = _onReceive;
  self->socketServer->onReceiveMessage = _onReceive;
}

void wss_Delete(PWebSocketServer self) {
  sock_Method_Delete(self->methodsBundle._onReceive);
  sock_Method_Delete(self->methodsBundle._onConnect);
  sock_Delete(self->socketServer);
  vct_Delete(self->pendingConnections);
  free(self);
}

static inline size_t wss_FindConnectionOnThePull(PWebSocketServer self, PConnection conn, uint8_t *found) {
  *found = 0;
  Connection *connections = self->pendingConnections->buffer;
  for(size_t i = 0, c = self->pendingConnections->size; i < c; i++) {
    if(conn->fd == connections[i].fd) {
      *found = 1;
      return i;
    }
  }
  return 0;
}

char *webSocketKey(PHttpString sec_websocket_key) {
  static const char *GUID = "258EAFA5-E914-47DA-95CA-C5AB0DC85B11";
  if (!sec_websocket_key->buffer) return NULL;
  size_t key_len = sec_websocket_key->sz;
  size_t guid_len = strlen(GUID);
  size_t cat_len  = key_len + guid_len;
  char *cat = (char *)malloc(cat_len + 1);
  if (!cat) return NULL;
  memcpy(cat, sec_websocket_key->buffer, key_len);
  memcpy(cat + key_len, GUID, guid_len);
  cat[cat_len] = '\0';
  unsigned char sha1_digest[SHA_DIGEST_LENGTH];
  SHA1((const unsigned char *)cat, cat_len, sha1_digest);
  free(cat);
  int b64_len = 4 * ((SHA_DIGEST_LENGTH + 2) / 3);
  char *accept = (char *)malloc(b64_len + 1);
  if (!accept) return NULL;
  EVP_EncodeBlock((unsigned char *)accept, sha1_digest, SHA_DIGEST_LENGTH);
  accept[b64_len] = '\0';
  return accept;
}

PHttpResponse wss_Response(PWebSocketServer self, PHttpRequest req) {
  PHttpResponse response = http_Response_Empty();
  response->response = 101;
  response->httpCode = "Switching Protocols";
  http_Response_Set(response, "Upgrade", sizeof("Upgrade") - 1, "websocket", sizeof("websocket") - 1);
  http_Response_Set(response, "Connection", sizeof("Connection") - 1, "Upgrade", sizeof("Upgrade") - 1);
  HttpString key = http_Request_GetValue(req, "Sec-WebSocket-Key");
  if(!key.buffer) {
    http_Response_Delete(response);
    return NULL;
  }
  char *newKey = webSocketKey(&key);
  http_Response_Set(response, "Sec-WebSocket-Accept", sizeof("Sec-WebSocket-Accept") - 1, newKey, strlen(newKey));
  free(newKey);
  return response;
}

uint8_t wss_ProcessConnectionRequest(PWebSocketServer self, PDataFragment dt) {
  PHttpRequest req = http_Request_Parse(dt->data, dt->size);
  if(!req) {
    return 0;
  }
  PHttpResponse response = wss_Response(self, req);
  http_Request_Delete(req);
  if(!response) {
    return 0;
  }
  HttpString responseChar = http_Response_ToString(response);
  DataFragment frag = {
    .conn = dt->conn,
    .data = responseChar.buffer,
    .persistent = 1,
    .size = responseChar.sz
  };
  sock_Write_Push(self->socketServer, &frag);
  http_Response_Delete(response);
  free(responseChar.buffer);
  return 1;
}

void _wss_OnReceive(PDataFragment dt, void *buffer) {
  PWebSocketServer self = buffer;
  uint8_t found;
  size_t connIndex = wss_FindConnectionOnThePull(self, &dt->conn, &found);
  if(!found) {
    if(self->onReceiveMessage) {
      void (*cMethod)(PDataFragment, void *) = self->onReceiveMessage->method;
      cMethod(dt, self->onReceiveMessage->mirrorBuffer);
    }
    return ;
  }
  if(!wss_ProcessConnectionRequest(self, dt)) {
    sock_PushCloseConnections(self->socketServer, &dt->conn);
  }
  vct_RemoveElement(self->pendingConnections, connIndex);
}

void _wss_OnConnect(PConnection connection, void *buffer) {
  PWebSocketServer self = buffer;
  if(self->onConnect) {
    void (*cMethod)(PConnection, void *) = self->onConnect->method;
    cMethod(connection, self->onConnect->mirrorBuffer);
  }
  vct_Push(self->pendingConnections, connection);
}

void wss_OnFrame(PWebSocketServer self, uint64_t deltaMS) {
  sock_OnFrame(self->socketServer, deltaMS);
}