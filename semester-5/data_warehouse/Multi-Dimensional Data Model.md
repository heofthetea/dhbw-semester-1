---
aliases:
  - MDDM
  - Star-Schema
---
> Alternative zu [[3NF]] eines [[OLTP]], optimisiert für Auswertung

## Bestandteile
- **Key Figures** => "measures"
- [[Dimension|Dimensionen]] ( = "[[Attribut|Attribute]]):
	- in jeder Dimension viele Ausprägungen
- **Dimension Table**
	- eine [[Tabelle]] für jede [[Dimension]]
	- ids für jedes Dimensionselement
	- Zusätzliche Felder für deskriptive Information
- **Fact Tables**
	- [[FOREIGN KEY Constraint|Fremdschlüssel]] auf die beschriebene Dimension
	- Andere Werte in der Tabelle beschreiben measures

## Queries
- Beispiel: "Sales amount for product X in region Y and time period Z"

## Beispiel
- [[Stern-Topologie]] mit Fact table im zentrum und dimension tables in Peripherie
![[Pasted image 20251021094717.png]]