> use two different [[Cryptographic Key|keys]] for en- and decryption

```mermaid
sequenceDiagram
Participant Alice
Participant Bob

Bob <<->> Alice: negotiation
Alice ->> Bob: PKEY A
Bob ->> Alice: PKEY B

```

> [!hint] Usually, asymmetric Encryption is used for the exchange of [[symmetric Encryption|symmetric]] [[Cryptographic Key|Keys]].

![[Pasted image 20250424112614.png]]

### Example
- [[RSA]]