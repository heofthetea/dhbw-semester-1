> [[Public Key]] mit einer Identität verbinden

- genutzt für [[Electronic Signature]] oder [[Domain]] Certificates
- x509 v3 spezifiziert in [[RFC]] 5280
	- definiert Format, Revocation, und Construction/Validation
- 

### Struktur
- Version
- Serial Number
- [[Electronic Signature]]
- Issuer
---
- Validity (time-bound)
	- `Not Before` ("ab wann")
	- `Not After` ("bis wann")
- Subject (End-nutzer)
- subject [[Public Key]]
- Extensions (proprietary, public, ...)
	- Key Usage restrictions: 
---
- welcher Algorithmus für die Signatur?
- [[Digital Signature]]

![[Pasted image 20260319164705.png]]


> [!hint] steckt hinter [[CA Certificate|SSL Certificate]]


## Decode Certificate
```bash
openssl x509 -in cert.pem -text -noout
```
