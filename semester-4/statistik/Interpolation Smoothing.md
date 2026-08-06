> Apply non-zero probabilities to values not observed in [[Trainingsdaten|Training Data]] 

- relevant for [[Naive Bayes]] (und andere Bayesian Klassifikatoren)

### Requisites
- High Order Estimate: [[Likelihood]] $L = p(x|\omega_{i})$ from [[Trainingsdaten|Training Data]]
- Low Order Estimate: $LOE = p(x|\omega_{i})\ \text{if}\ P(x) = 0$
	- (i.e. when the value has yet been unseen)

## Philosophies
### Backoff
- only use $LOE$ if $P(x) = 0$
- "falls back"/backs off

### Interpolation
- _Always_ blend between $LOE$ and $L$, even when $P(x) > 0$


> [!hint] in [[RBA per Freeman]] as implemented by Wiefling et al., the boolean flag `smoothing` controls whether they use Backoff or Interpolation Philosophy.
