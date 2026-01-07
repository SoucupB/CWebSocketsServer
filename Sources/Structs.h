#pragma once
#include <stdint.h>
#include <stddef.h>

#define PVOID void*
#define crm_Alloc malloc
#define crm_Free free
#define crm_Realloc realloc

struct WebSocketServer_t;
typedef struct WebSocketServer_t WebSocketServer;
typedef WebSocketServer *PWebSocketServer;

typedef enum {
  OPCODE_CONTINUATION_FRAME = 0x0,
  OPCODE_TEXT_FRAME = 0x1,
  OPCODE_BINARY = 0x2,
  OPCODE_CONNECTION_CLOSE = 0x8,
  OPCODE_PING = 0x9,
  OPCODE_PONG = 0xA
} Opcode;

typedef struct Auth_t {
  uint8_t bff[8];
} Auth;

typedef Auth *PAuth;

typedef struct EventBuffer_t {
  char *buffer;
  uint32_t size;
} EventBuffer;

typedef EventBuffer *PEventBuffer;

typedef struct EventMessage_t {
  uint8_t isAuthed;
  uint32_t headerCode; // request code 3 bytes
  Auth uniqueCode;
  EventBuffer str;
} EventMessage;

typedef struct WebSocketObject_t {
  char *buffer;
  size_t sz;
  uint8_t opcode;
  char *_fullMessage;
} WebSocketObject;

typedef WebSocketObject *PWebSocketObject;

// <payload_size> <header> <auth_code> (if necessary) <payload>

typedef EventMessage *PEventMessage;

typedef struct SocketMethod_t {
  void *method;
  void *mirrorBuffer; /*This buffer should be on heap or static memory but not on the stack*/
} SocketMethod;

typedef struct Connection_t {
  int32_t fd;
} Connection;

typedef struct DataFragment_t {
  uint32_t size;
  uint8_t persistent;
  Connection conn;
  char *data;
} DataFragment;

typedef SocketMethod *PSocketMethod;
typedef Connection *PConnection;
typedef DataFragment *PDataFragment;

typedef struct EventServer_t {
  PWebSocketServer wsServer;
  PSocketMethod onReceive; // void (*method)(PResponseObject, void *)
  PSocketMethod onClose; // void (*method)(PConnection, void *)
} EventServer;

typedef struct ResponseObject_t {
  EventMessage metaData;
  PConnection conn;
} ResponseObject;

typedef ResponseObject *PResponseObject;
typedef EventServer *PEventServer;

typedef struct PrivateMethodsBundle_t {
  PSocketMethod _onConnect;
  PSocketMethod _onReceive;
  PSocketMethod _onRelease;
} PrivateMethodsBundle;

typedef struct TimeMethod_t {
  void *method;
  void *buffer;
} TimeMethod;

typedef struct TimeFragment_t {
  TimeMethod methodFragment;
  int64_t executeAfter;
  int64_t time;
} TimeFragment;

struct Array_t {
  void *buffer;
  size_t size;
  size_t capacity;
  size_t objSize;
};

typedef struct Array_t *Array;

typedef struct TimeServer_t {
  Array methods;
  Array loopMethods;
} TimeServer;

typedef TimeServer *PTimeServer;

typedef struct Timeout_t {
  uint64_t timeout;
  PTimeServer server;
} Timeout;

typedef Timeout *PTimeout;

typedef struct Timers_t {
  PTimeServer timeServer;
  int64_t timeout;
} Timers;

typedef struct SocketServer_t {
  uint16_t port;
  int32_t maxActiveConnections;
  int32_t maxBytesPerReadConnection;
  Connection serverFD;
  Array connections;
  Array inputReads;
  Array outputCommands;
  Array closeConnectionsQueue;
  PSocketMethod onConnectionRelease; // void (*method)(Connection, void *)
  PSocketMethod onConnectionAquire; // void (*method)(Connection, void *)
  PSocketMethod onReceiveMessage; // void (*method)(PDataFragment, void *)
  Timers timeServer;
} SocketServer;

