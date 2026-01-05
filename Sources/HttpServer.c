#include "HttpServer.h"
#include <stdlib.h>
#include "HttpParser.h"
#include "SocketServer.h"
#include "JsonParser.h"
#include <string.h>
#include "NetworkBuffer.h"
#include "Array.h"

typedef struct HttpConnectionProtocol_t {
  Connection conn;
  PNetworkBuffer buff;
} HttpConnectionProtocol;

void httpS_InitializeMethods(PHttpServer self);
static void httpS_ReleaseConns(const PHttpServer self);

PHttpServer httpS_Create(uint16_t port) {
  PHttpServer self = crm_Alloc(sizeof(HttpServer));
  memset(self, 0, sizeof(HttpServer));
  self->server = sock_Create(port);
  self->connections = arr_Init(sizeof(HttpConnectionProtocol));
  self->maximumRequestSize = 1024 * 1024 * 10;
  httpS_InitializeMethods(self);
  return self;
}

void httpS_SetMethod(PHttpServer self, PSocketMethod onReceive) {
  self->onReceive = onReceive;
}

PHttpResponse httpS_PrivateCaller(PHttpServer self, PHttpRequest req) {
  PHttpResponse (*caller)(PHttpRequest, void *) = (PHttpResponse (*)(PHttpRequest, void *))self->onReceive->method;
  return caller(req, self->onReceive->mirrorBuffer);
}

void remote_OnConnect(Connection conn, void *mirror) {
  PHttpServer self = mirror;
  HttpConnectionProtocol proto = {
    .conn = conn,
    .buff = tpd_Create(self->maximumRequestSize)
  };
  arr_Push(self->connections, &proto);
}

static void httpS_ReleaseConns(const PHttpServer self) {
  HttpConnectionProtocol *conns = self->connections->buffer;
  for(size_t i = 0, c = self->connections->size; i < c; i++) {
    tpd_Delete(conns[i].buff);
  }
  arr_Delete(self->connections);
}

JsonElement httpS_Json_Get(PHttpRequest req) {
  if(!req->body.buffer) {
    return (JsonElement) {
      .type = JSON_INVALID
    };
  }
  char *_endingBuffer = NULL;
  JsonElement jsonElement = json_Parse((HttpString) {
    .buffer = req->body.buffer,
    .sz = req->body.sz
  }, &_endingBuffer);
  if(jsonElement.type != JSON_JSON || _endingBuffer != req->body.buffer + req->body.sz) {
    json_DeleteElement(jsonElement);
    return (JsonElement) {
      .type = JSON_INVALID
    };
  }
  return jsonElement;
}

PHttpResponse httpS_Json_Post(JsonElement jsn) {
  PHttpResponse response = http_Response_Create();
  HttpString str = json_Element_ToString(jsn);
  http_Response_SetBody(response, &str);
  if(jsn.type == JSON_JSON) {
    http_Response_SetJSON(response);
  }
  crm_Free(str.buffer);
  return response;
}

RequestStruct httpS_Request_StructInit(HttpString ip, uint16_t port) {
  RequestStruct response;
  memset(&response, 0, sizeof(RequestStruct));
  response.ip[ip.sz] = 0;
  memcpy(response.ip, ip.buffer, ip.sz);
  response.port = port;
  return response;
}

static HttpConnectionProtocol *httpS_Request_FindConn(const PHttpServer self, const PDataFragment dt) {
  HttpConnectionProtocol *conns = self->connections->buffer;
  for(size_t i = 0, c = self->connections->size; i < c; i++) {
    if(conns[i].conn.fd == dt->conn.fd) {
      return &conns[i];
    }
  }
  return NULL;
}

static PHttpRequest httpS_Request_ParseData(const PHttpServer self, const PDataFragment dt, uint8_t *incomplete) {
  *incomplete = 0;
  HttpConnectionProtocol *protocol = httpS_Request_FindConn(self, dt);
  if(!protocol) {
    return NULL;
  }
  if(!tpd_Push(protocol->buff, dt->data, dt->size)) {
    return NULL;
  }
  PHttpRequest request = http_Request_NB_Get(protocol->buff);
  if(!request) {
    *incomplete = 1;
    return NULL;
  }
  return request;
}

void remote_OnReceiveMessage(PDataFragment frag, void *buffer) {
  PHttpServer self = buffer;
  if(!self->onReceive) {
    sock_PushCloseConnections(self->server, &frag->conn);
    return ;
  }
  uint8_t incomplete;
  // PHttpRequest req = http_Request_Parse(frag->data, frag->size);
  PHttpRequest req = httpS_Request_ParseData(self, frag, &incomplete);
  if(incomplete) {
    return ;
  }
  sock_PushCloseConnections(self->server, &frag->conn);
  if(!req) {
    return ;
  }
  PHttpResponse response = httpS_PrivateCaller(self, req);
  HttpString responseString = http_Response_ToString(response);
  if(!responseString.buffer) {
    return ;
  }
  DataFragment dt = {
    .conn = frag->conn,
    .data = responseString.buffer,
    .persistent = 1,
    .size = responseString.sz
  };
  sock_Write_Push(self->server, &dt);
  crm_Free(responseString.buffer);
  http_Response_Delete(response);
  http_Request_Delete(req);
}

void httpS_InitializeMethods(PHttpServer self) {
  PSocketMethod onReceive = sock_Method_Create(
    (void *)remote_OnReceiveMessage,
    self
  );
  self->server->onReceiveMessage = onReceive;
  PSocketMethod onConnect = sock_Method_Create(
    (void *)remote_OnConnect,
    self
  );
  self->server->onConnectionAquire = onConnect;
}

void httpS_Delete(PHttpServer self) {
  sock_Method_Delete(self->server->onConnectionAquire);
  sock_Method_Delete(self->server->onReceiveMessage);
  httpS_ReleaseConns(self);
  sock_Delete(self->server);
  crm_Free(self);
}

void httpS_OnFrame(PHttpServer self, uint64_t deltaMS) {
  sock_OnFrame(self->server, deltaMS);
}