---
aliases:
  - Sequential Probability Ratio Test
---
[[Hypothesentest]]

- [[Nullhypothese]] $ELO_{0}$
- [[Alternative Hypothese]] $ELO_{1}$

### LLR
- Log [[Likelihood]] Ratio
- Models: how likely is the current standing under the assumed ELO bounds $[ELO_{0}, ELO_{1}]$?

$$\log(p(P_{w}\ |\ [ELO_{0}, ELO_{1}]))$$
### Bounds für LLR
- Errechnet aus den desired [[Fehler 1. Art]] und Fehler 2. Art:

$$[lo, hi] = \left[log\left(\frac{\beta}{1-\alpha}\right),\ log\left(\frac{1-\beta}{\alpha}\right)\right]$$


## Example: Fastchess Output
```
--------------------------------------------------
Results of current vs previous (5+0.5, NULL, NULL, 8moves_v3.pgn):
Elo: 631.91 +/- nan, nElo: 1056.68 +/- 77.10
LOS: 100.00 %, DrawRatio: 5.13 %, PairsRatio: inf
Games: 78, Wins: 76, Losses: 2, Draws: 0, Points: 76.0 (97.44 %)
Ptnml(0-2): [0, 0, 2, 0, 37], WL/DD Ratio: inf
LLR: 2.96 (100.6%) (-2.94, 2.94) [0.00, 20.00]
--------------------------------------------------
SPRT ([0.00, 20.00]) completed - H1 was accepted
Finished match
Total Time: 00:16:40 (hours:minutes:seconds)
```

- Parameter:
	- $ELO_{0} = 0$ (i.e. Engines sind gleich stark)
	- $ELO_{1} = 1$ (i.e. `current` ist 20 Elo stärker als `previous`)
	- $\alpha = 0.05 = 5\%$
	- $\beta = 0.05 = 5\%$ 
		- => Konfidenz $= 100 - (5 + 5)\% =  90\%$ (?)

## Format: `LLR: 2.96 (100.6%) (-2.94, 2.94) [0.00, 20.00]`

- LLR: Log-likelihood Ratio
- `(100.6%)` - Wie weit fortgeschritten ist der SPRT
	- => basically just wie weit ist LLR von der näheren Konfidenzgrenze entfernt
- bounds: `(lo, hi)` (s. [[#Bounds für LLR]])
- Hypothesen `[ELO-0, ELO-1]`

## Ballpark

| expected ELO Gain | approx. Games for LLR convergence |
| ----------------- | --------------------------------- |
| 400               | 5-15                              |
| 67                | 200-500                           |
| 28                | 800-2000                          |
| 10                | 5000-10 000                       |
| 5                 | > 20c 000                         |
