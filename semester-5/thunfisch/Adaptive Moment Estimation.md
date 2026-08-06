---
aliases:
  - Adam
---
 to > Variation of [[Gradient Descent]] adapting the Learning Rate

- due to adaptability doesn't require a lot of [[Hyperparameter]] optimization
- combines RMSProp and Momentum (see https://www.geeksforgeeks.org/deep-learning/adam-optimizer/)


### First Moment
This is the Momentum formula:
$$\vec{m}_{t}= \beta_{1}\vec{m}_{t-1} + (1 - \beta_{1})\frac{\partial L}{\partial w_{t}}$$
$$\vec{m}_{0} = \vec{0}$$
- Momentum basically controls the step size for the descet, based on a moving weighted average of past gradients

> [!hint] The weighted average becomes apparent when unwrapping the series; All information up until $\vec{m}_{0}$ is contained in $\vec{m}_{t-1}$

> [!hint] Note that $L = MSE(w_t)$ -> we're [[Ableitung|deriving]] the [[Loss|Loss function]],
### Second Moment
This is the formula for RMSProp. 
The vector $\vec{v}_{t}$ basically keeps track of past descents for every individual weight.

$$\vec{v}_{t} = \beta_{2}\vec{v}_{t-1} + (1 - \beta_{2})\left(\frac{\partial L}{\partial w_{t}}\right)$$
$$\vec{v}_{0} = \vec{0}$$

### Bias Correction
- both $m_{t}$ and $v_{t}$ are corrected for their [[Bias]] towards $0$ using the following formulas:

$$\hat{m_t} = \frac{m_t}{1 - \beta_1^t}, \quad \hat{v_t} = \frac{v_t}{1 - \beta_2^t}$$
### Updating weights for next iteration:
$$w_{t+1} = w_{t} - \alpha\left(\frac{\hat{m_{t}}}{\sqrt{\hat{v_t}}+\epsilon}\right)$$

