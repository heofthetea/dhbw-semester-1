[[Prädikat ! (Cut)]] und [[Prädikat fail]] in Kombination

- "Vincent mag alle Burger außer den 'Kahuna'."
```
likes(vincent, kahuna) :- !, fail.
likes(vincent, X) :- burger(X).

burger(bigMac).
burger(kahuna).
burger(royale).
```

#### Antworten
![[Pasted image 20240206143029.png]]
--> Problem: `fail` kann _zu früh_ auslösen! --> [[Negation as Failure]]


### Using not()
[[Negation as Failure]]
```Prolog
likes(vincent, X) :- 
	burger(X),
	not(X = kahuna).

burger(bigMac).
burger(kahuna).
burger(royale).
```

![[Pasted image 20240206144035.png]]