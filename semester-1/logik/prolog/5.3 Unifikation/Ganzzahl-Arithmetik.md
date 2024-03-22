[[Zahl]]
## Variablenzuweisung
![[Prädikat is]]


## Integer-Operationen

| Symbol | Operation |
| ---- | ---- |
| $+$ | Plus |
| $-$ | Minus |
| $div$ | division (abschneiden) |
| $mod$ | modulo |

- "Punkt vor Strich" wird respektiert
- Klammerausdrücke erlaubt
- _Infix-_ und _Präfixnotation_ ist erlaubt: $2 + 3 \Leftrightarrow +(2, 3)$ 

**Operatoren AN SICH führen keine Berechnungen durch !!!**
- Ausruck $+(2, 3)$ ist dasselbe wie $mother(john, mary)$ 
- ==> Benötigt Assoziation mit `is` operator


## Beispiel
in Wissensbank:
```
square(X,Y) :- Y is X * X.
inc(X, Y) :- Y is X + 1.
addThreeAndDouble(X, Y) :- Y is (X + 3) * 2.
```
--> _Achtung!_ Ergebnisvariable muss immer mit gegeben werden!

## Stolpersteine
- _alle_ Variable auf _rechter_ Seite müssen _gebunden_ sein!
- rechte Seite muss ein _korrekter_ arithmetischer Ausdruck sein
- _linke_ Seite wird _nicht_ ausgewertet!!
	- $1+2\quad is \quad 1+2$ liefert $false$, da _rechte Seite_ zu $3$ ausgewertet wird.
	- benutze [[Vergleichsprädikate]] dafür




