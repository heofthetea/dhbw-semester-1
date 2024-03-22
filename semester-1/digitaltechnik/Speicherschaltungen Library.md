#library 
## Flipflops
[[Master Flipflops]]
- _Grundprinzip_ eines [[Flipflops]]: $Q_{2} = \lnot Q_{1}$
	- erlaubt maximal zwei Operationen: _Set_ und _Reset_
	- somit nur Ausgang $Q_{1}$ betrachtet
- [[Speicherfall]]: $Q_{1n} = Q_{1(n - 1)}$ 
- [[Verbotener Fall]]: Dieses Grundprinzip liegt nicht vor
- [[Taktsteuerung]]: Takt kontrolliert, ob [[Flipflops|Flipflop]] angesteuert werden kann oder in [[Speicherfall]] bleibt
	- _statisch_: Flipflop reagiert auf _Wert_ des Taktes
	- _dynamisch_: Flipflop reagiert auf _Flanke_ (= Veränderung im Wert) des Taktes
- [[Zweiflankengesteuertes Flipflop|Zweiflankensteuerung]]: Information wird mit _ansteigender_ Flanke aufgenommen, und mit _abfallender_ Flanke weiter gegeben
- [[Charakteristische Gleichungen]] beschreiben die Funktionsweise eines [[Flipflops]] durch Boolesche Funktion
	- [[Liste an Charakteristischen Gleichungen]]

### Arten von Flipflops
- [[SR-Flipflop]] und [[Taktgesteuertes SR-Flipflop]]
- [[JK-Flipflop]] und [[Zweiflankengesteuertes JK-FF]] (Master-Slave-Aufbau)
- [[T-Flipflop (Toggle-FF)]]
- [[D-Flipflop (Delay-FF)]] und [[DV-Flipflop]]

---
## Zähler
[[Master Zähler]]
- [[Taktsteuerung]]
- _Prinzip_: Output gibt wieder, wie oft sich ein Eingangsimpuls verändert hat
- Ausgänge der [[Flipflops]] repräsentieren Wertigkeit der gezählten Binärzahl
	- je _niedriger_ der Index, desto _niedriger_ die Stelligkeit 
		($Q_{I}$ = $2^{0}$, $Q_{II}$ = $2^{1}$, etc)
- Wenn eine Gewisse Grenze erreicht wird, werden Flipflops _zurückgesetzt_ 
#### Unterschiedene Kategorien
|  | asynchron | synchron |
| ---- | ---- | ---- |
| vorwärts | [[Asynchronzähler vorwärts]] | [[Synchronzähler vorwärts]] |
| rückwärts | [[Asynchronzähler rückwärts]] | [[Synchronzähler rückwärts]] |
|  |  |  |
| BCD | [[BCD Asynchronzähler]] | [[BCD Synchronzähler Berechnung]] |
### Asynchronzähler
[[Asynchronzähler]]: Flipflops sind _asynchron_ bzgl. des [[Taktsteuerung|Taktes]]
- Realisierbar mit [[JK-Flipflop]] und [[T-Flipflop (Toggle-FF)]]
- _Prinzip_: Ausgang $Q_A$ des Flipflops $A$ wird direkt an Takt-Eingang des nächsten Flipflops $B$ angeschlossen
- _Problem_: Durch Signallaufzeit wird Information ggf. nicht _vor nächstem Takt_ am letzten Flipflop ankommen

### Synchronzähler
[[Synchronzähler]]: Flipflops sind _synchron_ bzgl. des[[Taktsteuerung|Taktes]]
- _nur_ noch mit [[Zweiflankengesteuertes JK-FF|Master-Slave JK-FF]] realisierbar
	- Funktion basiert darauf, dass _Signallaufzeit_ des Flipflops ein signal _lange genug_ verzögert, dass nachfolgende Flipflops bei Taktsignal reagieren können, bevor geupdated wird
