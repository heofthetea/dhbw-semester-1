[[Berechnung von Synchronzählung]]
- nur 10 Zustände wirklich benötigt --> trotzdem _alle_ hinschreiben
	- Achtung: bei 10. Zähler wieder die 0 an Ausgängen
	- beachte _Don't-Cares_
- Bei _Rückwärtszrählern_: IMMER LINKE SEITE -1!!!

### Tipps
- Don't Cares einmal eintragen 
	- Danach immer kopieren --> BESONDERE VORSICHT (einmal falsch = 4x falsch xd)
- kleinste Wertigkeit toggled immer (KV-Diagramm unnötig, Zeit sparen lol)
- [[Bei Synchronzählerberechnung immer von Links nach Rechts arbeiten]]
## [[Erweiterte Warheitstabelle]]
| Dezimalwert | $Q_{D(n)}$ | $Q_{C(n)}$ | $Q_{B(n)}$ | $Q_{A(n)}$ |  | $Q_{D(n+1)}$ | $Q_{C(n+1)}$ | $Q_{B(n+1)}$ | $Q_{A(n+1)}$ | Dezimalwert |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| 0 | 0 | 0 | 0 | 0 |  | 0 | 0 | 0 | 1 | 1 |
| 1 | 0 | 0 | 0 | 1 |  | 0 | 0 | 1 | 0 | 2 |
| 2 | 0 | 0 | 1 | 0 |  | 0 | 0 | 1 | 1 | 3 |
| 3 | 0 | 0 | 1 | 1 |  | 0 | 1 | 0 | 0 | 4 |
| 4 | 0 | 1 | 0 | 0 |  | 0 | 1 | 0 | 1 | 5 |
| 5 | 0 | 1 | 0 | 1 |  | 0 | 1 | 1 | 0 | 6 |
| 6 | 0 | 1 | 1 | 0 |  | 0 | 1 | 1 | 1 | 7 |
| 7 | 0 | 1 | 1 | 1 |  | 1 | 0 | 0 | 0 | 8 |
| 8 | 1 | 0 | 0 | 0 |  | 0 | 0 | 0 | 1 | 9 |
|  |  |  |  |  |  |  |  |  |  |  |
| 9 | 1 | 0 | 0 | 1 |  | 0 | 0 | 0 | 0 | 10 (reset) |
| 10 | 1 | 0 | 1 | 0 |  | X | X | X | X | X |
| 11 | 1 | 0 | 1 | 1 |  | X | X | X | X | X |
| 12 | 1 | 1 | 0 | 0 |  | X | X | X | X | X |
| 13 | 1 | 1 | 0 | 1 |  | X | X | X | X | X |
| 14 | 1 | 1 | 1 | 0 |  | X | X | X | X | X |
| 15 | 1 | 1 | 1 | 1 |  | X | X | X | X | X |


## KNF
![[knf_bcd_synchronzähler.png]]
## Schaltbild
![[schaltung_bcd_synchron.png]]

## Lösung
- _FUCK_ BEII $Q_{D}$ DEN FALL 8 FALSCH IN [[#Erweiterte Warheitstabelle]] EINGETRAGEN WHAT THE FUCK AAAAAAAAAAAAAAAAAAAAAAAA
- bei $Q_{D}$ (im fehlenden Fall) kein Zweierpäckchen bilden??
	- Weil [[Berechnung von Synchronzählung#4. Koeffizientenvergleich|Koeffizientenvergleich]] 
	- Gesuchte Variable (hier $G_{D}$) würde bei Päckchenbildung _über_ Grenzen eliminiert werden
		--> Output fliegt aus Gleichung raus ups
- Dicke Linien um _die aktuelle Ergebnisvariable_
- $Q_{B}$ ist auch falsch holy shit ich kann gar nichts dafuq
![[Pasted image 20240129160826.png]]
![[Pasted image 20240129160243.png]]