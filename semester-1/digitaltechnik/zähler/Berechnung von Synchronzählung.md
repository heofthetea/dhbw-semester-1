## Vorgehen
1. Wahreitstabelle aufstellen
2. Anwendungsgleichungen (= [[DNF]]) aufstellen und vereinfachen
	1. Dabei _spaltenweise_ arbeiten (ouch)
3. [[Charakteristische Gleichungen]] der verwendeten Flip-Flops bestimmen
4. Verknüpfungsgleichungen durch Koeffizientenvergleich bestimmen
	- Nimm charakteristische Gleichung
	- Überlege: Wie muss ich J und K belegen, damit der Term rauskommt?
5. Schaltbild auf Basis der Verknüpfungsgleichungen zeichnen

---
> Übung: [[BCD Synchronzähler Berechnung]]
## Beispiel
anhand [[Synchronzähler vorwärts]]
#### 1. Warheitstabelle
- Herangehensweise:
	1. Links die Takte aufstellen (dezimal)
	2. rechts den _erwarteten_ Ausgangswert eintragen
	3. Danach Ausgänge belegen
		- geschieht wieder anhand der aufgeschriebenen Dezimalwerte lol
![[Wahrheitstabelle_binaer_synchronzaehler.png]]

#### 2. KNF aufstellen
- Direkt in KV-Diagramme eintragen lol
- Gewöhnung an Darstellung: _oben bei $Q_{An}$_ anfangen, dann _gegen den Uhrzeigersinn_

###### 2.1. $Q_A$ 
==> $Q_{A(n+1)} = \lnot Q_{An}$ 
![[KV_Qa.png]]


###### 2.2 $Q_B$
--> $Q_{B(n+1)} = [Q_{A}\lnot Q_{B} \lor \lnot Q_{A}Q_{B}]_n$
![[kv_Qb.png]]


###### 2.3 $Q_C$
_vereinfachte Form_: $Q_{C(n+1)} =$$[ Q_{A}Q_{B} \lnot Q_{C} \lor \lnot (Q_{A}Q_{B})Q_{C}]_{n}$  
![[KV_Qc.png]]
###### 2.4 $Q_{D}$ 
$Q_{D(n+1)} =[Q_{A}Q_{B}Q_{C} \lnot Q_{D} \lor \lnot (Q_{A}Q_{B}Q_{C})Q_{D}]_{n}$  
![[kv_Qd.png]]
- Ein _Kernprimimplikant_ --> 1, die in kein Päckchen packbar ist


#### 3. Charakteristische Gleichung
allgemein:
![[Charakteristische Gleichungen#JK-Flipflop]]

--> 4 Bit-Zähler => 4 charakteristische Gleichungen
$Q_{A(n+1)} = [(\lnot Q_{A}\land J) \lor (Q_{A} \land \lnot K)]_n$
$Q_{B(n+1)} = [(\lnot Q_{B}\land J) \lor (Q_{B} \land \lnot K)]_n$
$Q_{C(n+1)} = [(\lnot Q_{C}\land J) \lor (Q_{C} \land \lnot K)]_n$
$Q_{D(n+1)} = [(\lnot Q_{D}\land J) \lor (Q_{D} \land \lnot K)]_n$

#### 4. Koeffizientenvergleich

_Trick_: $\lnot Q_{A} = 1 \land \lnot Q_{A}$,

==> vergleiche Koeffizienten:

###### 1. Flipflop
![[koeffizienten_Qa.png]]

###### 2. Flipflop
![[koeffizienten_Qb.png]]

###### 3. Flipflop
![[koeffizienten_Qc.png]]

###### 4. Flipflop
![[koeffizienten_Qd.png]]

#### Schaltbild erstellen
![[schaltbild_berechnung.png]]
