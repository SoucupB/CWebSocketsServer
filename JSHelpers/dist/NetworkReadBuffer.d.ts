export default class NetworkReadBuffer {
    input: Uint8Array<ArrayBufferLike>;
    littleEndian: boolean;
    currentCount: number;
    view: DataView;
    constructor(input: Uint8Array, littleEndian?: boolean);
    reset(): void;
    valid(): boolean;
    integer_8_bits(): number;
    integer_16_bits(): number;
    integer_32_bits(): number;
    float_32_bits(): number;
    float_64_bits(): number;
    _integer_64_bits_little_endian(first: number, second: number): number;
    _integer_64_bits_big_endian(first: number, second: number): number;
    integer_64_bits(): number;
}
