> returns $true$ wenn alle Argumente eine [[Liste]] sind und

- _1. Argument_: Liste $A$
- _2. Argument_: Liste $B$
- _3. Argument_: Liste $C$, mit `C = A.append(B)`. 

### Funktionsweise
```Prolog
append([], L, L).
append([H|T], L, [H|R]) :- append(T, L, R).
```
vgl. Prädikat `add/3` in [[Übung Rekursive Addition]]


### Suchbaum
![[Pasted image 20240205145928.png]]