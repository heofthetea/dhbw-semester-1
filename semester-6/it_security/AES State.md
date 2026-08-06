- Stichwort Golloire-Feld

> [!hint] Gewährleistet durch die Verschiebungen von Matritzenfeldern die kryptografischen Properties von [[AES]] sicher.

- 4x4 [[Matrix]]
- Substitutionen werden auf [[Klartext]] durchgeführt
- ermöglicht Transformationen



![[Pasted image 20260319160723.png]]

## Operationen
### AddRoundKey
- bitwise [[XOR]] zwischen Round key und dem [[State]]

### SubBytes
- Sbox
- Maps an Input [[Byte]] of the State to a new output byte of the state
- in der Regel durch [[Lookup Table]] implementiert

### ShiftRows
- jede Zeile wird nach links rotiert

### Mixcolumns
- multiplication von jeder Spalte mit einem [[Polynom]]

> [!hint] ist die rechenintensivste Transformation