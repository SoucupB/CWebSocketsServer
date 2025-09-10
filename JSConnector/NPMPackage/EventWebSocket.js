// MIT License



// Copyright (c) 2024 Soucup Bogdan



// Permission is hereby granted, free of charge, to any person obtaining a copy

// of this software and associated documentation files (the "Software"), to deal

// in the Software without restriction, including without limitation the rights

// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell

// copies of the Software, and to permit persons to whom the Software is

// furnished to do so, subject to the following conditions:



// The above copyright notice and this permission notice shall be included in all

// copies or substantial portions of the Software.



// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR

// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,

// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE

// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER

// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,

// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE

// SOFTWARE.


var i=e=>(e.getInt32(4,!0)&16777216)>0,l=e=>e.getInt32(4,!0)&16777215,u=e=>e.getInt32(0,!0),c=(e,t)=>i(t)?e.subarray(8,16):null,f=e=>e.authCode?16:8,w=e=>e.authCode==null?e.code:e.code|16777216,p=e=>e.size+f(e),a=e=>typeof e=="string"?new TextEncoder().encode(e):new Uint8Array(e),_=e=>e.authCode?a(e.authCode):null,y=(e,t)=>{let n=0;return i(t)&&(n=8),e.subarray(8+n,8+n+u(t))};function h(e){if(e.length<8)return null;let t=new DataView(e.buffer,e.byteOffset,e.byteLength);return{size:u(t),code:l(t),authCode:c(e,t),payload:y(e,t)}}var C=e=>e.code!=null&&e.authCode!=null&&e.payload!=null;function d(e){if(!C(e))return null;let t=new Uint8Array(p(e)),n=new DataView(t.buffer),o=0;e.size=e.payload.length,n.setInt32(0,e.size,!0),n.setInt32(4,w(e),!0);let r=null;if(e.authCode&&(r=_(e))){if(!r)return null;t.set(r,8),o+=8}return t.set(a(e.payload),8+o),t}var s=class{constructor(t){this.host=t,this.onOpen=null,this.onReceive=null,this.onClose=null,this.onError=null}_onOpen(t){t.onOpen&&t.onOpen()}_onReceive(t,n){t.onReceive&&t.onReceive(h(new Uint8Array(n)))}_setMethods_Node(){let t=this;this.ws.on("open",()=>this._onOpen(t)),this.ws.on("message",n=>this._onReceive(t,n)),this.ws.on("error",n=>this._onError(n))}_setMethods_Browser(){let t=this;this.ws.binaryType="arraybuffer",this.ws.onopen=()=>this._onOpen(t),this.ws.onmessage=n=>this._onReceive(t,n.data),this.ws.onerror=n=>this._onError(n)}_setMethods(){if(!this._isOnBrowser()){this._setMethods_Node();return}this._setMethods_Browser()}_onError(t){this.onError&&this.onError(t)}send(t){let n=d(t);n&&this.ws.send(n)}_isOnBrowser(){return typeof window<"u"}async connect(){let t;this._isOnBrowser()?t=WebSocket:t=(await import("ws")).default;try{this.ws=new t(this.host),this._setMethods()}catch{return!1}return!0}},v=s;export{s as EventWebSocket,v as default};
