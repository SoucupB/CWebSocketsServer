export default class NetworkWriteBuffer {
  buffer: Uint8Array<ArrayBufferLike>;
  littleEndian: boolean;
  view: DataView;
  size: number;
  capacity: number;
  byteViewSize: number;

  constructor(littleEndian: boolean = true) {
    this.littleEndian = littleEndian;
    this.size = 0;
    this.byteViewSize = 0;
    this.capacity = 16;

    this.buffer = new Uint8Array(this.capacity);
    this.view = new DataView(this.buffer.buffer);
  }

  _resize(): void {
    this.capacity *= 2;
    let newBuffer = new Uint8Array(this.capacity);
    for(let i = 0, c = this.size; i < c; i++) {
      newBuffer[i] = this.buffer[i];
    }
    this.buffer = newBuffer;
    this.view = new DataView(newBuffer.buffer);
  }

  _push(byte: number): void {
    if(this.size >= this.capacity) {
      this._resize();
    }
    this.buffer[this.size++] = byte;
  }

  _pushBytesCount(count: number): void {
    for(let i = 0; i < count; i++) {
      this._push(0x0);
    }
  }

  integer_8_bits(byte: number): void {
    this._push(byte);
    this.byteViewSize++;
  }

  integer_16_bits(value: number): void {
    let offset = 0x2;
    this._pushBytesCount(offset);
    this.view.setUint16(this.byteViewSize, value, this.littleEndian)
    this.byteViewSize += offset;
  }

  integer_32_bits(value: number): void {
    let offset = 0x4;
    this._pushBytesCount(offset);
    this.view.setUint32(this.byteViewSize, value, this.littleEndian);
    this.byteViewSize += offset;
  }

  integer_64_bits(value: number): void {
    let offset = 0x8;
    this._pushBytesCount(offset);
    this.view.setBigUint64(this.byteViewSize, BigInt(value), this.littleEndian);
    this.byteViewSize += offset;
  }

  float_32_bits(value: number): void {
    let offset = 0x4;
    this._pushBytesCount(offset);
    this.view.setFloat32(this.byteViewSize, value, this.littleEndian)
    this.byteViewSize += offset;
  }

  float_64_bits(value: number): void {
    let offset = 0x8;
    this._pushBytesCount(offset);
    this.view.setFloat64(this.byteViewSize, value, this.littleEndian)
    this.byteViewSize += offset;
  }

  string(value: string): void {
    const encoder = new TextEncoder();
    const stringBuffer = encoder.encode(value);
    this.integer_64_bits(stringBuffer.length);
    for(let i = 0, c = stringBuffer.length; i < c; i++) {
      this.integer_8_bits(stringBuffer[i])
    }
  }

  uintArray() {
    return this.buffer.slice(0, this.size);
  }
}