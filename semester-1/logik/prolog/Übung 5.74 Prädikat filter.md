![[Pasted image 20240206133241.png]]

[[Prädikat ! (Cut)]]
[[Zahl]]
```
filter([a, 1, 2, b], X).
```


### Lösung
```Prolog
filter([], []).

filter([H | T], Not_numbers) :-
    number(H), !, filter(T, Not_numbers).

filter([H | T], [H | A]) :-
    filter(T, A).
```

