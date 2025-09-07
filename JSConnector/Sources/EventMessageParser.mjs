
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

const payload = (buffer, view) => {
  let offset = 0;
  if(!isAuthed(view)) {
    offset = 8;
  }
  return buffer.subarray(8 + offset, payloadSize(view));
}

export default function eventParseMethod(buffer) {
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