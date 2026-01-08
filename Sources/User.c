#include "User.h"
#include <string.h>
#include "Array.h"

PUser usr_Create(PUserData parent) {
  PUser self = crm_Alloc(sizeof(User));
  memset(self, 0, sizeof(User));
  return self;
}

PUserData usrs_Create() {
  PUserData self = crm_Alloc(sizeof(UserData));
  memset(self, 0, sizeof(UserData));
  self->users = arr_Init(sizeof(User));
  return self;
}

static void usrs_DeleteAllUsers(const PUserData self) {
  PUser *users = self->users->buffer;
  for(size_t i = 0, c = self->users->size; i < c; i++) {
    crm_Free(users[i]);
  }
  arr_Delete(self->users);
}

void usrs_AddUser(PUserData self, uint64_t ID) {
  PUser usr = crm_Alloc(sizeof(User));
  usr->active = 0;
  usr->conn = NULL;
  usr->ID = ID;
  arr_Push(self->users, &usr);
}

void usrs_Delete(PUserData self) {
  usrs_DeleteAllUsers(self);
  crm_Free(self);
}

static inline PUser usrs_PlyByID(PUserData self, uint64_t ID) {
  PUser *users = self->users->buffer;
  for(size_t i = 0, c = self->users->size; i < c; i++) {
    if(users[i]->ID == ID) {
      return users[i];
    }
  }
  return NULL;
}

size_t usrs_ConnID(PUserData self, PConnection conn, uint8_t *ok) {
  PUser *users = self->users->buffer;
  *ok = 0;
  for(size_t i = 0, c = self->users->size; i < c; i++) {
    if(users[i]->conn && users[i]->conn->fd == conn->fd) {
      *ok = 1;
      return i;
    }
  }
  return 0;
}

PUser usrs_ByIndex(PUserData self, uint64_t index) {
  PUser *users = self->users->buffer;
  if(index >= self->users->size) {
    return NULL;
  }
  return users[index];
}

PUser usrs_Activate(PUserData self, uint64_t ID, PConnection conn) {
  PUser currentUser = usrs_PlyByID(self, ID);
  if(!currentUser) {
    return 0;
  }
  currentUser->active = 1;
  currentUser->conn = conn;
  return currentUser;
}

PUser usrs_Get(PUserData self, uint64_t ID) {
  return usrs_PlyByID(self, ID);
}

void usrs_Deactivate(PUserData self, PConnection conn) {
  User *users = self->users->buffer;
  for(size_t i = 0, c = self->users->size; i < c; i++) {
    if(users[i].conn->fd == conn->fd) {
      users[i].conn = NULL;
      users[i].active = 0;
      return ;
    }
  }
}

void usr_Deactivate(PUser self) {
  self->conn = NULL;
  self->active = 0;
}

PUser usrs_ByConnection(PUserData self, PConnection conn) {
  PUser *users = self->users->buffer;
  for(size_t i = 0, c = self->users->size; i < c; i++) {
    if(users[i]->conn->fd == conn->fd) {
      return users[i];
    }
  }
  return NULL;
}