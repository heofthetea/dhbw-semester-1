## Beispiel: Mathematischer Betrag
[[absolute_value.pl]]
```Prolog
abs(X, X) :- X >= 0.
abs(X, Y) :- X < 0, > is -X.
```

- Funktionsweise problemlos:
	- `abs(-5, R)` --> $R = 5$.
	- `abs(%, R)` --> $R = 5\ ; false$.
--> _nerviges $false$ mit richtigen Lösungen konjugiert_

### Suchbaum
![[Pasted image 20240206131720.png]]

- Backtracking geht _ganzen_ [[Suchbaum]] entlang
	==> Verzweigungspunkt für _jeden_ Aufruf des `abs` Prädikats
- Viele unnötige Verzweigungen sind, offensichtlich, ineffizient
- Interpreter _weiß nicht_, dass weiterer Weg unnötig ist
