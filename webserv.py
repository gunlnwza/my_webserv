import socket
import signal
import sys

HOST = '127.0.0.1'
PORT = 8080

def shutdown(signum, frame):
    print("\nShutting down server...")
    sys.exit(0)

signal.signal(signal.SIGINT, shutdown)

def start_server():
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        s.bind((HOST, PORT))
        s.listen()
        print(f"Listening on {HOST}:{PORT}...")

        while True:
            conn, addr = s.accept()
            with conn:
                print(f"Connected by {addr}")
                handle_connection(conn)

def handle_connection(conn):
    request = conn.recv(1024).decode()
    print("Request:\n", request)

    if not request:
        return

    method, path = parse_request(request)
    body = route_request(method, path)
    response = build_response(200 if body else 404, body)
    
    conn.sendall(response.encode())

def parse_request(request):
    lines = request.splitlines()
    if not lines:
        return "GET", "/"
    method, path, _ = lines[0].split()
    return method, path

def route_request(method, path):
    if path == "/":
        return "Hello from /"
    elif path == "/about":
        return "This is the about page."
    else:
        return ""

def build_response(code, body):
    status = {
        200: "OK",
        404: "Not Found"
    }
    header = f"HTTP/1.1 {code} {status[code]}\r\n"
    header += "Content-Type: text/plain\r\n"
    header += f"Content-Length: {len(body)}\r\n"
    header += "\r\n"
    return header + body

if __name__ == "__main__":
    start_server()