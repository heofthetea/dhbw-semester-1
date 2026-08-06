> [[A*]] im Bereich des Autonomen Fahrens

- regular [[A*]] in der realität schwierig
	- berücksichtigt nicht, dass man oft nur vor/zurück/drehen hat anstatt vor/zurück/rechts/links

## Dubins Pfad
- man fährt immer mit konstanter Geschwindigkeit vorwärts

Der kürzeste Weg zwischen zwei Punkten ist immer eine Abfolge von _höchstens_ 3 Segmenten mit maximaler Krümmung (links, rechts) oder gerade aus
![[Pasted image 20260309112051.png]]

> [!info]- Bild
![[Pasted image 20260309112101.png]]


## Generalisierung
- Punkte werden auf ein Raster gelegt
- wenn über zwei verschiedene Wege im selbern Raster gelandet wird:
	- Weg mit geringerer Krümmung wird gewählt

## Trade-off bei [[Heuristik]] mit Hindernissen
- zweite Heuristik: Farhbahrkeit ignorieren
- nur mit Positionen arbeiten (drehung ignorieren)
- dann _maximum_ aus dieser [[Heuristik]] und dem Dubin Pfad nehmen
	- -> mit hindernissen ist das teure
	- im flachen der Dubin pfad