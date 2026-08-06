> Die Klasse $\omega_{i}$, für die [[Likelihood]] maximal ist, wird ausgewählt

![[Pasted image 20251031131256.png]]

## Sonderfall von [[MBR Klassifikator]], wenn:
### Vorraussetzungen
1. [[01-Loss]]
2. gleiche [[A-priori Wahrscheinlichkeit]]en (vgl. [[Laplace Experiment|Diskrete Gleichverteilung]])


## Beispiel: Bit-Übertragung
- $P(x = -1) = P(x = 1) = \frac{1}{2}$ => [[Laplace Experiment|Diskrete Gleichverteilung]]
- [[01-Loss]] -> ??

![[Pasted image 20260715111910.png]]


### Entscheidungsgrenze
- [[Entscheidungsgrenze]] einfach bei $0$ ansiedeln -> am wenigsten Überlappunt

$$\hat{s}_{ML} - \begin{cases}-1;\qquad x \lt 0 \\ 1; \qquad x \gt 0\end{cases}$$


