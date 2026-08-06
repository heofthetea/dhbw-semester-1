> Replacement for [[Binary Cross Entropy]] for imbalanced problems

$$L(\hat{p_{i}}) = -\alpha_{i}(1-\hat{p_{i}})^{\gamma}\log(\hat{p_{i}})$$

- $\hat{p_{t}}$ is the [[Wahrscheinlichkeit|probability]] for the true class:
	- $\hat{p_{i}} = \begin{cases} \hat{y}\qquad \quad \text{if} \ \  y = 1 \\ 1 - \hat{y} \quad \text{otherwise}\end{cases}$
	- basically: $\hat{p_{i}} \rightarrow 0$ the more confident a model is in its class
- $\gamma$ weighs this term (typically $\gamma = 2$) - called **focus parameter**
- $\alpha_{t}$ scales for class imbalance; e.g. the [[Umkehrfunktion|inverse]] class [[Relative Häufigkeit|frequency]] $\frac{|\Omega|}{|occ(\omega_{i }|}$ 

> [!hint] for [[Batch]] scoring, one can simply sum over $i$

### Functionality
- for a misclassified sample (or uncertainty), $\hat{p_{i}} \rightarrow 0 \Rightarrow (1-\hat{p_{i}}) \rightarrow 1$ 
	- => the term stays and increases the loss

