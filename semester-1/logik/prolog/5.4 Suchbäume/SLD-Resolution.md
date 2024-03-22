- _Selective_: Wähle nächstes Literal (In Prolog: zuletzt eingeführtes)
- _Linear_: Erste Elternklausel ist zuletzt erzeugte [[Zielklausel]]
	- Fange an mit _Anfangsklausel_
	- Wenn Resolution funktioniert: mach mit erhaltener Zielklausel weiter
- _Definite clause_: Zweite Elternklausel ist [[Definite Klausel]]

## Vorteile
- weniger [[Unifikation|Unifikationen]] benötigt
	- nur gewähltes Literal mit Köpfen der  [[Definite Klausel|definiten Klauseln]]
- weniger _erzeugte_ Klauseln: Nur _eine_ Resolvente pro Klausel der [[Anfrage]]

## Methode
- Lege Atome ([[Goal|Goals]]) der [[Anfrage]] auf [[Stack]]
- unifiziere oberstes [[Goal]] $G$ mit allen Regelköpfen
- wenn erfolgreich: ersetze $G$ durch Regelrumpf (evt. mehrere Möglichkeiten)
- wenn [[Stack]] leer:
	- Anfrageklausel ist _unerfüllbar_ bzgl. [[Wissensbank]]
	 ==> return Variablenbindungen

### Pseudo-Code
![[sld_resolution_pseudo.png]]
- _Verzweigungspunkt_: Relevant für backtracking - Hier wird ein anderer Weg gewählt, wenn eine Verzweigung ins Leere läuft
- diese _while_-Schleife kann nie leer werden
	--> Endlos-Schleife
- Reihenfolge in [[Wissensbank]] ist wichtig!!

## Beispiel
![[Beispiel SLD-Resolution]]