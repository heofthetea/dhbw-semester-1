
[[symmetric Encryption]]
[[asymmetric Encryption]]


> [!hint] Technically is [[Hashing]] is also an [[Encryption]] scheme -> but cannot be decrypted.


- wird immer mit [[XOR]] gemacht

## Formally (maybe)
4-[[Tupel]]:

$$(A, P, C, K)$$
- $A$: [[Alphabet]] (basicaly [[Boolsche Menge]])
- $P$: [[Nachricht|Message]] space, contains the [[Klartext|Plaintext]]
- $C$: [[Ciphertext]]
- $K$: Keyspace; eine [[Bijektive Abbildung]] mit:
	- [[Encryption]] [[Abbildung|Funktion]] $E: M \longrightarrow C$
	- Dekryption [[Abbildung|Funktion]] $D: C \longrightarrow M$
