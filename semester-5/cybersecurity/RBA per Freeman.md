- [[Naive Bayes]]
- Uses [[Likelihood|Likelihoods]] estimated from the login history to calculate the Likelihood that the current login is valid

## Mathematical Foundations
### Simple Idea
[[Likelihood Ratio Test]]
$$LR = \frac{p(\mathcal{A}|u, \vec{F})}{p(\mathcal{L}|u, \vec{F})}$$
where:
- $\mathcal{V} = \set{\mathcal{A}, \mathcal{L}}$ is a [[Menge|Set]] [[Isomorphism|isomorphic]] to the [[Boolsche Menge|Boolean Set]], denoting whether the Validity of a Login is classified as legitimate ($\mathcal{L}$) or an attack ($\mathcal{A}$)
- $u$ is the [[User]] trying to log in
- $\vec{F}$ is a [[Vektor|Vector]] of [[Attribut|Features]] 

> [!error] Problem: There is far too little data to properly [[Schätzer|estimate]] these [[Likelihood|likelihoods]]

### Reformulated
- Freeman et al. reformulate this LR through some assumptions, most notably the [[Unabhängige Ereignisse|independence]] of individual Features
	- -> the [[Naive Bayes]] Assumption
	- => allows for the independent weighing of eachh feature

$$S_{u}(\vec{F})= \left(\prod\limits_{i=1}^{|\vec{F}|} p(\mathcal{A}|F_{i})^{\alpha_i}\frac{p(F_{i})^{\beta_i}}{p(F_{i}|u, \mathcal{L})^{\gamma_{i}}}\right)\frac{p(u|\mathcal{A})^\delta}{p(u|\mathcal{L})^{\epsilon}}$$
where:
- $[\alpha, \beta, \gamma]$ is a $|\vec{F}|\times 3$ [[Matrix]] of Weighing Coefficients for each subfeature
	- likewise, $\delta$ and $\epsilon$ are weighing coefficients for user Likelihoods
- $p(u|\mathcal{V})$ is the [[Likelihood]] of an attacker/legitimate login being the user $u$

### Wiefling
- wiefling drops $p(\mathcal{A}|\vec{F_{i}})$ from their calculations entirely (Rotter et al.).
	- they also don't _calculate_ $p(u|\mathcal{A})$
- also they don't leave Likelihoods as $0$, but perform [[Interpolation Smoothing]]
- also, from what I can see in the code, they use only one weight throughout _every_ feature, instead of individual weights; and don't weigh the user likelihoods


=> the formula actually used by Wiefling thus becomes:
$$S_{u}(\vec{F})= \left(\prod\limits_{i=1}^{|\vec{F}|} \left(\frac{p(F_{i})}{p(F_{ii}|u, \mathcal{L})}\right)^{w_{i}}\right)\frac{1}{|U| \cdot p(u|\mathcal{L})}$$


> [!hint] The reason for this is that in their original study (What's in score ...), they didn't collect attack data (wtv that means). However in Pump up..., they compared whether using Attack data makes a difference, and concluded that the model performed worse lol

#### Subfeatures
except... THAT'S NOT IT
THEY COMPLETELY VIOLATE THIS THING FURTHER BY INTRODUCING **SUBFEATUES** AS A FUCKING SUM
-> WHICH ESSENTIALLY MEANS THE BELOW BEHEMOTH CANNOT BE SIMPLIFIED FURTHER AT ALL

$$S_{u}(\vec{F})= \left(\prod\limits_{i=1}^{|\vec{F}|}\frac{\left(\sum\limits_{k}p(\vec{SF}_{ik})\cdot {w_{ik}}\right)^{w_{i}}}{\left(\sum\limits_{k}p(\vec{SF}_{ik}|u, \mathcal{L})\cdot {w_{ik}}\right)^{w_{i}}}\right)\frac{1}{|U| \cdot p(u|\mathcal{L})}$$
where
$$\sum\limits_{k}w_{ik} = w_{i}\quad ;\quad [SF_{i0},\, SF_{i1},\, \dots,\, SF_{i3}]^{t} = F_{i}$$
additionally, $p(\vec{SF}_{ik}|C)$ is not calculated as the simple [[Likelihood]] $\frac{|\set{c\in C\ |\ c[SF_{ik}] == SF_{ik}}|}{|C|}$, but rather as a whacky combination that I have no fucking clue of how to mathematically express that:

```python
likelihood_user_subfeature = likelihood(history_subfeature, feature, feature_value, smoothing=smoothing)
likelihood_subfeature = likelihood(history, feature, feature_value, smoothing=smoothing)

return likelihood_user_subfeature * likelihood_subfeature
```
## How is a decision made?
- it's certainly some kind of threshhold for $S_{u}(\vec{F})$

### Decision Wiefling
Wiefling et al. mention in What's in Score the follwing:

> For a fair comparison, we calibrated the risk score access thresholds of both RBA models. We adjusted regarding the percentage of blocked attacks in each attacker model, which we call the true positive rate (TPR), as in related work \[20].

Taken in context with their reauthentication rate plots, this can be taken as (see [[argmin]])
$$\operatorname*{arg\,min}_{\theta }(TPR - \theta_{TPR})$$
- where $\theta_{TPR}$ is the threshhold from the legend
- and $\theta$ is the access threshhold
![[Pasted image 20260721173952.png]]
=> when in doubt, pull [[Adaptive Moment Estimation|Adam]] out oder so

#### Dynamic Threshhold
In Pump up, Wiefling mentions that the risk scores decline with increasing history sizes. Based on collected data, they train [[Regression]] models:
1. A [[Linearregression|linear regression]]
2. A [[Polynom|polynomial]] regression
3. A hyprid of these
The models should predict the "closest" (wtv that means, probably mean/median) risk score for a legitimate login based on the login history size.

=> I'll ignore that haha

### Freeman
Freeman (whom Wiefling cited here as \[20]) doesn't _really_ talk about this, they just mention a hypothetical:
> The threshold $\theta$  can be generally adjusted on a validation set to balance the trade-off between the rate of misclassified legitimate logins (false positives, FP) and the attack detection rate (true positives, TP) 

and then later, in a different context, mention a [[Logistische Regression|logistic regression]]:

> we will assess the performance of our model against different types of attacks (either observed or simulated)  by computing the True Positive Rate (TPR, i.e., the fraction of correctly classified account-takeover attempts) at 10% False Positive Rate

