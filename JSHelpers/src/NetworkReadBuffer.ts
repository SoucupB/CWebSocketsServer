export default class NetworkReadBuffer {
  input: Uint8Array<ArrayBufferLike>;
  littleEndian: boolean;
  currentCount: number;
  view: DataView;

  constructor(input: Uint8Array, littleEndian: boolean = true) {
    this.input = input;
    this.littleEndian = littleEndian;
    this.currentCount = 0;
    this.view = new DataView(this.input.buffer);
  }

  reset(): void {
    this.currentCount = 0;
  }

  valid(): boolean {
    return this.currentCount == this.input.length;
  }

  integer_8_bits(): number {
    if(this.currentCount + 1 > this.input.length) {
      return 0;
    }
    const value: number = this.input[this.currentCount++];
    return value;
  }

  integer_16_bits(): number {
    if(this.currentCount + 2 > this.input.length) {
      return 0;
    }
    const value: number = this.view.getInt16(this.currentCount, this.littleEndian);
    this.currentCount += 2;
    return value;
  }

  integer_32_bits(): number {
    if(this.currentCount + 4 > this.input.length) {
      return 0;
    }
    const value: number = this.view.getInt32(this.currentCount, this.littleEndian);
    this.currentCount += 4;
    return value;
  }

  float_32_bits(): number {
    if(this.currentCount + 4 > this.input.length) {
      return 0.0;
    }
    const value: number = this.view.getFloat32(this.currentCount, this.littleEndian);
    this.currentCount += 4;
    return value;
  }

  float_64_bits(): number {
    if(this.currentCount + 8 > this.input.length) {
      return 0.0;
    }
    const value: number = this.view.getFloat64(this.currentCount, this.littleEndian);
    this.currentCount += 8;
    return value;
  }

  _integer_64_bits_little_endian(first: number, second: number): number {
    return first + (second * 2 ** 32);
  }

  _integer_64_bits_big_endian(first: number, second: number): number {
    return second + (first * 2 ** 32);
  }

  integer_64_bits(): number {
    if(this.currentCount + 4 > this.input.length) {
      return 0;
    }
    const first: number = this.integer_32_bits();
    const second: number = this.integer_32_bits();
    if(this.littleEndian) {
      return this._integer_64_bits_little_endian(first, second);
    }
    return this._integer_64_bits_big_endian(first, second);
  }
}