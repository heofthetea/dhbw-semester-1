
- Problem von [[Accuracy]]: Unbalancierte Datensätze
	- Beispiel: Datensatz enthält zu $99\%$ Datenpunkte in [[Klasse]] $A$, $1\%$ aus Klasse $B$
	- Klassifikator, der immer $\hat{\omega} = A$ sagt, hat [[Accuracy]] von $\frac{99}{99 + 1} - 99\%$

=> [[Balanced Accuracy]] gewichtet nach Klassengröße


### according to Ümmü

$$FPR = \frac{FP}{FP+TN}$$