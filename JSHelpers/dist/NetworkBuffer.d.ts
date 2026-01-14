export declare class NetworkReadBuffer {
    input: Uint8Array<ArrayBufferLike>;
    bigEndian: boolean;
    currentCount: number;
    view: DataView;
    constructor(input: Uint8Array, bigEndian?: boolean);
    reset(): void;
    integer_8_bits(): number;
    integer_16_bits(): number;
    integer_32_bits(): number;
    float_32_bits(): number;
    float_64_bits(): number;
}
