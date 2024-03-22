> Improvement upon [[Backtracking ist ineffizient]]


```Prolog
abs(X, X) :- X >= 0, !.
abs(X, Y) :- X < 0, > is -X.
```
--> ist `abs(X, X)` erfolgreich, werden alle weiteren Verzweigungspunkte durch [[Prädikat ! (Cut)|Cut]] getrimmt.
### Suchbaum
![[Pasted image 20240206132859.png]]