---
aliases:
  - SSL Certificate
---
[[x509 certificate]]

- [[Certificate]] ausgestellt von einer [[Certificate Authority]] (CA)

## Example
```yaml
Data: Version: 3 (0x2)
Serial Number: 24:c8:7a:45:67:a6:1c:99 
Signature Algorithm : sha256WithRSAEncryption
Issuer : C=AT, ST=Vienna , O=Course Test, CN=Course
Validity
Not Before: May 1 05:27:16 2021 GMT
Not After : May 2 05:27:16 2026 GMT Subject : C=AT, ST=Vienna , O=Course Test, CN=Course Subject Public Key Info :
Public Key Algorithm : rsaEncryption RSA Public Key: (4096 bit)
Modulus (4096 bit ): 00:c7:a6:87:d1:e6:93:25:33:67:10:d8:a4:22:40:...
Exponent : 65537 (0 x10001 ) X509v3 extensions :
X509v3 Subject Key Identifier: AA:76:4A:C3:87:BD:32:33:AC:A4:C3:75:A8:23:A5:97:B3:2B:11:CC
X509v3 Authority Key Identifier:
	keyid: EA:89:8D:B4:94:AC:77:D8:ED:ED:DC:11:B8:13:A4:9A:B6:4B:61:B2
	DirName: /C=AT/ST=Vienna/O=Test 
	serial: 75:A4:AA:C3:34:E3:A7:87
Course/CN=Test
X509v3 Basic Constraints:CA:TRUE
X509v3 Key Usage:
	- CertificateSign , CRLSign
Signature:
46:78:33:a6:d4:43:cd:98:3d:23:f2:d6:84:3a:dd:28:65:a3 :............
```

## Obtain all Certificates served by a server
```bash
openssl s_client -connect example.com -showcerts
```