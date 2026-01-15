export default class NetworkReadBuffer {
    constructor(input, littleEndian = true) {
        this.input = input;
        this.littleEndian = littleEndian;
        this.currentCount = 0;
        this.view = new DataView(this.input.buffer);
    }
    reset() {
        this.currentCount = 0;
    }
    valid() {
        return this.currentCount == this.input.length;
    }
    integer_8_bits() {
        if (this.currentCount + 1 > this.input.length) {
            return 0;
        }
        const value = this.input[this.currentCount++];
        return value;
    }
    integer_16_bits() {
        if (this.currentCount + 2 > this.input.length) {
            return 0;
        }
        const value = this.view.getInt16(this.currentCount, this.littleEndian);
        this.currentCount += 2;
        return value;
    }
    integer_32_bits() {
        if (this.currentCount + 4 > this.input.length) {
            return 0;
        }
        const value = this.view.getInt32(this.currentCount, this.littleEndian);
        this.currentCount += 4;
        return value;
    }
    float_32_bits() {
        if (this.currentCount + 4 > this.input.length) {
            return 0.0;
        }
        const value = this.view.getFloat32(this.currentCount, this.littleEndian);
        this.currentCount += 4;
        return value;
    }
    float_64_bits() {
        if (this.currentCount + 8 > this.input.length) {
            return 0.0;
        }
        const value = this.view.getFloat64(this.currentCount, this.littleEndian);
        this.currentCount += 8;
        return value;
    }
    _integer_64_bits_little_endian(first, second) {
        return first + (second * 2 ** 32);
    }
    _integer_64_bits_big_endian(first, second) {
        return second + (first * 2 ** 32);
    }
    integer_64_bits() {
        if (this.currentCount + 4 > this.input.length) {
            return 0;
        }
        const first = this.integer_32_bits();
        const second = this.integer_32_bits();
        if (this.littleEndian) {
            return this._integer_64_bits_little_endian(first, second);
        }
        return this._integer_64_bits_big_endian(first, second);
    }
    string() {
        const strSize = this.integer_64_bits();
        if (strSize + this.currentCount > this.input.length) {
            return "";
        }
        const decoder = new TextDecoder("utf-8");
        const stringResponse = decoder.decode(this.input.subarray(this.currentCount, this.currentCount + strSize));
        this.currentCount += strSize;
        return stringResponse;
    }
}
