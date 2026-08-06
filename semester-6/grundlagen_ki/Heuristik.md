- für **optimale** Lösung: Heuristik muss immer unterschätzen (zulässig sein)
	- -> konsistent?

## Zulässige Heuristik
- die [[Heuristik]] überschätzt das tatsächlich beste Resultat nie

$$\forall_{v}\ h(v) \leq h^{*}(v)$$

## Konsistente Heuristik
- das ding muss gegeben sein:

$$\forall_{v, v'}\quad h(v) \leq c(v, v') + h(v')$$

![[Pasted image 20260309102705.png]]


## Dominanz
Eine zulässige [[Heuristik]] $h_{1}$ dominiert eine weitere zulässige [[Heuristik]] $h_{2}$, wenn $h_{1}$ mehr Information liefert als $h_{2}$.