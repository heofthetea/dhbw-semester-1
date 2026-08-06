> Misst, wie gut zwei Klassen voneinander getrennt sind

[[Entropie]]



$$\phi(\omega, \hat{\omega}) = - \omega\cdot \log_{2}(\hat{\omega}) - (1-\omega)\cdot \log_{2}(1-\hat{\omega})$$
=> basically exponentially punishes wrong classifications

| $\omega$   | $\hat{\omega}$ | $\phi(\omega, \hat{\omega})$ |
| ---------- | -------------- | ---------------------------- |
| 0          | -> 0           | $\rightarrow - \infty$       |
| 0          | -> 1           | $\rightarrow \infty$         |
| 0 $\lor$ 1 | 0.5            | 1                            |
| 1          | -> 0           | $\rightarrow \infty$         |
| 1          | -> 1           | $\rightarrow - \infty$       |
![[Pasted image 20260729163111.png]]


> [!warning]- Poorly suited for imbalanced problems
> Every point is considered equally; A classifier yielding always $\hat{\omega} = 0$ can achieve good results (almost like [[Accuracy]])

