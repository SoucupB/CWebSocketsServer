from http.server import BaseHTTPRequestHandler, HTTPServer
from urllib.parse import urlparse, parse_qs
import json

class RequestHandler(BaseHTTPRequestHandler):
  def do_GET(self):
    parsed_url = urlparse(self.path)
    params = parse_qs(parsed_url.query)

    response = {
      "method": "GET",
      "path": parsed_url.path,
      "params": params
    }

    self.send_response(200)
    self.send_header("Content-Length", str(len(json.dumps(response))))
    self.send_header("Some-Custom-Data", "fdsfdsggg")
    self.send_header("Some-Custom-Data-2", "aaaafdsfdsggg")
    self.send_header("Content-Type", "application/json")
    self.end_headers()

    self.wfile.write(json.dumps(response).encode())

  def do_POST(self):
    content_length = int(self.headers.get("Content-Length", 0))
    body = self.rfile.read(content_length).decode()

    self.send_response(200)
    self.send_header("Content-Type", "application/json")
    self.end_headers()

    response = {
      "method": "POST",
      "body": body
    }

    self.wfile.write(json.dumps(response).encode())

def run(server_class=HTTPServer, handler_class=RequestHandler, port=8000):
  server_address = ("", port)
  httpd = server_class(server_address, handler_class)
  print(f"Server running on http://localhost:{port}")
  httpd.serve_forever()

if __name__ == "__main__":
  run()
