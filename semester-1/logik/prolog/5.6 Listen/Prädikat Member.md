> `member(T, L)` 
> returns $true$, wenn $T \in L$, sonst $false$.

- zweistellig
- _1. Argument_: Term $T$
- _2. Argument_: Liste $L$
- Argumente können _Variablen sein_ --> belegt Variable der Reihe nach mit _allen Elementen_ der Liste aus

### Funktionsweise
- [[Rekursive Prädikate]]
```Prolog
member(X, [X|_]).
member(X, [_|T]) :- member (X, T).
```
- Implementation mit [[Anonyme Variable|anonymer Variable]] je [[Basisklausel]] verhindert verzweigungspunkte.
	==> [[Unifikation]] findet in _Regelkopf_ statt
	
### Beispiel
![[Pasted image 20240205134044.png]]

