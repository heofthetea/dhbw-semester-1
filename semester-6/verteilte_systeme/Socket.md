> Kommunikationsendpunkt, mit dem [[Prozess|Prozesse]] über [[Netzwerk]] Kommunizieren können

[[TCP]], [[IP]], [[Port]]

- Ein Socket ist ein 3-Tupel $S = (I, \Pi, P)$, wo:
	- $I$: die [[IP Adresse]] des Sockets ist
	- $\Pi$: der [[Port]] des Sockets
	- $P$: das [[Protokoll]] (meistens [[TCP]]/[[UDP]])
- Commt noch Information über den verbundenen [[Client]] dazu, wird es ein 5-tupel
	- -> ist dann ein Verbindungssocket

## Listening vs Verbindungssocket
- **Listening Socket**: Lauscht auf einem [[Port]] und wartet auf incoming connections
- **Connection Socket**: Baut eine Verbindung zum Client auf
	- Beinhaltet zusätzlich noch Information über de Client Socket
	- damit Listening Socket weitere Verbindungen entgegen nehmen kann
	- [[Client]]s öffnen nur Verbindungs-Sockets

![[Pasted image 20260224094812.png]]
## Rust ([[TCP]])
```rust
let listener = tokio::net::TcpListener::bind(args.address).await?;
```

## Python (TCP)
```python
import socket

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind("127.0.0.1", 80)
server.listen(1)

client_sock, addr = server.accept()

while True:
	data = client_sock.recv(1024).decode()
	if data.lower == "close":
		break
client_sock.close()
server.close()
```