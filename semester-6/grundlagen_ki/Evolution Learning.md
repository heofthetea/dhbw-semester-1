> Suchen auf [[Optimierung|Optimierungsproblem]] mithilfe von [[Evolution nach Darwin]]

- [[Wahrscheinlichkeit|stochastische]] Suche, [[Metaheuristik|metaheuristisch]]
- was **Gene** sind ist abhängig vom [[Optimierung|Optimierungsproblem]]

```python
population = random(N)
while not good_enough(best(population, 1)):
	candidates = best(population, K)
	population = candidates.reproduce()
```

> [!hint] Der beste der Generation wird 1:1 in die nächste Generation übernommen
> Man kann sich trotzdem verschlechtern, wenn die Umgebung [[Nichtdeterminismus|nichtdeterministisch]] ist
## Prinzip
1. [[Zufallsvorgang|Zufällige]] Generierung einer Lösung
2. Evaluation der Lösung
3. Yeet the bad ones

![[Pasted image 20260316094012.png]]


## Vorteile
- Globale Suche, robust gegen lokale Optima
- Gut [[Multithreading|parallelisierbar]]
- Braucht weniger Domänenwissen
	- deswegen flexibel

## Nachteile
- Hoher Rechenaufwand
- [[Nichtdeterminismus|nicht-deterministisches]] Verhalten
- keine **Garantie** für ein Optimum
- Sehr Sensitiv gegenüber [[Hyperparameter|Parameter]]
- Gefahr der vorzeitigen Konvergenz (lokales Optimum???)