- _Prinzip_: Alle Takteingänge werden _parallel_ angesteuert
#### Berechnung
- Schaltungen für [[Synchronzähler]] können [[Berechnung von Synchronzählung|berechnet]] werden
	- [[Berechnung von Synchronzählung|Vorgehen]]:
		1. Wahrheitstabelle aufstellen
		2. DNF bilden
			1. mit KV-Diagrammen vereinfachen
		3. [[Charakteristische Gleichungen]] der Flipflops aufstellen
		4. [[Berechnung von Synchronzählung#Beispiel#4. Koeffizientenvergleich|Koeffizientenvergleich]] ergibt Belegung der Eingänge $J$ und $K$
		5. WOHOOO SCHALTBILD (🤮)
	- **Achtung**: [[Bei Synchronzählerberechnung immer von Links nach Rechts arbeiten]]
- Beipiel: [[BCD Synchronzähler Berechnung]]
### Frequenzteiler
[[Frequenzteiler]]
- [[Jeder Zähler ist ein Frequenzteiler]]
- Die [[Frequenz am n-ten Flipflop]] eines [[Master Zähler|Zählers]] folgt der Regel $f_{n} = \frac{f_{E}}{2^{n}}$
- wenn [[Asynchroner Frequenzteiler]] in der Klausur dran kommt bin ich gearscht
	- immerhin kommen [[Synchroner Frequenzteiler | Synchrone Frequenzteiler]] garantiert nicht dran

---
## Auswahl- und Registerschaltungen
[[Master Digitale Auswahl- und Verbindungsschaltungen]]
### Datenselektoren
[[Datenselektor]]
- _input_: Mehrere Bits/Gruppen an Bits an Daten
- _output_: Eines der Daten im _input_, entschieden durch einen/mehrere _Steuereingänge_ $S$
- [[4-bit zu 1-bit Datenselektor]]: wählt ein bit aus 4 aus
- [[4-bit zu 4-bit Datenselektor]]: wählte eine von mehreren _4-bit Gruppen_ aus
- Anwendungsbeispiel: [[Adressdekodierer]]
#### Komparatorschaltungen
- vergleichen _binäre Inputs_ $\set{A, B}$ auf $\set{A < B, A == B, A > B}$ (repräsentiert durch Ausgänge $\set{X, Y, Z}$)
	- für jeden dieser Beziehungen ist ein Ausgang zuständig
- [[1-bit Komparator]] vergleicht zwei bits miteinander (kann aus Logikgattern aufgebaut werden)
	- [[1-bit Komparator mit Sperrschaltung]]: zusätzlicher Eingang $E$ (Enable): $E = 0 \Rightarrow X = Y = Z = 0$ 
- [[3-bit Komparator]]
	- "Human" Approach: Vergleiche Ziffern von größter bis niedrigster Stelligkeit (mit [[1-bit Komparator mit Sperrschaltung|1-bit Komparatoren]])

### Transmissionsschaltungen
- [[Multiplexer]]: sequenziert Bits aus input ("n zu 1 bit")
	- Beispiel: [[16-bit zu 1-bit Multiplexer]]
- [[Demultiplexer]]: parallelisiert Bits aus input ("1 zu n bit")
	- Umsetzung: [[Datenselektor]] mit _zeitabhängiger_ Beschaltung durch [[#Zähler]]
- [[BUS-Schaltung]] sendet Information von _Sender_ zu _Receiver_
	- _parallel_: Eine Leitung pro Bit
	- _seriell_: Anwendung von [[Multiplexer]] (als _Sender_) und [[Demultiplexer]] (als receiver))

### Registerschaltungen
#### [[Schieberegister]]
- aufgenommener _input_ wird von Flipflop zu Flipflop um Takt verzögert
	- Funktionsweise am Besten zu erkennen in [[Übung Schieberegister Zeitablaufdiagramm|Zeitablaufdiagramm]] 
- Aufbau using [[D-Flipflop (Delay-FF)]]
- [[Schieberegister mit serieller Ein- und Ausgabe]]
	- input wird vorne rein geworfen und kommt Zeitverzögert hinten wieder raus
- [[Schieberegister mit paralleler Ausgabe]]
	- input wird vorne reingeworfen, und an jedem Flipflop kann "Zwischenstand" abgelesen werden
- [[Schieberegister mit paralleler Ein- und Ausgabe]]
	- Flipflops können manuell ausgelesen und _gesetzt_ werden
- [[Speicherregister]] (nicht klausurrelevant)
	- Information wird einmal aufgenommen, aber nicht weiter verschoben
- [[Ringregister]]
	- Information vom Letzten Flipflop wird wieder vorne rein geschoben
