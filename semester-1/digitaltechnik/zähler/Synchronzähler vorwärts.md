> 4-bit binärer Vorwärtszähler

![[synchronzaehler_binary.png]]
- Information wird mit absteigender Flanke aufgenommen, und mit ansteigender weitergegeben

Erstes Flipflop ist ein [[T-Flipflop (Toggle-FF)]] (makes sense - kleinste Stelle toggled)

### Funktionsweise
- Jeder Flip-Flop liegt auf Speicherfall, außer beide seiner Anschlüsse liegen auf 1
	- Beide Anschlüsse auf 1: _niederwertige_ Stelligkeiten liegen alle auf 1

![[zeitablaufdiagramm_vorwaehrtszaehler_synchron.png]]
> Flip-Flops sind asynchron bzgl. der Clock, aber _synchron_ zueinander

- Informationsweitergabe verschiebt sich zwar durch Signallaufzeit
	- _aber_: Taktsignale sind synchron
- _Signallaufzeit ist wichtig_: Bei _erstem Takt_ bleibt $Q_{I}$ kurz auf 0
	- ermöglicht, dass Momentsaufnahme nach n Takten akkurat ist
