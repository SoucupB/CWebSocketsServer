#include "JWT.h"
#include <openssl/hmac.h>
#include <openssl/evp.h>
#include "TimeFragment.h"
#include "JsonParser.h"
#include <string.h>
#include "Vector.h"

static inline char *jwt_CreateHeader();
static inline void jwt_ToBase64UrlEncoded(HttpString str, uint8_t *response, size_t *finalSize);
static inline size_t jwt_Base64_Size(size_t sz);
static inline void jwt_EncodeElement(JsonElement payload, uint8_t *code, size_t *sz);
void jwt_HMAC(HttpString key, HttpString secret, uint8_t *hmacResult, size_t *currentSize);
void jwt_PrintHMAC(uint8_t *hmacCode, size_t sz);

static inline void jwt_Add_String(Vector strDrt, HttpString str) {
  for(size_t i = 0, c = str.sz; i < c; i++) {
    vct_Push(strDrt, &str.buffer[i]);
  }
}

static inline void jwt_Add_Char(Vector strDrt, char chr) {
  vct_Push(strDrt, &chr);
}

static inline void jwt_Add_Header(Vector strDrt) {
  char *header = jwt_CreateHeader();
  size_t sz = strlen(header);
  size_t headerBase64Size = jwt_Base64_Size(sz);
  size_t newB64Size;
  uint8_t headerBase64[headerBase64Size + 2];
  jwt_ToBase64UrlEncoded((HttpString) {
    .buffer = header,
    .sz = sz
  }, headerBase64, &newB64Size);
  jwt_Add_String(strDrt, (HttpString) {
    .buffer = (char *)headerBase64,
    .sz = newB64Size
  });
}

void jwt_AddSignature(Vector str, HttpString secret) {
  HttpString newStr = {
    .buffer = str->buffer,
    .sz = str->size
  };
  const size_t csz = jwt_Base64_Size(32);
  uint8_t hmacResult[csz + 2];
  size_t newB64Size;
  jwt_HMAC(newStr, secret, hmacResult, &newB64Size);
  jwt_Add_Char(str, '.');
  for(size_t i = 0; i < newB64Size; i++) {
    vct_Push(str, &hmacResult[i]);
  }
}

HttpString jwt_Encode_t(JsonElement payload, HttpString secret, uint64_t iam, uint64_t expirationInMS) {
  Vector response = vct_Init(sizeof(char));
  jwt_Add_Header(response);
  jwt_Add_Char(response, '.');
  json_Map_Add(payload, "iat", json_Integer_Create((int64_t)iam));
  json_Map_Add(payload, "exp", json_Integer_Create((int64_t)expirationInMS + iam));
  HttpString payloadString = json_Element_ToString(payload);
  size_t payloadBase64Size = jwt_Base64_Size(payloadString.sz);
  uint8_t payloadBase64[payloadBase64Size + 1];
  size_t cB64Sz;
  jwt_EncodeElement(payload, payloadBase64, &cB64Sz);
  jwt_Add_String(response, (HttpString) {
    .buffer = (char *)payloadBase64,
    .sz = cB64Sz
  });
  jwt_AddSignature(response, secret);
  char *bff = response->buffer;
  size_t sz = response->size;
  vct_DeleteWOBuffer(response);
  return (HttpString){
    .buffer = bff,
    .sz = sz
  };
}

HttpString jwt_Encode(JsonElement payload, HttpString secret, uint64_t expirationInMS) {
  return jwt_Encode_t(payload, secret, tf_CurrentTimeMS(), expirationInMS);
}

static inline void jwt_EncodeElement(JsonElement payload, uint8_t *code, size_t *sz) {
  HttpString payloadString = json_Element_ToString(payload);
  jwt_ToBase64UrlEncoded(payloadString, code, sz);
  free(payloadString.buffer);
}

void jwt_HMAC(HttpString key, HttpString secret, uint8_t *hmacResult, size_t *currentSize) {
  unsigned int hmac_length = 0;
  uint8_t hmalRes[50];
  HMAC(
    EVP_sha256(),
    (uint8_t *)secret.buffer, secret.sz,
    (uint8_t *)key.buffer, key.sz,
    hmalRes, &hmac_length
  );
  jwt_ToBase64UrlEncoded((HttpString) {
    .buffer = (char *)hmalRes,
    .sz = 32
  }, hmacResult, currentSize);
}

void jwt_PrintHMAC(uint8_t *hmacCode, size_t sz) {
  printf("HMAC-SHA256: ");
  for (unsigned int i = 0; i < sz; i++)
    printf("%c", hmacCode[i]);
  printf("\n");
}

static inline size_t jwt_Base64_Size(size_t sz) {
  return 4 * ((sz + 2) / 3);
}

size_t jwt_Base64_Size_Public(size_t sz) {
  return jwt_Base64_Size(sz);
}

static inline void jwt_ToBase64UrlEncoded(HttpString str, uint8_t *response, size_t *finalSize) {
  const size_t cSize = jwt_Base64_Size(str.sz);
  EVP_EncodeBlock(response, (uint8_t *)str.buffer, str.sz);
  for(size_t i = 0; i < cSize; i++) {
    if (response[i] == '+') { 
      response[i] = '-';
    }
    else if (response[i] == '/') { 
      response[i] = '_';
    }
  }
  if(!finalSize) {
    return ;
  }
  *finalSize = cSize;
  while(*finalSize > 0 && response[(*finalSize) - 1] == '=') {
    (*finalSize)--;
  }
}

uint8_t jwt_IsSigned(HttpString str, HttpString secret) {
  char *buffer = str.buffer;
  size_t sz = 0;
  int8_t pnt = 0;
  while(sz < str.sz && pnt < 2) {
    if(buffer[sz] == '.') {
      pnt++;
    }
    sz++;
  }
  const size_t csz = jwt_Base64_Size(32);
  uint8_t hmacResult[csz + 2];
  size_t newB64Size;
  jwt_HMAC((HttpString) {
    .buffer = buffer,
    .sz = sz - 1
  }, secret, hmacResult, &newB64Size);
  if(newB64Size != (str.sz - sz)) {
    return 0;
  }
  return !memcmp(buffer + sz, hmacResult, newB64Size);
}

static inline char *jwt_CreateHeader() {
  return "{\"alg\":\"HS256\",\"typ\":\"JWT\"}";
}