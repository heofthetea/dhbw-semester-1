![[Pasted image 20240205171154.png]]
- durch XORs wird entschieden, ob Subtrahend Summand wird
	- je nachdem wird Komplement gebildet
_Idee_: Bei Steuerleitung invertieren

_Enable_-Eingang:
- statt $XOR$s $AND$s: Information wird _nur_ weitergeleitet, wenn $E = 1$ ist
	==> ansonsten liegen nur 0 an -->[[Neutrales Element]] der Addition

> [!info] Wenn Steuerleitungen für sowohl $XOR$ als auch $AND$ existieren, kann gesteuert werden, ob B subtrahiert werden soll, oder gar nichts gemacht

### Steuerschaltung

| S | B | Expected Output X |
| ---- | ---- | ---- |
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 0 |
==>$X = S \oplus B$  