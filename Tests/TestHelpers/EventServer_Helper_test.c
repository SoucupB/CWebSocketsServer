#include "EventServer_Helper_test.h"
#include "WebSocketServer_Helper_Test.h"

void test_Util_Evs_Delete(PEventServer self) {
  if(self->onClose) {
    sock_Method_Delete(self->onClose);
  }
  if(self->onReceive) {
    sock_Method_Delete(self->onReceive);
  }
  evs_Delete(self);
}

void test_Util_Evs_SendClearMessage(PEventServer evServer, PConnection conn, char *msg, uint32_t sz, uint32_t code) {
  EventMessage toSendMsg = {
    .headerCode = code,
    .isAuthed = 0,
    .str = (EventBuffer) {
      .buffer = msg,
      .size = sz
    }
  };
  EventBuffer toSend = evm_New_Transform(&toSendMsg);
  test_Wss_SendMessage(evServer->wsServer, conn, toSend.buffer, toSend.size);
  free(toSend.buffer);
}