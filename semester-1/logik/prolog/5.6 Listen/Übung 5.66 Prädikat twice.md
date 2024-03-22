![[Pasted image 20240205141633.png]]

```Prolog
twice([], []).
twice([H|T], [H, H | TB]) :- twice(T, TB).
```
[[twice.pl]]

