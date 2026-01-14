import NetworkReadBuffer from './../dist/NetworkReadBuffer'

test('little endian 64 bits integer', () => {
  const bytes = new Uint8Array([1, 2, 3, 4, 5, 6, 0, 0]);
  let bff = new NetworkReadBuffer(bytes);
  expect(bff.integer_64_bits()).toBe(6618611909121);
});

test('big endian 64 bits integer', () => {
  const bytes = new Uint8Array([1, 2, 3, 4, 5, 6, 0, 0]);
  let bff = new NetworkReadBuffer(bytes, false);
  expect(bff.integer_64_bits()).toBe(72623859790381056);
});

test('little endian 16 bits integer', () => {
  const bytes = new Uint8Array([1, 2, 3, 4, 5, 6, 0, 0]);
  let bff = new NetworkReadBuffer(bytes);
  expect(bff.integer_16_bits()).toBe(513);
});

test('big endian 16 bits integer', () => {
  const bytes = new Uint8Array([1, 2, 3, 4, 5, 6, 0, 0]);
  let bff = new NetworkReadBuffer(bytes, false);
  expect(bff.integer_16_bits()).toBe(258);
});

test('little endian 32 bits integer', () => {
  const bytes = new Uint8Array([1, 2, 3, 4, 5, 6, 0, 0]);
  let bff = new NetworkReadBuffer(bytes);
  expect(bff.integer_32_bits()).toBe(67305985);
});

test('big endian 32 bits integer', () => {
  const bytes = new Uint8Array([1, 2, 3, 4, 5, 6, 0, 0]);
  let bff = new NetworkReadBuffer(bytes, false);
  expect(bff.integer_32_bits()).toBe(16909060);
});