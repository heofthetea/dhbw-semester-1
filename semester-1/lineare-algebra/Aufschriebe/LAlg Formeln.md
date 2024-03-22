[[Cardanische Formel]]

## Zahlentheorie
- Kleiner Satz von Fermat: $a^{n} =_{n}a$ 
## New shit
- $pq$-Form MNF:
	- $x^{2} + px + q = 0$, dann ist $x_{1, 2} = \frac{p}{2} \pm \sqrt{(\frac{p}{2})^{2}-q}$   

## Geometrie

- _Abstand Punkt/Gerade_ : $d(\textbf{q}, g) = ||\textbf{u} \times (\textbf{q} - \textbf {p})||$ , where $g = \textbf{p} \cdot t\textbf{u}$ with $||\textbf{u}|| = 1$  
- _Tangentialebene_: $T = \{x \in \mathbb{R}^{3}\ |\ \langle \textbf{x} - \textbf{m}|\textbf{p} - \textbf{m} \rangle\}$ ,where m ist Mittelpunkt der Kugel K, und p der Schnittpunkt von T mit K
- _Radian to Degree_: (Dreisatz) $\frac{\alpha}{2\pi} \cdot 360\degree$ 
- _Orthogonalbasis_: 
	- gegeben seinen zwei _nicht parallele_ Vektoren $a, b \in \mathbb{R}^3$ 
	- dann ist $B := \set{\textbf{a},\ ||\textbf{a}||^{2}\textbf{b} - \langle {\textbf{a}|\textbf{b}\rangle\textbf{a}},\ \textbf{a} \times \textbf{b}}$ eine Menge _paarweise orthogonaler_ Vektoren
	- Vektoren aus $B$ normieren für Ortho*normal*basis

### Matrizen
- mit einem Vektor: $A^{-1} = \frac{1}{det(A)} [a_{2} \times a_{3}, a_{3} \times a_{1}, a_{1} \times a_{2}]$ 


## Trigonometrie
##### Additionssätze
$sin(\alpha + \beta) = sin(\alpha)cos(\beta) + sin(\beta)cos(\alpha)$
$cos(\alpha + \beta) = cos(\alpha)cos(\beta) - sin(\alpha)sin(\beta)$

## Komplexe Zahlen
- _Polardarstellung_: $z = |z| \cdot (cos(\alpha) + i \cdot sin(\alpha))$ (first cosine, then sine)
	- _Multiplikation_: $z \cdot w = |zw| \cdot (cos(\alpha + \beta) + i \cdot sin(\alpha + \beta))$ 
		- --> Es folgt _Division_: $z \cdot w = \frac{|z|}{|w|} \cdot (cos(\alpha - \beta) + i \cdot sin(\alpha - \beta))$
	- _Potenzierung:_ $z^{n}= |z|^{n} \cdot (cos(n\alpha) + i \cdot sin(n\alpha))$ 
- $w_{1}= (z)^{\frac{1}{2}} = \sqrt{\frac{1}{2}(|z| + a)} + \nu(b)i \cdot \sqrt{\frac{1}{2}(|z| - a)}$, mit $\nu(b)$ = "Vorzeichen von b" 
	- $w_{2} = - w_{1}$ 
- Darstellung $sin$ und $cos$:
	- $Re(z) = cos(\alpha) = \frac{1}{2}(e^{i\alpha} + e^{-i\alpha})$ 
	- $Im(z) = sin(\alpha) = \frac{1}{2i}(e^{i\alpha} + e ^{-i\alpha})$ 

