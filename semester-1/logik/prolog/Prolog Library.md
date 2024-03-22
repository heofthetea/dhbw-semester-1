#library
## Architektur
[[Master Prolog 5.1 Intro]]

- [[Declarative Programming Language]]: beschreibt was _ist_, nicht, _wie_ 
- Wesentliche Bestandteile:
	- [[Wissensbank]] - beschreibt _Fakten_
		- [[Wissensbank]] wird in der Prolog Datei beschreiben
	- [[Prolog Interpreter]] - dynamisches User Interface. Vergleicht [[Anfrage|Prompts]] mit den Fakten derr Wissensbank.
- [[Closed World Assumption]]: Fakt ist _nur_ $true$, wenn er zweifelsfrei aus [[Wissensbank]] folgt
	- $f \rightarrow f \in KB$  
	- _Kontraposition_: [[Negation as Failure]]: Was _nicht_ aus [[Wissensbank]] folgt, ist _falsch_
		- $f\not\in KB \rightarrow \lnot f$  
## Syntax
[[Master Prolog Syntax]]
### Naming Conventions
- [[Variable]]: beginnt mit _Großbuchstabe_ oder _Underscore_
- [[Atom|Atom (= Konstante)]]: beginnt mit Kleinbuchstabe, _oder_ ist wrapped in _single quotes_
- [[Komplexer Term]]: Aufgebaut wie _Funktion_ in anderen Programmiersprachen:
	- Signatur aus _Name_ und _Parametern_
	- gibt entweder $true$  oder $false$ zurück
	- `term_name/n` gibt _Stelligkeit_ für Term an
- Jedes Statement wird abgeschlossen mit einem _Punkt_ (`.`) --> vergl. Semikolon in C

