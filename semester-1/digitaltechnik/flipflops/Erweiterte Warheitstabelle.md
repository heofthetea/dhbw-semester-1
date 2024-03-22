Dadurch, dass $Q_{1}$ von $Q_{1}$ in _vorherigem_ Zustand abhängt, steht auf Ausgangsseite der Wahrheitstabelle eine Variable
--> das ist eklig

_Lösung_: Da $Q_{1}$ nur zwei Werte einnehmen kann, wird $Q_{1}$ einfach auf linke Seite geschoben

> [!Info]
> In Klausur nur gefordert, wenn es um [[Charakteristische Gleichungen]] oder [[Berechnung von Synchronzählung]] geht Wenn einfach nur Wahrheitstabellen aufgestellt werden müssen, kann eine reguläre Wahrheitstabelle angegeben werden.
### Beispiel: RS-FF
| S | R | $Q_{1{t_n}}$ |
| ---- | ---- | ---- |
| 0 | 0 | $Q_{1{t_{n-1}}}$ |
| 0 | 1 | 0 |
| 1 | 0 | 1 |
| 1 | 1 | -X- |

==> expandiert zu:

| S | R | $Q_{1{t_{n-1}}}$ | $Q_{1{t_{n}}}$ |
| ---- | ---- | ---- | ---- |
| 0 | 0 | 0 | 0 |
| 0 | 0 | 1 | 1 |
| 0 | 1 | 0 | 0 |
| 0 | 1 | 1 | 0 |
| 1 | 0 | 0 | 1 |
| 1 | 0 | 1 | 1 |
| 1 | 1 | 0 | -X- |
| 1 | 1 | 1 | -X- |
**Achtung**: Zeitinformation muss _immer_ enthalten sein:
- Linke seite: $t_{n-1}$
- Rechte seite: $t_n$
