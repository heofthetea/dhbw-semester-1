
- im Prinzip wieder nur Lösen eines [[Optimierung|Optimierungsproblems]]
- [[Backpropagation]] zur Optimierung
- ist ein iterativer Prozess: jede Iteration ist eine "Epoche" (kommt prolly aus dem evolutionsbasierten Lernen)

## Hyperparameter
- **Epochen**: Wie viele Iterationen?
- **Batches**: Wie viele Batches?
	- Trainingsdaten werden in der Regel nicht am Stück als Input verwendet (zu viele)
	- => $D_{train}$ wird in $b$ [[Teilmenge|Teilmengen]] (= [[Batch|Batches]]) unterteilt
	- wird idR selber gemacht vom NN (????????????????????)
![[Pasted image 20251205124812.png]]
## Parameter
- [[Loss]]-Funktion: Wie gut sind die gelernten Gewichte?
	- => stark von der Problemstellung abhängig
- **Optimizer**: Wie werden die Gewichte während des Trainings adaptiert?
	- Aufgabe: Loss Funktion minimieren
	- Bsp: [[Gradient Descent]], [[Adaptive Moment Estimation|Adam]] (most popular)

## Loss Function
### Regression
- [[Mean Squared Error]]

### Klassifikation
- Cross Entropy
