> Recursion is a programming technique where a function calls itself to solve smaller instances of the same problem until a base case is reached, facilitating problem-solving by breaking it down into smaller, more manageable tasks. (thanks, chatGPT)
## Beispiel: Fakultät
![[recursion_in_memory.png]]

```c
int factorial(int n) {
	if (n == 0)
		return 1;
	
	return n * factorial(n - 1);
}
```


## Beispiel: Türme von Hanoi
| Scheiben | Züge |  |
| ---- | ---- | ---- |
| 1 | 1 |  |
| 2 | 3 |  |
| 3 | 7 |  |
Wie viele Züge sind notwendig?
--> rekursiv: 
$A_{1} = 1$
$A_{n+1}= 2\;A_{n} + 1$
--> explizit: $A_{n}= 2^{n} - 1$

--> 64 Scheiben (mit einer Sekunde pro Scheibe): $A_{64} \approx 6*10^{11}$ Jahre


Variable:
1 Zug = 100 instructions
CPU takt = 4 GHz
--> $4 * 10^9$ instructions/seconds --> $4 * 10^8$ seconds
==> AMD Ryzen 7 needs ~150 years


### Implementation
[[hanoi.c]]

Pseudo-Code:
```python
def hanoi(from, to, disc):
	temp_pos = position \ {from, to}
	if disc == 1:
		move(disc, from, to);
	
	hanoi(from, temp_pos, disc - 1)
	move(disc,from, to)
	hanoi(temp_pos, to, disc - 1)
```

to get temp_pos index:
```python
temp_pos = (1 + 2 + 3) - (from + to)
```


