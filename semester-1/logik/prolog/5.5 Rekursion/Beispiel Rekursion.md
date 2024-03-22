## [[Imperative Programmiersprache]]
### Iterativ
```c
int factorial(int n) {
	int fac = 1;
	for(int i = 1; i <= n; i++)
		fac = fac * i;
	return fac;
}
```

### Rekursiv
[[Recursion]]
- ist mehr Arbeit für Compiler lol
- aber: _"To iterate is human, to recurse divine"_.
- Eleganter: Einfach definition abgeschrieben 
```c
int factorial(int n) {
	if (n == 0)
		return 1;
	
	return n * factorial(n - 1);
}
```