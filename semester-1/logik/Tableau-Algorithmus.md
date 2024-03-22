> Testet logische Formel auf Erfüllbarkeit
> Liefert ein [[Modell]] $M \models \varphi$, wenn kein Clash erzeugt wurde

## Verfahren
 1. Formel in [[NNF]]
 2. Tableau durchführen
	 1. Work depth-first
	 2. Heuristiken für Reihenfolge:
		1. [[⋀ Regel]]
		2. [[∃ Regel]]
		3. [[⋁ Regel]]
		4. [[∀ Regel]] 
3. enthält jede Spalte einen [[Clash]]:
	1. $\varphi$ ist _unerfüllbar_
4. Ist auf einem Pfad keine Regel mehr anwendbar:
		1. Suche [[Unifikation|Unifikationen]], und Belegungen, die auf [[Clash]]-freiem Pfad liegen
