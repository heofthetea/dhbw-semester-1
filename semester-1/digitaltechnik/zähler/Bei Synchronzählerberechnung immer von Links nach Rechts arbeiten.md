[[Synchronzähler]]
- Pattern des Zählers nicht von oben nach unten verfolgen (also rechte spalte als 9, 8, 7, 6, 5, ...) vorstellen
- stattdessen Eingangsseite betrachten:

### Beispiel [[Synchronzähler rückwärts]]
| Eingang ($t_n$) | Operation | Ausgang ($t_{n + 1}$) |
| ---- | ---- | ---- |
| 0 | 0 - 1 (inkl. reset) | 9 |
| 1 | 1 - 1 | 0 |
| 2 | 2 - 1 | 1 |
| 3 | 3 - 1 | 2 |
| 4 | 4 - 1 | 3 |
| 5 | 5 - 1 | 4 |
| 6 | 6 - 1 | 5 |
| 7 |  | 6 |
| 8 |  | 7 |
| 9 |  | 8 |
