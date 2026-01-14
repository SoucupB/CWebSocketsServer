export class NetworkReadBuffer {
    constructor(input, bigEndian = false) {
        this.input = input;
        this.bigEndian = bigEndian;
        this.currentCount = 0;
        this.view = new DataView(this.input.buffer);
    }
    reset() {
        this.currentCount = 0;
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
        const value = this.view.getInt16(this.currentCount, true);
        this.currentCount += 2;
        return value;
    }
    integer_32_bits() {
        if (this.currentCount + 4 > this.input.length) {
            return 0;
        }
        const value = this.view.getInt32(this.currentCount, true);
        this.currentCount += 4;
        return value;
    }
    float_32_bits() {
        if (this.currentCount + 4 > this.input.length) {
            return 0.0;
        }
        const value = this.view.getFloat32(this.currentCount, true);
        this.currentCount += 4;
        return value;
    }
    float_64_bits() {
        if (this.currentCount + 8 > this.input.length) {
            return 0.0;
        }
        const value = this.view.getFloat64(this.currentCount, true);
        this.currentCount += 8;
        return value;
    }
}
