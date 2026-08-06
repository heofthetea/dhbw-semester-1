> Ein für ein System untypisches Ereignis

---
# Datenbanken
> Wenn eine [[Konsistenzüberwachung|Inkonsistenz]] in der [[Datenbank]] existiert
## Einfügeanomalie
- [[Daten]] können nicht angelegt worden, weil benötigte Teilinformationen nicht existieren

> [!hint] Beispiel: [[Schwacher Entitätstyp|Abhängige Entität]] einfügen, für die noch keine starke Entität existiert -> bräuchte [[null]]

## Löschanomalie
- [[Daten]], die eigentlich nicht gelöscht werden sollten, werden trotzdem gelöscht

## Änderungsanomalie
- Man muss denselben Wert aufgrund [[Redundanz]] an mehreren Stellen ändern
	- => Hier können an einigen Stellen Fehler passieren, oder einige Stellen vergessen werden
