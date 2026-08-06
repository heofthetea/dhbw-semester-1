> Standardisiertes [[Menge|Set]] an [[Cryptographic Key|kryptografischen]] [[Algorithmus|Algorithmen]] für [[TLS]] Network connections

- [[Client]] und [[Server]] einigen sich auf eine Suite
## Beispiel TLS 1.2
```
TLS_ECDHE_RSA_WITH_AES_256_GCM_SHA384
```

![[Pasted image 20260426181937.png]]

- [[TLS]]
- [[asymmetric Encryption]]:
	- [[RSA]] für [[Authentication|Authentifizierung]] von [[Certificate]]
	- [[ECDHE]] für [[Schlüsselaustausch]]
- `AES_256_GCM`: [[symmetric Encryption]] mit [[AES]] GCM (GCM ist ein [[AES Modi|AES Modus]])
- [[SHA-256|SHA-384]] für [[Message Authentication Code]] Authentifizierung