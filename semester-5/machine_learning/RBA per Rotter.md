> extends [[RBA per Freeman]]

- essentially: Feed [[Likelihood|Likelihoods]] into an [[Feed-Forward Neural Network|FNN]]

> [!warning] They sample their attackers a bit.. questionably.

## Likelihoods chosen
1. $p(F_{i})$
2. $p(F_{i}|u, \mathcal{L})$
3. $p(u | \mathcal{L})$
4. $p(u| \mathcal{A})$ (which they actually calculate, )

### Features used
they use the same ones as [[RBA per Freeman#Wiefling|Wiefling]] for backward compatibility pretty much:
1. IP
2. ASN
3. Country
4. UAS
5. Browser
6. OS
7. Device Type

## Network Architecture
- [[Hidden Layer|Hidden Layers]]: 5
- [[Neuron|Neurons]] per HL: 48
- Input [[Neuron|Neurons]]: $16$ (checks out: $|\set{p(F_{i}),\,p(F_{i}|u, \mathcal{L})}| \cdot 7\ \text{features} + 2 = 16$ )
- [[Activation Function]]: Leaky [[Activation Function#Rectified Linear Unit (RELU)|RELU]]
	- output layer: [[Sigmoid]] (=> scores normed to $[0, 1]$)
## Training
[[Training eines Neural Network]]
- 80/20 split (how? random? they only say "manually")
- max 100 [[Epoch]]
	- [[Regularisierung DNN|Early stopping]] afer 10 epochs (_validation_ loss)
- [[Loss]]: [[Binary Cross Entropy]]
	- i guess this is accounted for by roughly 50/50 sampling between attacks and legits; could try weighing or [[Focal Loss]] at least
- Optimizer: [[Adaptive Moment Estimation|Adam]]

> [!warning]- For finding the optimal [[#Network Architecture]], they used [[Stratification|stratisfied]] [[K-fache Kreuzvalidierung|k-fold cross-validation]] with $k = 5$
> stratisfied _probably_ by (very targeted) attackers


> [!question] When/how do I calculate the likelihoods?
> - in deployment, easy
> - but training?
> - I guess I have to recalculate likelihoods for every event in the training data and add them as columns 🥲 \#numpyisblackmagic

