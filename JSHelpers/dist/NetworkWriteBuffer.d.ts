export default class NetworkWriteBuffer {
    buffer: Uint8Array<ArrayBufferLike>;
    littleEndian: boolean;
    view: DataView;
    size: number;
    capacity: number;
    byteViewSize: number;
    constructor(littleEndian?: boolean);
    _resize(): void;
    _push(byte: number): void;
    _pushBytesCount(count: number): void;
    integer_8_bits(byte: number): void;
    integer_16_bits(value: number): void;
    integer_32_bits(value: number): void;
    integer_64_bits(value: number): void;
    float_32_bits(value: number): void;
    float_64_bits(value: number): void;
    string(value: string): void;
    uintArray(): Uint8Array<ArrayBuffer>;
}
