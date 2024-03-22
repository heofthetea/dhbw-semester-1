> \=/2

- Negation von `=` ([[Unifikation]])
- gibt $false$ zurück, wenn Argumente unifizierbar sind
- gibt $true$ zurück, wenn Argumente _nicht_ unifizierbar sind
- Gibt _nie_ Variablenbindungen zurück **!!**

```
?- mia \= vincent.
true.

?- a \= B.
false.

?- B = b, a \= B.
true.
```
