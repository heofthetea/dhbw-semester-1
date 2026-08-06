> [[Neural Network]]-based Chess Engine

- im Grunde: [[Monte Carlo Tree Search]]
	- was auch immer zum Fick das ist
- in jeder Position entscheidet ein [[Neural Network|NN]], was die vielversprechendsten Züge sind:
	- $(p, v)$ where $p$ is the [[Wahrscheinlichkeit|probability]] of this move being played, and $v$ the expected outcome (loss, draw, win)
- irgendwie sowas