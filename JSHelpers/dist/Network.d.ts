export default class Network {
    url: string;
    jwt: string | null;
    onReceive: any;
    onDisconnect: any;
    opened: boolean;
    loggedIN: boolean;
    ws: WebSocket | null;
    constructor(url: string);
    connect(): void;
    _ftypeOf(value: any): "other" | "object" | "string" | "array";
    _getBytes_String(payload: any): Uint8Array<ArrayBuffer>;
    _getBytes_Array(payload: any): Uint8Array<any>;
    _getBytes_Object(payload: any): Uint8Array<ArrayBuffer>;
    _getBytes(payload: any): Uint8Array<any> | null;
    send(data: any): void;
    extractData(response: any): boolean;
    setMethods(): void;
    addJWTAuth(jwt: string): void;
    login(): void;
}
