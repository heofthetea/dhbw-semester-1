Gegeben sei eine _kubische Gleichung_ der Form $x^{3}+ bx^{2}+ cx + d = 0$.

1. _Substitution_ $x = y - \frac{b}{3}$ [^1]
	1. Gleichung liegt nun in _Standard-Form_ vor: $y^{3} + py + q = 0$
		mit $p = c - \frac{b^{2}}{3}$ und $q = \frac{2}{27}b^{3} - \frac{1}{3}bc + d$ 
2. _Berechne_ Determinante $\Delta$ mit $\Delta := (\frac{p}{3})^{3} + (\frac{q}{2})^2$ 
3. Unterscheide zwischen _drei Fällen_:
	1. $\Delta > 0$: 1 reelle Lösung
		1. $y_{1}= \sqrt[3]{\sqrt{\Delta} - \frac{q}{2}} -\sqrt[3]{\sqrt{\Delta} + \frac{q}{2}}$ 
	2. $\Delta = 0$: 2 reelle Lösungen
		1. $y_{1} = \frac{3q}{p}$
		2. $y_{2} = y_{3} = -\frac{3q}{2p}$
	3. $\Delta < 0$: 3 reelle Lösungen
		1. Berechne $\varphi = \frac{1}{3}arccos(-\frac{q}{2}\sqrt{\frac{27}{|p|^{3}}})$
		2. $y_{1} = 2\sqrt{\frac{|p|}{3}}cos(\varphi)$ 
		3. $y_{2/3}$ = $-2\sqrt{\frac{|p|}{3}} cos(\varphi \ \pm \frac{\pi}{3})$ 
4. _Resubstititution_ mit $x = y + \frac{b}{3}$ nicht vergessen!!

[^1]: Für Substitutionen wird hier stets direkt angegeben, wie _resubstituiert_ wird.


### tipps
- $\varphi$ auf mindestens 4 Nachkommastellen runden!!(mitsamt `[...] -> x` in WTR)