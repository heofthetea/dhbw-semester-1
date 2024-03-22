
| Arithmetik | Prolog |
| ---- | ---- |
| $x < y$ | `X < Y` |
| $x \leq y$ | `X =< Y` |
| $x = y$ | `X =:= Y` |
| $x \not= y$ | `X =\= Y` |
| $x \geq y$ | `X >= Y` |
| $x > y$ | `X > Y` |

### Funktionsweise
- _Beide_ Seiten werden arithmetisch ausgewertet
- Ergebnisse werden verglichen
- Abhängig von _Ergebnissen_ ist Goal erfolgreich oder scheitert


>[!Warning]
>- _Beide_ Seiten müssen korrekte arithmetische Terme sein.
 >- _Keine_ Seite darf ungebundene Variablen enthalten
>- **Vorsicht!** es heißt `=<` und nicht `<=` (BS lol)
