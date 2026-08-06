[[XOR]]

> [!warning] Problem für [[Unconditional Hardness]]: ich brauch zusätzlich ein Schlüsselverteilungsverfahren

#todo Beispiel

- einfach nur [[Bit]]-wise [[Klartext]] mit [[Ciphertext]] [[XOR]]-en 

> [!hint] [[Unconditional Hardness]]: Durch [[XOR]] ist es unmöglich zu sagen ob eine $1 = 0 \oplus 1$ im [[Ciphertext]] bedeutet dass die $1$ im [[Klartext]] steht, oder im [[Cryptographic Key|Schlüssel]]
### Anforderung
1. Darf nur einmal benutzen
2. Muss _perfekt_ [[Zufallsvorgang|zufällig]] sein
3. [[Cryptographic Key|Schlüssel]] muss genau so lang sein wie der [[Klartext]]
4. Darf nur Sender und Receiver zugänglich gemacht werden

> [!hint] implizite Anforderung: hinreichend Langer [[Klartext]] (ein halbes Byte ist einfach bruteforcable)

