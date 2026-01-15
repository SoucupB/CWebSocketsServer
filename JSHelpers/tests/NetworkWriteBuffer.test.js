import NetworkWriteBuffer from './../dist/NetworkWriteBuffer'
import NetworkReadBuffer from './../dist/NetworkReadBuffer'

const memTest = (template, response) => {
  expect(Array.from(template)).toEqual(Array.from(response))
}

test('little endian 8 bits integer', () => {
  let bff = new NetworkWriteBuffer();
  let expected = [5];
  bff.integer_8_bits(5);
  memTest(expected, bff.uintArray());
});

test('little endian 16 bits integer', () => {
  let bff = new NetworkWriteBuffer();
  let expected = [5, 0];
  bff.integer_16_bits(5);
  memTest(expected, bff.uintArray());
});

test('big endian 16 bits integer', () => {
  let bff = new NetworkWriteBuffer(false);
  let expected = [0, 5];
  bff.integer_16_bits(5);
  memTest(expected, bff.uintArray());
});

test('little endian 16 bits integer with bigger number', () => {
  let bff = new NetworkWriteBuffer();
  let expected = [191, 94];
  bff.integer_16_bits(24255);
  memTest(expected, bff.uintArray());
});

test('big endian 16 bits integer with bigger number', () => {
  let bff = new NetworkWriteBuffer(false);
  let expected = [94, 191];
  bff.integer_16_bits(24255);
  memTest(expected, bff.uintArray());
});

test('little endian 32 bits integer with bigger number', () => {
  let bff = new NetworkWriteBuffer();
  let expected = [217, 31, 33, 49];
  bff.integer_32_bits(824254425);
  memTest(expected, bff.uintArray());
});

test('big endian 32 bits integer with bigger number', () => {
  let bff = new NetworkWriteBuffer(false);
  let expected = [49, 33, 31, 217];
  bff.integer_32_bits(824254425);
  memTest(expected, bff.uintArray());
});

test('little endian 64 bits integer with bigger number', () => {
  let bff = new NetworkWriteBuffer();
  let expected = [217, 43, 218, 79, 10, 3, 0, 0];
  bff.integer_64_bits(3342824254425);
  memTest(expected, bff.uintArray());
});

test('big endian 64 bits integer with bigger number', () => {
  let bff = new NetworkWriteBuffer(false);
  let expected = [0, 0, 3, 10, 79, 218, 43, 217];
  bff.integer_64_bits(3342824254425);
  memTest(expected, bff.uintArray());
});

test('little endian 32 bits float', () => {
  let bff = new NetworkWriteBuffer();
  let expected = [129, 4, 162, 67];
  bff.float_32_bits(324.0352);
  memTest(expected, bff.uintArray());
});

test('little endian 64 bits float', () => {
  let bff = new NetworkWriteBuffer();
  let expected = [27, 13, 224, 45, 144, 64, 116, 64];
  bff.float_64_bits(324.0352);
  memTest(expected, bff.uintArray());
});

test('big endian 32 bits float', () => {
  let bff = new NetworkWriteBuffer(false);
  let expected = [67, 162, 4, 129];
  bff.float_32_bits(324.0352);
  memTest(expected, bff.uintArray());
});

test('big endian 64 bits float', () => {
  let bff = new NetworkWriteBuffer(false);
  let expected = [64, 116, 64, 144, 45, 224, 13, 27];
  bff.float_64_bits(324.0352);
  memTest(expected, bff.uintArray());
});

test('little endian string', () => {
  let bff = new NetworkWriteBuffer();
  let expected = [2, 0, 0, 0, 0, 0, 0, 0, 97, 98];
  bff.string("ab");
  memTest(expected, bff.uintArray());
});

test('big endian string', () => {
  let bff = new NetworkWriteBuffer(false);
  let expected = [0, 0, 0, 0, 0, 0, 0, 2, 97, 98];
  bff.string("ab");
  memTest(expected, bff.uintArray());
});

test('little endian special chars string', () => {
  let bff = new NetworkWriteBuffer();
  let expected = [6, 0, 0, 0, 0, 0, 0, 0, 97, 98, 240, 159, 140, 141];
  bff.string("ab🌍");
  memTest(expected, bff.uintArray());
});

test('little endian big array size', () => {
  let bff = new NetworkWriteBuffer();
  let count = 70211;
  bff.integer_32_bits(count);
  for(let i = 0; i < count; i++) {
    bff.integer_32_bits(i * 3);
  }
  bff.string("The string code is finised🌍!!!!");
  let bfr = new NetworkReadBuffer(bff.uintArray());
  let readCount = bfr.integer_32_bits();
  expect(readCount).toBe(count);
  for(let i = 0; i < readCount; i++) {
    expect(bfr.integer_32_bits()).toBe(i * 3);
  }
  expect(bfr.string()).toEqual("The string code is finised🌍!!!!");
  expect(bfr.valid()).toBe(true);
});

test('little endian big array size', () => {
  let bff = new NetworkWriteBuffer(false);
  let count = 27211;
  bff.integer_32_bits(count);
  for(let i = 0; i < count; i++) {
    bff.integer_32_bits(i * 3);
  }
  bff.string("The string code is finised!!!!");
  let bfr = new NetworkReadBuffer(bff.uintArray(), false);
  let readCount = bfr.integer_32_bits();
  expect(readCount).toBe(count);
  for(let i = 0; i < readCount; i++) {
    expect(bfr.integer_32_bits()).toBe(i * 3);
  }
  expect(bfr.string()).toEqual("The string code is finised!!!!");
  expect(bfr.valid()).toBe(true);
});


