[[Goals of Cryptography]]

> [!info] Serves the combination of **Integrity** and **Authenticity** [[Goals of Cryptography]].

- Fundamental idea:
	- use [[Forward Error Correction|FEC]] so that if the [[Nachricht|Message]] would be tampered with, the signature would not be valid
		- obviously, an attacker can easily forge this by re-computing the [[Forward Error Correction|FEC]] for the new message
	- => Also include the [[Private Key]] of the sender, so that the signature is only valid if it conforms with the sender's [[Public Key]] (whatever exactly that means)

## Basic Architecture
![[Pasted image 20260319163837.png]]