> `length(List, Length)`

- _erstes Argument_: Liste
- _zweites Argument:_ Länge der Liste

### Funktionsweise
[[Leere Liste]]
[[Ganzzahl-Arithmetik#Variablenzuweisung]]
```Prolog
length([], 0).
length([_|T], X) :- length(T, Y), X is Y + 1.
```

### Beispiel
![[Pasted image 20240205140352.png]]

