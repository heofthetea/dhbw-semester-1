> Kontrolliert, wann ein [[Neuron]] feuert

[[Abbildung|Funktion]], [[Diskriminanzfunktion]]

- Aufgabe: Nichtlinearität in ein [[Neural Network]] bringen
	- Summe ($a$ im Bild) ist Äquivalent einer [[Diskriminanzfunktion|Linearen Diskriminanzfunktion]]
- $w_{0}$ ist der Bias


> [!hint] Das Input-Layer hat keine Activation Function (gibt einfach Merkmale weiter)

![[Pasted image 20251205112021.png]]

### Anforderungen:
- Nichtlinearität
- [[Differenzenquotient|Differenzierbarkeit]] (für [[Gradient Descent]] etc)
- einfach zu Berechnen (niedrige [[Komplexität]])

> [!warning] Ohne Nichtlinearität wären die Hidden Layer eigentlich komplett ntuzlos - man könnte direkt die Output-Neuronen trainieen.
> Nichtlineare zusammenhänge könnten dann gar nicht gelernt werden


## Arten
### Lineare Aktivierung
- useless - außer im Output layer

### Sprungfunktion
- Im Prinzip harter Schwellwert
![[Pasted image 20251205112521.png]]

> [!warning] für $a = 0$ ist die undefiniert lel


### Sigmoid
- Normiert den Output zwischen $0$ und $1$
![[Pasted image 20251205112607.png]]

### Tangens hyperbolicus
![[Pasted image 20251205112642.png]]

### Rectified Linear Unit (RELU)
- mittlerweile mit die beliebtesten
> [!hint] Entspricht dem Verhalten einer Diode -> direkt in Hardware übersetzbar

$$\phi(a) = \text{max}(0, a)$$

![[Pasted image 20251205112709.png]]

#### Abwandlungen
- Parametric/Leaky ReLU (Steigung für $\lt 0$)
- [[Exponentialfunktion|exponential]] ReLU

### Softmax
- für Output Layer in einem $c \gt 2$-[[Klasse|Klassen]] Problem
	- Suche das wofür die maximal ist

![[Pasted image 20251205113057.png]]