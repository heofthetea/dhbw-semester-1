- vergleicht 2 Einträge bestehend aus 3 bit
- _Kanonischer_ Weg würde zu 64 Einträgen in db führen --> not feasible

"Human" Approach:
1. Vergleiche _größte Stelligkeit_ 
2. wenn gleich: vergleiche niedrigere Stelligkeit
3. usw...

--> läuft auf Verwendung von [[1-bit Komparator]] hinaus


![[Pasted image 20240202081040 1.png]]

### Umsetzung
![[Pasted image 20240202081809 1.png]]
Ausgang $Y_{n}$ überprüft _Gleichheit_
Wenn ja: _Enable_-Eingang des nächsten [[1-bit Komparator mit Sperrschaltung|1-bit Komparator]] wird auf 1 gesetzt

