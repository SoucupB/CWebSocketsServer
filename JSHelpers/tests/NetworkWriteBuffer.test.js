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