### Bausteine
- Besteht im Wesentllichen aus [[Regeln (Rules)]]
	- [[Regeln (Rules)|Regeln]] sind aufgeteilt in [[Goal|Goals]]
		- Dabei steht immer _links_ genau _ein_ [[Goal]] (genannt _Head_), und _rechts_ (genannt _Body_) stehen beliebig viele _Kindgoals_
			- Syntax: `head :- body.`
				- gesprochen: "head _if_ body" --> funktioniert wie _Subjunktion_, aber umgekehrt
			- _Child Goals_ können mit `,` [[Regeln (Rules)#Konjunktion im Rumpf|konjugiert]]  und mit `;` [[Regeln (Rules)#Disjunktion im Rumpf|disjugiert]] werden
	- [[Goal|Goals]] können $true$ oder $false$ sein
		- bestehen aus [[Komplexer Term|komplexen Termen]] 
			- ein [[Komplexer Term]] besteht aus mehreren [[Term|regulären Termen]]
			- in einem [[Komplexer Term|komplexen Term]] ist stets der _äußerste_ Funktor (respective "_Funktionssymbol_") das [[Prädikat]]
#### Besondere Prädikate
[[Master Prolog 5.3 built-ins]]

[[Besondere Prädikate]]: sind in built-into Prolog
- [[Unifikation]]: `=/2`
	- Überprüft, ob es einen _Unifikator_ gibt, der zwei Terme _gleich_ macht
		- Gibt diesen Unifikator an, oder $false$ wenn es keinen gibt
	- **ACHTUNG!**: kein Occurs-Check: $X \rightarrow f(X)$ ist _valide_ Abbildung!
- [[Gleichheit]]: `==/2`
	- Überprüft, ob zwei Terme bereits gleich _sind_ --> Führt _keine_ [[Unifikation]] durch
	- Berücksichtigt _zuvor_ getätigte Variablenbindungen durch [[Unifikation]]
	- Hauptsächlich relevant für [[Ganzzahl-Arithmetik]]
		- [[Gleichheit]]

##### [[Ganzzahl-Arithmetik]]
- Arbeitet mit [[Zahl|Zahlen]]
- Unterstützt [[Ganzzahl-Arithmetik#Integer-Operationen|Rechenregeln]] $\set{+,-,div,mod}$ sowie Punkt-vor-Strich und Klammern
- [[Ganzzahl-Arithmetik#Gleichheit|Variablenzuweisung]] wird mit `is` bezeichnet
	- Bindet [[Variable]] auf _linker Seite_ an _Ergebnis_ der rechten Seite
	- Unterschied zu anderen Programmiersprachen: Variable _bleibt_ gebunden!!!
		- Ausnahme: [[Anonyme Variable]]
- [[Vergleichsprädikate]]: 
	- Vergleichen _zwei_ [[Ganzzahl-Arithmetik|arithmetische Ausdrücke]] miteinander
	- Hierbei wird _keine_ Variable gebunden!!

## Suchbäume
[[Master Prolog 5.4 Suchbäume]]
### Horn-Formeln
- [[Horn-Formel]] ist eine logische Formel der Form $R_{1}\land R_{2} \land ... \land R_{n} \rightarrow K$
	- [[Horn-Formel|Horn-Klausel]] ist diese Form in KNF, geschrieben als Klausel $\{\lnot R_{1},\ \lnot R_{2},\ ... ,\ \lnot R_{n},\ K\}$ 
- [[Definite Klausel]] besitzt genau _ein_ positives Atom
	- [[Regeln (Rules)]] nur negierte [[Term|Atome]]
	- [[Wissensbank|Fakt]] nur positive [[Term|Atome]] 
- [[Zielklausel]] besitzt _kein_ positives Atom
- [[Ohne Fakten in der Wissensbank kann es nur falsche oder nicht terminierende Resolutionen geben]]

### SLD-Resolution
[[SLD-Resolution]]

- Optimierte Herangehensweise an gewöhnliches Resolutionsverfahren
- Stellt Resolution als _Baumstruktur_ aus Klauseln da
- steht für **S**elective-**L**inear-**D**efinite Clause
- Vorteile:
	- Insgesamt müssen weniger [[Unifikation|Unifikationen]] durchgeführt werden
	- erzeugt weniger Klauseln

#### SLD-Resolution in Prolog
[[Beispiel SLD-Resolution]]
###### Vorgehen
- Alle [[Goal|Goals]] der [[Anfrage]] sind negiert --> _Anfrageklausel_
- _Fakten_ werden in der Reihenfolge behandelt, in der sie in der [[Wissensbank]] stehen
	- Reihenfolge ist wichtig!!! (s. [[Suchbaum]])

1. Lege [[Goal|Goals]] der [[Anfrage]] auf [[Stack]] $S$
2. [[Unifikation|Unifiziere]] _oberstes_ [[Goal]] $G$ mit allen _Regelköpfen_ in [[Wissensbank]]
3. wenn [[Unifikation]] erfolgreich:
	1. Entferne $G$ aus dem [[Stack]] $S$
	2. Push alle _Regelrümpfe_ aus der [[Unifikation]] auf $S$
4. Wenn $S$ leer ist: _Anfrageklausel_ ist unerfüllbar bzgl. der [[Wissensbank]]
	==> Die [[Anfrage]] ist erfüllbar

---
## Rekursion
[[Master Prolog 5.5 Rekursion]]
 - Ein [[Prädikat]] $P$ ist [[Rekursive Prädikate|rekursiv]], wenn sein _Body_ einen Aufruf zu $P$ enthält
 - Ohne [[Rekursive Prädikate|Rekursion]] wäre Prolog nicht _turing-complete_
 - Im [[Beispiel SLD-Resolution|Suchbaum]] werden die _Parameter_ des [[Rekursive Prädikate|Rekursiven Prädikats]] in jeder Iteration _umbenannt_ 
	 - dies vermeidet eine "sperrende" Belegung durch einen vorherigen Aufruf
 - [[Endlosschleife|Endlosschleifen]] entstehen, wenn die [[Unifikation]] eines [[Rekursive Prädikate|Rekursiven Prädikats]] mit sich selbst einen _Kreis_ erzeugen kann
	 - _Bsp_: `married(X,Y) :- married(Y,X).`
		 - hier kann stets `X` auf `Y` abgebildet werden und umgekehrt, und damit der _rekursive_ Aufruf erfolgen
		 - Das Programm _kann_ nur terminieren, wenn eine spezifische Belegung von`X` und `Y` bereits als [[Basisklausel]] in der [[Wissensbank]] steht (z.B. `married(Anke, Andreas).`)

- Durch [[Best-Practices Rekursion]] wird sichergestellt, dass [[Endlosschleife|Endlosschleifen]] _erst_ auftreten, _nachdem_ der [[Prolog Interpreter|Interpreter]] bereits alle möglichen _Fakten_ berücksichtigt hat
	- Stets alle [[Basisklausel|Basisklauseln]] _vor_ das [[Rekursive Prädikate|Rekursive Prädikat]] schreiben
	- Prädikate [[tail-rekursiv]] schreiben

### Cut
- [[Prädikat ! (Cut)]] schneidet alle direkt vorangegangenen Verzweigungspunkte ab

---
## Listen
[[Hub Prolog 5.6 Listen]]
- [[Alles ist Liste]]: [[Liste|Listen]] sind universelle Datenstruktur (Objekt, Liste, Vektor, etc)
- Besondere Liste: [[Leere Liste]] 
	- [[Basisklausel]] einer [[Rekursive Prädikate|rekursiven Operation]] auf [[Liste|Listen]] besitzt immer aus einer [[Leere Liste|Leeren Liste]] als Argument
- _Notationsformen_:
	- [[Liste#Head|Head]]-[[Liste#Tail|Tail]]-Notation: `[H | T]` --> Hierbei ist `H` ein _beliebiger_ [[Term]], `T` eine [[Liste]]
	- "normale" Form: Wie in _python_ `[a, b, c, ...]`
	- _Mix_ aus beiden ist Möglich:
		- `[1, 2 | T ]
		- `[H | [b, c, d]]`
- [[Liste|Listen]] können wie in anderen Programmiersprachen [[Verschachtelte Liste|verschachtelt]] werden (Beispiel siehe [[Übung 5.69 Zebra]])


### Arbeiten mit Listen
> Allgemeines Prinzip: [[Rekursive Prädikate]], mit [[Basisklausel]] die [[Leere Liste]] behandeln.

Beispiele: [[Übung Palindrom]], [[Übung 5.66 Prädikat twice]]
#### Built-in Prädikate
- [[Prädikat Member]]: `member/2`: returns $true$, wenn $A \in B$
- [[Prädikat length]]: `length/2`: returns $true$, wenn _Argument_ für Länge mit der _Länge_ der Liste unifizierbar ist
- [[Prädikat append]]: `append/3`: returns $true$, wenn `A.append(B) = C` gilt
- [[Prädikat prefix]]: `prefix/2`: returns $true$, wenn $A$ ein Präfix von $C$ ist gilt