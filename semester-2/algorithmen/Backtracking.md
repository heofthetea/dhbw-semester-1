> Algorithmus für Constraint Satisfaction

[[Recursion]]

- sobald eine Entscheidung getroffen werden muss:
	- probiere eine möglichkeit
	- wenn später was schief geht:
		- gehe zurück zum letzten Entscheidungspunkt
		- probiere was anderes


## fundamental implementation
```python
def backtracking(choice):
	for option in options:
		if backtracking(option) succeeds:
			return option # was right choice
	return Failure # no option succeeded
```
