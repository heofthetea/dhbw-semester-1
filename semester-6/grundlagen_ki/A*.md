> Optimisierung von [[Dijkstras Algorithm|Dijkstra]] durch [[Heuristik]]

> [!warning] Anders als bei Dijkstra gibt es auch einen festen _Zielknoten_.

- Suchheuristik $h$: [[Schätzung]] der Distanz zum Zielknoten
	- Für jeden Nachbar-[[Knoten]] in der [[Queue]]: Gewichtung wird beeinflusst durch die [[Heuristik]]
	- Heuristik muss _immer_ die tatsächliche Distanz _unterschätzen_ damit sie funktioniert.

> [!hint] Für Navigation: Luftlinie ist eine gute Heuristik.


> [!hint] Wenn $h = 0$, ist die Suche uninformiert, also einfach ein [[Dijkstras Algorithm|Dijkstra]].


## In practice
1. Define the [[Heuristik]] function $h(v)$
2. add it on top of the queue weight

```python
dist[v] = dist[u] + weight
prev[v] = u
Q.push(v, dist[v] + h(v, target))
```

> [!warning] Only add the weight when talking to the [[Queue]] -> otherwise the distance of each node is persisted in the graph, skewing the result.