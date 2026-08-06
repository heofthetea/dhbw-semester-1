> Welche Art der Verwechslung ist schlimmer? (-> [[Konfusionsmatrix]])

$$L_{ij} = L(\hat{\omega} = \omega_{i}, \omega = \omega_{j})$$
- 1. Parameter -> geschätzte [[Klasse]] ist $\omega_{i}$
- 2. Paremter -> tatsächliche [[Klasse]] ist $\omega_{j}$
## Idee
- $L_{ii} = 0$
- $L_{ij} \gt 0$ für $i \neq j$
- $L_{ij} \uparrow$ für schlimme Fehler, $L_{ij} \downarrow$ für verzeihbare Fehler


$$L = \begin{bmatrix} L_{11} & \dots & L_{1c} \\ \vdots & \ddots & \vdots \\ Lc1 & \dots & L_{cc} \end{bmatrix}$$

## Verbreitet
- [[Binary Cross Entropy]]
- [[Accuracy]], [[Recall]] or other [[Evaluation eines Modells|Bewertungsmetrik Klassifikation]]
- [[Focal Loss]]