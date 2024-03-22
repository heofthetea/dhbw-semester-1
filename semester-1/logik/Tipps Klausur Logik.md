- Variablenbelegung bei Unifikation _in globaler Scope_
- _kein_ [[Master Prolog|Prolog]] Programmentwurf
	- eventuell Fehlersuche / Erweitern
	- "custom Funktionen" nicht verwenden (bsp. [[Prädikat suffix]]) - wird vorgegeben in Klausur
- Bei Fragen "welche Antwort?":
	- _Fehler_ berücksichtigen!!
		- [[Endlosschleife|Endlosschleifen]] sind auch Fehlermeldungen (`out of local stack`)

[[Relationen sind eine Teilmenge der Produktmenge]]
[[Definitionen Logik]]
#### Formalisierung
> [!warning] _Junktoren_ binden stärker als _Klammern_

### Tableau
- _UND_ Regel: überprüfen, ob _alle_ erzeugten Terme bereits in Spalte sind
- _ODER_-Regel: überprüfen, ob _eins_ der erzeugten Terme bereits in Spalte ist
	--> wenn das der Fall ist: REGEL NICHT ANWENDBAR
	
- _Abschlusssatz_: "Jeder Pfad enthält einen Clash, deswegen ist $\varphi$ unerfüllbar."
- gegebenen Term _nicht_ vereinfachen !!!
- verschiedene Pfade sind unabhängig voneinander zu behandeln

![[Tableau-Algorithmus]]
- Wenn $\exists$ innerhalb Allquantor-Scope ist, _zuerst_ [[∀ Regel]] anwenden, um nicht komplex [[Skolemisierung|skolemisieren]] zu müssen

### Unifikation
- $\cdot //\cdot$ Syntax erklären
- ANGABE VON UNIFIKATOR REICHT!!!!
	==> es muss nicht jeder Schritt angegeben werden
	![[Pasted image 20240228165139.png]]

### Resolution
> [!warning] - Nicht Unifikation und Faktorisierung gleichzeitig machen
> - Für Unifikation nur die Abbildungen, die wirklich notwendig sind
- mit Einheitsklauseln ($\set{\lnot K(a)}$) arbeiten, um andere Klauseln kleiner zu machen!
- bereits generierte Klauseln verwenden!!!!

![[Pasted image 20240228165321.png]]

### Miniscoping
![[Pasted image 20240228163430.png]]

## Prolog Prädikate
---
### Suchbäume
- ist ein _Search Tree_ (ref. Info-LK)
	- Seiten sind Relevant: was _zuerst_ bearbeitet wird, ist linker Teilbaum
- Verzweigungspunkte einzeichnen, AUCH WENN NACH ERSTER ANTWORT AUFGEHÖRT WERDEN KANN!!!
- Immer nur _einen_ Schritt pro Verzweigung

### Prädikate
![[Vergleichsprädikate]]

![[Prädikat Member]]

![[Prädikat length]]

![[Prädikat append]]