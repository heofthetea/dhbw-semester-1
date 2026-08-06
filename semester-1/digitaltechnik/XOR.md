$$a \oplus b =(a \land b) \lor (\lnot a \land \lnot b)$$

[[Kommutativität]]

> [!hint] Ist äquivalent zur [[8051 ADD|Addition]] [[Modulo]] $2$.

| a   | b   | $a \oplus b$ |
| --- | --- | ------------ |
| 0   | 0   | 0            |
| 0   | 1   | 1            |
| 1   | 0   | 1            |
| 1   | 1   | 0            |


## Eigenschaften
- $a \oplus a = \vec{0}$  [[Zero]]
- [[Zero]] ist [[Neutrales Element]] -> $a \oplus \vec{0} = a$ 
	- $\vec{1}$ ist das auch btw
- [[XOR]] ist eine Addition [[Modulo]] $2$
	- => daraus folgt die Umkehrbarkeit

> [!hint] [[XOR]] ist seine eigene [[Umkehrfunktion]]


# n-stelliges [[XOR]]
- durch [[Kommutativität]]: Einfach beliebig in zweier Paare ausrechnen
> [!hint] Cheat-code: Anzahl der einsen zählen: 
> - ungerade -> xor = 1
> - gerade -> xor = 0

