#include "HttpServer.h"
#include <stdlib.h>
#include "HttpParser.h"
#include "SocketServer.h"
#include "JsonParser.h"
#include <string.h>

void httpS_InitializeMethods(PHttpServer self);

PHttpServer httpS_Create(uint16_t port) {
  PHttpServer self = malloc(sizeof(HttpServer));
  memset(self, 0, sizeof(HttpServer));
  self->server = sock_Create(port);
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
  free(str.buffer);
  return response;
}

void remote_OnReceiveMessage(PDataFragment frag, void *buffer) {
  PHttpServer self = buffer;
  sock_PushCloseConnections(self->server, &frag->conn);
  if(!self->onReceive) {
    return ;
  }
  PHttpRequest req = http_Request_Parse(frag->data, frag->size);
  if(!req) {
    return ;
  }
  PHttpResponse response = httpS_PrivateCaller(self, req);
  HttpString responseString = http_Response_ToString(response);
  DataFragment dt = {
    .conn = frag->conn,
    .data = responseString.buffer,
    .persistent = 1,
    .size = responseString.sz
  };
  sock_Write_Push(self->server, &dt);
  free(responseString.buffer);
  http_Response_Delete(response);
}

void httpS_InitializeMethods(PHttpServer self) {
  PSocketMethod onReceive = sock_Method_Create(
    (void *)remote_OnReceiveMessage,
    self
  );
  self->server->onReceiveMessage = onReceive;
}

void httpS_Delete(PHttpServer self) {
  sock_Method_Delete(self->server->onReceiveMessage);
  sock_Delete(self->server);
  free(self);
}

void httpS_OnFrame(PHttpServer self, uint64_t deltaMS) {
  sock_OnFrame(self->server, deltaMS);
}