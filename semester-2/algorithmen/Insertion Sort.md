> **Insertion** von richtigen Elementen von einem Im-[[Array]] in ein Out-[[Array]]

[[stable sorting algorithm]], [[out-of-place Sortieren]]

1. gehe [[Array]] von successive von vorne nach hinten durch
2. schiebe Element an der Stelle $i$ an ihre richtig [[Sortieren|sortierte]] Stelle im Output-Array

=> Out-Array ist einfach der Anfang des In-Arrays für [[in-place Sortieren]] 

> [!warning] Vertauscht immer nur benachbarte Elemente 


### Pseudo Code
```python
def insert_sort(arr):
	for i in range(1, len(arr)):
		j = i
		while j > 0 and arr[j] < arr[j - 1]:
			arr[j], arr[j - 1] = arr[j - 1], arr[j]
			j = j - 1
	return arr
```

[[Beispiel Insertion Sort]]

## Auf [[Liste]]
- man muss nur [[Pointer]] vertauschen, nichts vertauschen
-> Selbes Prinzip mit neuem [[Listenanker]]

> [!note] maximal 2 Swaps pro Schritt, weil man nicht ein halbes Array durch die gegend kopieren muss


[[Recursion]]

```python
def insert_sort_list(n):
	res = None
	while n:
		first = n
		n = n.next
		res = insert_sorted(res, first)
	return res


def insert_sorted(n, element):
	if not n:
		element.next = None
		return element

	if element.payload < n.payload:
		element.next = i
		return element
	n.next = insert(n.next, element)
	return n
	
```
