import NetworkReadBuffer from './../dist/NetworkReadBuffer'

test('adds 1 + 2 = 3', () => {
  const bytes = new Uint8Array([1, 2, 3, 4, 5, 6, 0, 0]);
  let bff = new NetworkReadBuffer(bytes);
  const number = bff.integer_64_bits();
  console.log(number);

  expect(1 + 2).toBe(3);
});