typedef SocketServer *PSocketServer;

typedef struct WebSocketServer_t {
  PSocketServer socketServer;
  PSocketMethod onConnect; // void (*method)(PConnection, void *)
  PSocketMethod onReceiveMessage; // void (*method)(PDataFragment, void *)
  PSocketMethod onRelease; // void (*method)(PConnection, void *)
  PrivateMethodsBundle methodsBundle;
  Array pendingConnections;
  Array pendingPingRequests;
  Array activeConnections;
  PTimeout timeServer;
  size_t maxBSize;
  size_t maxBSizeForHttpReq;
} WebSocketServer;

typedef WebSocketServer *PWebSocketServer;

typedef enum {
  GET,
  POST,
  PUT,
  PATCH,
  DELETE
} HttpAction;

typedef struct HttpString_t {
  char *buffer;
  size_t sz;
} HttpString;

typedef HttpString *PHttpString;

typedef struct URL_t {
  HttpString path;
  char httpType[16];
  HttpAction method;
} URL;

typedef URL *PURL;

typedef struct HttpMetaData_t {
  HttpString codes[10];
  size_t actionsSz;
} HttpMetaData;

typedef HttpMetaData *PHttpMetaData;

typedef struct TrieNode_t *PTrieNode;

typedef struct Hsh_t {
  uint32_t count;
  PTrieNode parentNode;
} Hsh;

typedef Hsh *PHsh;

typedef struct TrieNode_t {
  uint32_t count;
  void *buffer;
  PTrieNode *nextNodes;
} TrieNode;

typedef struct Key_t {
  char *key;
  uint32_t keySize;
} Key;

typedef struct Hash_t {
  PHsh hash;
  PHsh valuesSize;
} Hash;

typedef struct HttpRequest_t {
  Hash headers;
  PURL url;
  HttpString body;
  char *_endBuffer;
  PHttpMetaData metadata;
} HttpRequest;

typedef HttpRequest *PHttpRequest;

typedef struct HttpResponse_t {
  char *httpCode;
  Hash headers;
  HttpString body;
  uint16_t response;
} HttpResponse;

typedef HttpResponse *PHttpResponse;

typedef enum {
  JSON_INVALID,
  JSON_NULL,
  JSON_INTEGER,
  JSON_NUMBER,
  JSON_STRING,
  JSON_BOOLEAN,
  JSON_JSON,
  JSON_ARRAY
} JsonType;

typedef enum {
  RESPONSE_TIMEOUT,
  RESPONSE_PARSE_ERROR
} RequestError;

typedef struct JsonElement_t {
  void *value;
  JsonType type;
} JsonElement;

typedef JsonElement *PJsonElement;

typedef struct JsonObject_t {
  PHsh hsh;
  uint8_t selfContained;
} JsonObject;

typedef JsonObject *PJsonObject;

typedef struct HttpServer_t {
  PSocketServer server;
  PSocketMethod onReceive; // PHttpResponse (*caller)(PHttpRequest, void *)
  Array connections;
  size_t maximumRequestSize;
} HttpServer;

typedef HttpServer *PHttpServer;

typedef struct HttpRequestServer_t {
  Array requests;
  int64_t timeoutMS;
  size_t maxSizeInB;
} HttpRequestServer;

typedef HttpRequestServer *PHttpRequestServer;

typedef struct RequestStruct_t {
  uint16_t port;
  char ip[17];
  HttpString query;
  PSocketMethod onSuccess; // void (*onSuccess)(PHttpResponse req, void *mirror)
  PSocketMethod onFailure; // void (*onFailure)(RequestError error, void *mirror)
} RequestStruct;

typedef struct JWT_t {
  JsonElement header;
  JsonElement payload;
} JWT;

typedef JWT *PJWT;

typedef struct NetworkBuffer_t {
  void *buffer;
  void *currentBuffer;
  size_t size;
  size_t capacity;
  size_t maxRetriedSize;
  size_t maxSizeB;
} NetworkBuffer;

typedef NetworkBuffer *PNetworkBuffer;