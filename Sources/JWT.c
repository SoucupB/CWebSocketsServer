#include "JWT.h"
#include <openssl/hmac.h>
#include <openssl/evp.h>
#include "TimeFragment.h"
#include "JsonParser.h"
#include <string.h>
#include "Array.h"
#include <unistd.h>
#include "String.h"

#define MAXIMUM_JWT_SIZE 1024 * 1024 * 10

static inline char *jwt_CreateHeader();
void jwt_ToBase64UrlEncoded(HttpString str, uint8_t *response, size_t *finalSize);
static inline size_t jwt_Base64_Size(size_t sz);
static inline void jwt_EncodeElement(JsonElement payload, uint8_t *code, size_t *sz);
void jwt_HMAC(HttpString key, HttpString secret, uint8_t *hmacResult, size_t *currentSize);
void jwt_PrintHMAC(uint8_t *hmacCode, size_t sz);
void jwt_DecodeBase64(HttpString str, uint8_t *response, size_t *responseSz);
void jwt_FromBase64URLEncodedToNormal(HttpString str, uint8_t *response, size_t *sz);
static inline uint8_t jwt_CharValid(char chr);
uint8_t jwt_IsJWTCorrectlyFormatted(HttpString str);

static inline void jwt_Add_String(Array strDrt, HttpString str) {
  for(size_t i = 0, c = str.sz; i < c; i++) {
    arr_Push(strDrt, &str.buffer[i]);
  }
}

static inline void jwt_Add_Char(Array strDrt, char chr) {
  arr_Push(strDrt, &chr);
}

static inline void jwt_Add_Header(Array strDrt) {
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

void jwt_AddSignature(Array str, HttpString secret) {
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
    arr_Push(str, &hmacResult[i]);
  }
}

HttpString jwt_Encode_t(JsonElement payload, HttpString secret, uint64_t iam, uint64_t expirationInMS) {
  Array response = arr_Init(sizeof(char));
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
  arr_DeleteWOBuffer(response);
  free(payloadString.buffer);
  return (HttpString){
    .buffer = bff,
    .sz = sz
  };
}

void jwt_FromBase64URLEncodedToNormal(HttpString str, uint8_t *response, size_t *sz) {
  size_t paddingNeeded = (4 - (str.sz % 4)) % 4;
  size_t z = 0;
  for(size_t i = 0, c = str.sz; i < c; i++) {
    switch (str.buffer[i])
    {
      case '-': {
        response[i] = '+'; 
        break;
      }
      case '_': {
        response[i] = '/'; 
        break;
      }
      
      default: {
        response[i] = str.buffer[i];
        break;
      }
    }
    z++;
  }
  for(size_t p = 0; p < paddingNeeded; p++) {
    response[z++] = '=';
  }
  *sz = z;
}

void jwt_DecodeBase64(HttpString str, uint8_t *response, size_t *responseSz) {
  BIO *bio, *b64;
  b64 = BIO_new(BIO_f_base64());
  BIO_set_flags(b64, BIO_FLAGS_BASE64_NO_NL);
  bio = BIO_new_mem_buf((void*)str.buffer, str.sz);
  bio = BIO_push(b64, bio);
  ssize_t currentResponseSize = BIO_read(bio, response, str.sz);
  BIO_free_all(bio);
  if(currentResponseSize <= 0) {
    *responseSz = 0;
    return ;
  }
  *responseSz = (size_t)currentResponseSize;
}

uint8_t jwt_DecodeURLEncodedBase64(HttpString str, uint8_t *response, size_t *responseSz) {
  uint8_t decoded[str.sz + 5];
  size_t sz;
  jwt_FromBase64URLEncodedToNormal(str, decoded, &sz);
  jwt_DecodeBase64((HttpString) {
    .buffer = (char *)decoded,
    .sz = sz
  }, response, responseSz);
  return *responseSz != 0;
}

size_t jwt_ExtractStringChecker(HttpString str) {
  size_t sz = 0;
  while(sz < str.sz && str.buffer[sz] != '.') {
    sz++;
  }
  return sz;
}

uint8_t jwt_IsHeaderValid(HttpString str) {
  size_t headerSize = jwt_ExtractStringChecker(str);
  size_t headerDecodedSize;
  uint8_t headerResponse[str.sz + 1];
  jwt_DecodeURLEncodedBase64((HttpString) {
    .buffer = (char *)str.buffer,
    .sz = headerSize
  }, headerResponse, &headerDecodedSize);
  if(!headerDecodedSize) {
    return 0;
  }
  JsonElement headerJson = json_Parse((HttpString) {
    .buffer = (char *)headerResponse,
    .sz = headerDecodedSize
  }, NULL);
  if(headerJson.type != JSON_JSON) {
    json_DeleteElement(headerJson);
    return 0;
  }
  JsonElement encryptionType = json_Map_GetString(headerJson, "alg");
  if(encryptionType.type != JSON_STRING) {
    json_DeleteElement(headerJson);
    return 0;
  }
  char *acceptedAlgorithm = "HS256";
  size_t acceptedAlgorithmSize = strlen(acceptedAlgorithm);
  PHttpString algoString = (PHttpString)encryptionType.value;
  if(algoString->sz != acceptedAlgorithmSize) {
    json_DeleteElement(headerJson);
    return 0;
  }
  if(memcmp(acceptedAlgorithm, algoString->buffer, acceptedAlgorithmSize)) {
    json_DeleteElement(headerJson);
    return 0;
  }
  json_DeleteElement(headerJson);
  return 1;
}

