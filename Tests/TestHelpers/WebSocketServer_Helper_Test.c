#include "WebSocketServer_Helper_Test.h"
#include "Socket_Helper_test.h"
#include "Vector.h"
#include "WebSocketsTranslator.h"
#include "TimeFragment.h"
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <unistd.h>
#include <stdlib.h>

PConnection test_Wss_Util_Connect(PWebSocketServer wssServer, char *input) {
  PConnection connection = test_Util_Connect(wssServer->socketServer);
  test_Util_SendMessage(wssServer->socketServer, connection, input, strlen(input));
  return connection;
}

PConnection test_Wss_Util_ExchangeConnection(PWebSocketServer wssServer) {
  char *handshakeMessage = "\
GET /chat HTTP/1.1\r\n\
Host: example.com:80\r\n\
Upgrade: websocket\r\n\
Connection: Upgrade\r\n\
Sec-WebSocket-Key: dGhlIHNhbXBsZSBub25jZQ==\r\n\
Sec-WebSocket-Version: 13\r\n\
\r\n";
char *handshakeAccepted = "\
HTTP/1.1 101 Undefined\r\n\
Connection: Upgrade\r\n\
Content-Length: 0\r\n\
Sec-WebSocket-Accept: s3pPLMBiTxaQ9kYGzzhZRbK+xOo=\r\n\
Upgrade: websocket\r\n\
\r\n";
  PConnection connection = test_Wss_Util_Connect(wssServer, handshakeMessage);
  test_Util_Expect(connection, handshakeAccepted, strlen(handshakeAccepted));
  return connection;
}

void test_Wss_RepeatFramesDiff(PWebSocketServer self, uint64_t deltaMS, uint32_t repeats) {
  while(repeats--) {
    wss_OnFrame(self, deltaMS);
  }
}

void test_Wss_BufferMessage(PWebSocketServer wssServer, PConnection conn, char *buffer, size_t sz) {
  WebSocketObject wssObj = (WebSocketObject) {
    .buffer = buffer,
    .sz = sz,
    .opcode = OPCODE_BINARY
  };
  char *message = wbs_Masked_ToWebSocket(wssObj);
  test_Util_BufferMessage(wssServer->socketServer, conn, message, wbs_FullMessageSize(message));
  free(message);
}

void test_Wss_PingPong(PWebSocketServer wssServer, PConnection conn, uint64_t pingAt) {
  wss_OnFrame(wssServer, pingAt / 2);
  wss_OnFrame(wssServer, pingAt / 2 - 1);
  test_Wss_SendPong(wssServer, conn);
  wss_OnFrame(wssServer, pingAt / 2);
}

void test_Wss_SendMessage(PWebSocketServer wssServer, PConnection conn, char *buffer, size_t sz) {
  WebSocketObject wssObj = (WebSocketObject) {
    .buffer = buffer,
    .sz = sz,
    .opcode = OPCODE_BINARY
  };
  char *message = wbs_Masked_ToWebSocket(wssObj);
  test_Util_SendMessage(wssServer->socketServer, conn, message, wbs_FullMessageSize(message));
  free(message);
}

void test_Wss_SendPing(PWebSocketServer wssServer, PConnection conn) {
  WebSocketObject wssObj = (WebSocketObject) {
    .buffer = "1000",
    .sz = sizeof("1000") - 1,
    .opcode = OPCODE_PING
  };
  char *message = wbs_Masked_ToWebSocket(wssObj);
  test_Util_SendMessage(wssServer->socketServer, conn, message, wbs_FullMessageSize(message));
  free(message);
}

void test_Wss_SendPong(PWebSocketServer wssServer, PConnection conn) {
  WebSocketObject wssObj = (WebSocketObject) {
    .buffer = "1000",
    .sz = sizeof("1000") - 1,
    .opcode = OPCODE_PONG
  };
  char *message = wbs_Masked_ToWebSocket(wssObj);
  test_Util_SendMessage(wssServer->socketServer, conn, message, wbs_FullMessageSize(message));
  free(message);
}

void test_Wss_WaitAndRunUntil(PWebSocketServer sv, int64_t timeout, uint8_t (*method)(void *), void *buffer) {
  int64_t crtTime = tf_CurrentTimeMS();
  while(1) {
    if(method(buffer)) {
      return ;
    }
    assert_true(timeout >= 0);
    usleep(10 * 1000);
    int64_t currentTime = tf_CurrentTimeMS();
    int64_t deltaMS = currentTime - crtTime;
    timeout -= deltaMS;
    wss_OnFrame(sv, deltaMS);
    crtTime = currentTime;  
  }
}

void test_Wss_Util_Delete(PWebSocketServer self) {
  if(self->onConnect) {
    sock_Method_Delete(self->onConnect);
  }
  if(self->onReceiveMessage) {
    sock_Method_Delete(self->onReceiveMessage);
  }
  if(self->onRelease) {
    sock_Method_Delete(self->onRelease);
  }
  wss_Delete(self);
}

void test_Wss_Expect(PConnection conn, char *buffer, size_t sz) {
  DataFragment dt = sock_Client_Receive(conn);
  Vector receivedData = wbs_FromWebSocket(dt.data, dt.size);
  assert_non_null(receivedData);
  WebSocketObject *objects = receivedData->buffer;
  uint8_t objectFound = 0;
  for(size_t i = 0, c = receivedData->size; i < c; i++) {
    if(!memcmp(objects[i].buffer, buffer, sz)) {
      objectFound = 1;
      break;
    }
  }
  assert_true(objectFound);
  free(dt.data);
  vct_Delete(receivedData);
}