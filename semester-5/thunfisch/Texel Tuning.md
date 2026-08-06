- Paper by Ethereal: [[ethereal_tuning.pdf]]
- [[Regressatortraining]]

## High-Level approach
- from https://youtu.be/3JCWxH6IehQ?si=JiUYEmCz4CTAMGkl&t=3135

1. Evaluate position
2. [[#Mapping of Evaluation to Outcome]]
3. Calculate error of residuals: [[Mean Squared Error|MSE]]
4. 


## Mapping of Evaluation to Outcome
- use a [[Activation Function#Sigmoid|Sigmoid]]:

$$\sigma = \frac{1}{1 + e ^{-KE}}$$

> [!hint] That is the simplified sigmoid defined by Ethereal; Peter Österlund used a more convoluted one that used base 10

## [[Hyperparameter]] $K$
- K scales the [[Sigmoid]] based on the default-weighted Evaluation
- Optimized using [[Grid Search]]


# Thunfisch specific
## Estimation of runtime (ASSUMING WE WOULD CALCULATE GRADIENT ANALYTICALLY HAHAHA)
Locally on a 10-core mac, evaluating one batch of the training data takes ~250ms. (release mode).
We'll assume that the time scales anti-proportionally with the cores available; meaning a single core would take $250\text{ms} \cdot 10 = 2.5\text{s}$.
We have approximately 2000 weights in our eval at the time of writing.
Since we calculate derivatives numerically, we'll need to evaluate positions twice ($\vec{w_{t}} - \vec{\delta}$, $\vec{w_{t}} + \vec{\delta}$); meaning calculating the gradient of the Loss for one epoch costs us $0.5$ seconds.
**NOTE** that this assumes full batch-sizes; mini batching will reduce this significantly.

The formula for estimating how long tuning will take thus is somewhere along the following:

$$\frac{2.5}{c} \cdot e\ \text{seconds}$$

where:
- $c$ is the number of available CPU cores
- $e$ is the number of total epochs

Training with $4000$ Epochs on my local mac should take $1000\text{s} = 16\  \text{minutes}$.
Note that the more batches we introduce, the less efficiently we can use the cores, as we can only parallelize the gradient computations.