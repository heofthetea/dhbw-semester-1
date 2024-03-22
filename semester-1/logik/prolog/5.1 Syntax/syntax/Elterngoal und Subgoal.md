Alle Goals im _Body_ sind _Subgoals_ vom Goal in Head.
Goal im _Head_ ist _Elterngoal_ von Goals im Body.

```Prolog
a(X) :-
	b(X),
	c(X), 
	d(X).
```
 hier ist `a/1` das _elterngoal_, und die Prädikate `b/1, c/1, d/1` _Subgoal_.