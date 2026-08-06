[[Beispiel Dijkstra]], [[Graph]]

- [[Greedy Algorithm]] ==> Funktioniert nicht, wenn [[Gewichteter Graph|Gewichte]] von externen Faktoren (z.B. anderen Gewichten) abhängig sind


> [!info] Ergebnis ist ein [[Baum]] mit dem Startknoten als [[Wurzel]]

> [!hint] [[Dijkstras Algorithm|Dijkstra]] ist [[Prim Algorithmus|Prim]], bei dem sich der _gesamte_ [[Pfad]] vom Startknoten aus angeschaut wird, nicht nur eine einzelne [[Kante]].

> [!hint] [[Dijkstras Algorithm]] ist im Prinzip eine [[Breadth-First Traversion|Breadth-First search]] 

### Komplexität
$$\in \mathcal{O}(|V|^2)$$
Durch Optimierunge mit Datenstrukturen:
$$\in \theta(|E| \cdot log(|V|))$$
# Algorithmus
**Eingabe**: [[Graph]] $G(V, E)$, [[Gewichteter Graph|Kantengewicht]]-Funktion $e$, _Startknoten_ $v_{s}$

#### 1. Initialisierung
$d(v_{s}) = 0$ (Startknoten ist 0 Schritte von sich selbst entfernt)
$\forall_{v_{i}\neq v_{s}}: d(v_{i}) = \infty$

#### 2. Iteration
1. Setze aktuellen [[Knoten]]  $v_{c}$
2. Für alle Nachbarn $v_{n}$von $v_{c}$
	1. Berechnde $d(v_{n}) = d(v_{c}) + e(v_{c}, v_n)$ 
	2. wenn $d(v_{n})$ kleiner ist als der aktuelle Wert für $v_{n}$, update
3. Füge $v_{c}$ zur [[Menge]] der besuchten [[Knoten]] $B$ hinzu
4. Wenn $B = V$ gilt: fertig
	1. else: Wähle neues $v_{c}$ aus $A \textbackslash B$ 

## Informal
1. Initialisiere jeden [[Knoten]] mit Distanz $\infty$ und merke sich für jeden [[Knoten]] den Vorgänger
2. Gehe vom aktuellen [[Knoten]] alle ausgehenden [[Kante|Kanten]] $(v_{c}, v_{i})$an
	1. update Wert für $v_{i}$, falls Distanz kürzer ist als vorherige
	2. update ebenfalls den Vorgänger
3. wähle nächsten aktuellen Knoten als denjenigen Nachvolger von $v_{c}$, der die <span style="color:rgb(245, 154, 35)">kürzeste</span> Distanz insgesamt hat
	1. Dabei wird der letzte aktuelle Knoten als _finalisiert_ markiert

## Implementierung
#todo 
```python
def dijkstra(graph, start):
	current = graph.node(start)
	current.update_dist(0)
	while current:
		for succ, weight in current.adj_list:
			 
```

- [[Knoten]], für die bereits Werte computed wurden, können in [[Queue]] gespeichert werden
	- falls Wert geupdatet wird: neu zur [[Queue]] hinzufügen