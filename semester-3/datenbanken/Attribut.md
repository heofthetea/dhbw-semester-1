---
aliases:
  - Feature
---
[[Entität]], [[Schlüsselattribut]]

- Ein Key-Value Pair aus **name** und [[Menge|Domäne]] (= Wertebereich)/Datentyp

## Konzeptioneller Entwurf ([[ERM]])

Eigenschaften einer [[Entität]] _oder_ einer [[Relationship|Beziehung]]
-> wird in [[Datenbankschema]] zu den Spalten

- Einzelne Ausprägungen heißen _Attributwerte_
- Es werden nur Attribute gespeichert, die für die _konkrete Anwendung_ relevant ist.
	- **!!** Meine Aufgabe, um das auch mit dem Kunden zu diskutieren!

> [!hint] Man sollte so wenig Daten wie nötig speichern, aber nicht so wenig wie möglich!
> - ggf. auch in die Zukunft schauen


![[Pasted image 20240917150907.png]]


> [!warning] [[Relationship|Relationships]] haben auch [[Attribut|Attribut]]!!

## Wertebereich
[[Zielmenge|Wertemenge]]
- Beschreibt, welche Werte das [[Attribut]] festlegen kann
--> z.B. die Größenordnung einer Spalte
- verhindert, dass Daten nicht oder falsch gespeichert werden

> [!warning] Muss mit Kunden abgestimmt werden!!


