> entfernt _Verzweigungspunkte_, die _nach_ dem Aufruf des Eltern-[[Goal|Goals]] angelegt wurden
> Alternative Unifikationen mit demselben Prädikat werden unterbunden.

> [!Warning]
> _Nicht_ äquivalent zu `return`.!!!

- [[Elterngoal und Subgoal]]
- nullstellig
- ist _immer_ successful

_Ist ein procedural Command, nicht deklarativ_
- ermöglicht neu Programmkonstrukte (Negation)
### Funktion
- kein Backtracking _vor_ den Cut
- bestehende Variablenbindungen werden fixiert
- keine alternativen [[Unifikation]]
- keine alternativen Klauseln zur _Erfüllung_ eines [[Goal|Goals]]

#### Graphisch
![[Pasted image 20240206142200.png|400]]
- beachte: nur Pfade des _Elterngoals_ werden weggestrichen
	- Pfade weiter oben im Baum werden weiter durchsucht!!






