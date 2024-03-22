Aufruf an [[Rekursive Prädikate|Rekursives Prädikat]] wird als _letztes_ angesprochen.
-> Es werden erst alle Fälle mit Ergebnis abgearbeitet, bevor [[Endlosschleife]] geschieht

```
descend(X, Y) :- child(Z, Y), descend(X, Z). %tail-rekursiv
descend(X, Y) :- descend(X, Z), child(Z, Y). %NICHT tail-rekursiv
```

[[tail_rekursiv.pl]]