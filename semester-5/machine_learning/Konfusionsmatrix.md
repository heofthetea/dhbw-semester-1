> Zeigt an, wie viele Verwechslungen es zwischen der erwarteten und der tatsächlichen Klasse $\hat{\omega}$ und $\omega$ 
> und: We


- Dient dazu, systematische Fehler zu finden



## Im Binären Fall
- $\omega$: Klasse
- $\hat{\omega}$: Geschätzte Klasse (durch [[Klassifikator]])

| $n_{ij}$           | $\omega_{1}$            | $\omega_{2}$            |
| ------------------ | ----------------------- | ----------------------- |
| $\hat{\omega_{1}}$ | TN = True negative      | FN = [[False Negative]] |
| $\hat{\omega_{1}}$ | FP = [[False Positive]] | TP = True Positive      |
> [!warning]- $Acc$ und $ER$ gewichten [[False Positive]] und [[False Negative]] gleich stark -> ist nicht immer der Fall
> 1. Ärztliche Diagnose: FP weniger schlimm als FN (FP = mehr tests, FN = tot)
> 2. Polizeistaat: FN weniger schlimm als FP (FN = falsch unschuldig (nach Unschuldsvermutung gut), FP = unschuldige hinter gittern)
### Derived Metrics im Binären Fall
#### Fehlerrate
[[Fehlerrate|Error Rate]]
$$\frac{n_{ij}}{N}$$
- für $c = 2$
$$\frac{FP+FN}{2}$$

#### Accuracy
[[Accuracy]]
$$ACC = \frac{n_{ii}}{N}$$

- für $c= 2$:

$$\frac{TP+TN}{2}$$

