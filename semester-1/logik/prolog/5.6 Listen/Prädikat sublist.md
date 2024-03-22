[[Prädikat prefix]]
[[Prädikat suffix]]
```
sublist(Sub, List) :- 
	prefix(Pre, List),
	suffix(Sub, Pre).
```