uint8_t jwt_Payload_AreTokensValid(JsonElement payload) {
  JsonElement exp = json_Map_GetString(payload, "exp");
  if(exp.type == JSON_INVALID) {
    return 1;
  }
  if(exp.type != JSON_INTEGER) {
    return 0;
  }
  int64_t expDate = json_Integer_Get(exp);
  if(expDate <= tf_CurrentTimeMS()) {
    return 0;
  }
  return 1;
}

static inline uint8_t jwt_CharValid(char chr) {
  return (chr >= '0' && chr <= '9') ||
         (chr >= 'A' && chr <= 'Z') ||
         (chr >= 'a' && chr <= 'z') ||
          chr == '_' || chr == '-';
}

uint8_t jwt_IsJWTCorrectlyFormatted(HttpString str) {
  if(str.sz >= MAXIMUM_JWT_SIZE) {
    return 0;
  }
  int8_t pnt = 0;
  size_t index = 0;
  int8_t checker = 0;
  while(index < str.sz) {
    if(jwt_CharValid(str.buffer[index])) {
      checker = 1;
    } else if(str.buffer[index] == '.') {
      if(!checker) {
        return 0;
      }
      checker = 0;
      pnt++;
    } else {
      return 0;
    }
    index++;
  }
  return pnt == 2 && checker;
}

uint8_t jwt_IsPayloadValid(HttpString str) {
  size_t headerSize = jwt_ExtractStringChecker(str);
  HttpString payloadString = {
    .buffer = headerSize + str.buffer + 1,
    .sz = str.sz - headerSize
  };
  ssize_t cSz = payloadString.sz;
  while(cSz >= 0 && payloadString.buffer[cSz] != '.') {
    cSz--;
  }
  payloadString.sz = cSz;
  size_t payloadDecodedSize;
  uint8_t payloadResponse[payloadString.sz + 1];
  jwt_DecodeURLEncodedBase64(payloadString, payloadResponse, &payloadDecodedSize);
  if(!payloadDecodedSize) {
    return 0;
  }
  JsonElement payloadJson = json_Parse((HttpString) {
    .buffer = (char *)payloadResponse,
    .sz = payloadDecodedSize
  }, NULL);
  if(payloadJson.type != JSON_JSON) {
    json_DeleteElement(payloadJson);
    return 0;
  }
  if(!jwt_Payload_AreTokensValid(payloadJson)) {
    json_DeleteElement(payloadJson);
    return 0;
  }
  json_DeleteElement(payloadJson);
  return 1;
}

uint8_t jwt_IsValid(HttpString str, HttpString secret) {
  if(!jwt_IsJWTCorrectlyFormatted(str)) {
    return 0;
  }
  if(!jwt_IsHeaderValid(str) || !jwt_IsPayloadValid(str)) {
    return 0;
  }
  return jwt_IsSigned(str, secret);
}

static inline void jwt_HeaderPayload(HttpString jwtStr, HttpString *headerPtr, HttpString *payloadPtr) {
  size_t firstPointIndex = 0;
  while(firstPointIndex < jwtStr.sz && jwtStr.buffer[firstPointIndex] != '.') {
    firstPointIndex++;
  }
  size_t secondPointIndex = firstPointIndex + 1;
  while(secondPointIndex < jwtStr.sz && jwtStr.buffer[secondPointIndex] != '.') {
    secondPointIndex++;
  }
  headerPtr->buffer = jwtStr.buffer;
  headerPtr->sz = firstPointIndex;
  payloadPtr->buffer = jwtStr.buffer + firstPointIndex + 1;
  payloadPtr->sz = secondPointIndex - firstPointIndex - 1;
}

PJWT jwt_Parse(HttpString jwtStr, HttpString secret) {
  if(!jwt_IsValid(jwtStr, secret)) {
    return NULL;
  }
  PJWT response = malloc(sizeof(JWT));
  memset(response, 0, sizeof(JWT));
  HttpString header;
  HttpString payload;
  jwt_HeaderPayload(jwtStr, &header, &payload);
  uint8_t headerStr[header.sz];
  size_t headerSize;
  if(!jwt_DecodeURLEncodedBase64(header, headerStr, &headerSize)) {
    jwt_Delete(response);
    return NULL;
  }
  uint8_t payloadStr[payload.sz];
  size_t payloadSize;
  if(!jwt_DecodeURLEncodedBase64(payload, payloadStr, &payloadSize)) {
    jwt_Delete(response);
    return NULL;
  }
  JsonElement headerJson = json_Parse((HttpString) {
    .buffer = (char *)headerStr,
    .sz = headerSize
  }, NULL);
  JsonElement payloadJson = json_Parse((HttpString) {
    .buffer = (char *)payloadStr,
    .sz = payloadSize
  }, NULL);
  response->header = headerJson;
  response->payload = payloadJson;
  if(payloadJson.type != JSON_JSON || headerJson.type != JSON_JSON) {
    jwt_Delete(response);
    return NULL;
  }
  return response;
}

void jwt_Delete(PJWT self) {
  json_DeleteElement(self->header);
  json_DeleteElement(self->payload);
  free(self);
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

void jwt_ToBase64UrlEncoded(HttpString str, uint8_t *response, size_t *finalSize) {
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
  size_t sigSize = str.sz - sz;
  if(pnt != 2 || sigSize <= 30) {
    return 0;
  }
  const size_t csz = jwt_Base64_Size(32);
  uint8_t hmacResult[csz + 2];
  size_t newB64Size;
  jwt_HMAC((HttpString) {
    .buffer = buffer,
    .sz = sz - 1
  }, secret, hmacResult, &newB64Size);
  if(newB64Size != sigSize) {
    return 0;
  }
  return !memcmp(buffer + sz, hmacResult, newB64Size);
}

static inline char *jwt_CreateHeader() {
  return "{\"alg\":\"HS256\",\"typ\":\"JWT\"}";
}