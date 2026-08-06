- wieder [[gerichteter Graph]] ([[Category]])
- [[Relation]] sind [[Knoten]]
- [[Variable|Variablen]] sind [[Kante|Kanten]]

![[Pasted image 20260223104510.png]]
## Primal Graph (für [[Executable|Binary]] Constraint)
- $CSP$ ist ein [[Constraint Satisfaction Problem]]:
	- $X = \set{X_{1}, ..., X_{n}}$ sind [[Variable|Variablen]]
	- $D_{i}$ sind die [[Trägermenge|Domänen]]
	- $C = \set{C_{1}, ..., C_{m}}$ sind die Constraints

Der Constraint Graph ist ein [[ungerichteter Graph]] $G = (V, E)$ sodass:
- $V = X$ (jede [[Variable]] ist ein [[Knoten]])
- $(X_{i}, X_{j}) \in E$ iff there exists a Constraint $C_{k} \in C$ that involves $X_{i}$ and $X_{j}$


## Bipartiter Graph
- je eine [[Knoten]]-[[Menge]] für [[Variable|Variablen]] und [[Nebenbedingung|Constraints]]
- Eine [[Kante]] erbindet eine [[Variable]] $X_{i}$ mit einem [[Nebenbedingung|Constraint]] $C_{i}$ iff $X_{i}$ in $C_{i}$ involviert ist