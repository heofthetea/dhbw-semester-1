> Was nicht aus der [[Wissensbank]] folgt, ist falsch.
> _built into_ Prolog

Kontraposition von [[Closed World Assumption]]
- Wenn $Goal$ aus [[Wissensbank]] folgt: return $true$
- else: $false$

### Realisierung
[[Prädikat ! (Cut)]]
[[Prädikat fail]]
```Prolog
not(Goal) :- Goal, !, fail.
not(Goal).
```

### Unterschiede zu logischer Negation
> Logische Negation in Prolog: `\+`
- [[Negation as Failure]] `not(Goal)` gilt _nur_, wenn $KB \land \lnot Goal$ ([[Wissensbank]] konjugiert mit negiertem Goal) erfüllbar ist
- Negierte Fakten `not(Fact(X)).` ist nicht möglich xd