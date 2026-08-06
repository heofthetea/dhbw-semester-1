> [[gerichteter Graph]] der [[Zeitlogik]]

#todo Beispiel

- jede [[Kante]] ist eine [[Menge]] aus Zeitlichen [[Relation]]
- Kanten können "falsch herum" sein -> Durch Invertieren (e.g. $d \mapsto di$) kann die [[Kante]] umgedreht werden
	- Muss gemacht werden, um [[transitiv]] [[Schlussfolgerungstabelle Zeitlogik|folgern]] zu können (vgl. [[Composition]])
## Konsistenzüberwachung
[[Konsistenzüberwachung]]

> [!warning] ist [[NP-Vollständigkeit|NP-Vollständig]]

1. Bilde [[Composition]] für alle [[Relation|Relationen]]
2. für jede zwei [[Relation|Relationen]]: Schlussfolgere mithilfe von [[Schlussfolgerungstabelle Zeitlogik]]
	1. Wenn [[Operationen auf Mengen#Intersection|Schnittmenge]] existiert -> diese Kanten sind konsistent
	2. Elemente der [[Composition]], die nicht in der Folgerung sind, rausstreichen
3. Repeat bis in einem Durchgang durch alle Kanten nichts gestrichen wurde

> [!warning] Falls gestrichen wurde, muss die [[Kante]] nochmal auf Konsistenz überprüft werden !!!!!
### Schlussfolgern mit [[Menge|Mengen]]
$$C\set{m, o, d}A\set{<, >}B$$

$$\set{\gt, \lt} \circ \set{m, o, d} = p(>, m) \cup p(>, o) \cup p(>, d) \cup ...$$

> [!hint] $p^{(2)}$ ist [[Schlussfolgerungstabelle Zeitlogik]]



