
const isAuthed = (view) => {
  return (view.getInt32(4, true) & (1<<24)) > 0;
}

const headerCode = (view) => {
  return (view.getInt32(4, true) & (1<<24) - 1);
}

const payloadSize = (view) => {
  return view.getInt32(0, true);
}

const authCode = (buffer, view) => {
  if(!isAuthed(view)) {
    return null;
  }
  return buffer.subarray(8, 16);
}

const headerSize = (obj) => {
  if(!obj.authCode) {
    return 8;
  }
  return 16;
}

const headerFromObj = (obj) => {
  return obj.authCode == null ? obj.code : (obj.code | (1<<24));
}

const bufferSize = (obj) => {
  return obj.size + headerSize(obj);
}

const authCodeFromObj = (obj) => {
  if(!obj.authCode) {
    return null;
  }
  return new Uint8Array(obj.authCode);
}

const payload = (buffer, view) => {
  let offset = 0;
  if(!isAuthed(view)) {
    offset = 8;
  }
  return buffer.subarray(8 + offset, 8 + offset + payloadSize(view));
}

export function eventParseMethod(buffer) {
  if(buffer.length < 8) {
    return null;
  }
  const view = new DataView(buffer.buffer, buffer.byteOffset, buffer.byteLength);
  return {
    size: payloadSize(view),
    code: headerCode(view),
    authCode: authCode(buffer, view),
    payload: payload(buffer, view)
  }
}

export function eventCreateMessage(obj) {
  let arr = new Uint8Array(bufferSize(obj));
  let view = new DataView(arr.buffer);
  let offset = 0;
  view.setInt32(0, obj.size, true);
  view.setInt32(4, headerFromObj(obj), true);
  if(obj.authCode) {
    arr.set(8, authCodeFromObj(obj));
    offset += 8;
  }
  arr.set(8 + offset, new Uint8Array(obj.payload));
  return arr;
}