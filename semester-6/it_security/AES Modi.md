
- Plaintext: Klartex
- ciphertext: verschlüsselte Text
- IV: Seed

## ECB
> Electronic Code Book Mode

- simpelste [[Block Cipher]]
- Einzelne Blöcke sind in keiner Form miteinander verknüpft
	- -> Anfällig für Häufigkeitsanalyse
![[Pasted image 20260319155017.png]]

## CBC
> [[Cipher Block Chaining]]

- zufälliger [[Seed|Initialisierungsvektor]]
	- => Dadurch: [[Zufallsvorgang|Zufallselement]]
- Der Output eines Blocks wird als [[Seed|Initialisierungsvektor]] für den nächsten Block verwendet ([[XOR]])

![[Pasted image 20260319155200.png]]

## CFB
> Cipher Feedback Mode

![[Pasted image 20260319155444.png]]


## OFB
> Output Feedback Mode

- [[Encryption|verschlüsselter]] [[Seed|IV]] wird weiter gereicht, _bevor_ er mit [[Klartext]] [[XOR]]-ed wird

![[Pasted image 20260319155948.png]]

## CTR
> Counter Mode

- jetzt kommt ein Counter hinzu
	- inkrementiert einfach mit jedem Block
- auch eine [[Nonce]] kommt dazu
- Counter und [[Nonce]] werden verschlüsselt
- Danach mit [[Klartext]] XORd

> [!warning] Hier hat's keine Weiterreichung mehr

![[Pasted image 20260319160237.png]]

## GCM
- [[Stream Cipher]]