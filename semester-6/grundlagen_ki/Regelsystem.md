> [[Produktionsregel|Produktionsregeln]] geben an, wie ein Ausdruck transformiert werden kann


$$\text{<Condition>} \longrightarrow \text{<Action>}$$

![[Pasted image 20260223092717.png]]

- **Konfliktlösung**: Wenn mehre [[Produktionsregel|Produktionsregeln]] anwendbar sind: in welcher Reihenfolge probier ich die aus?
	- Most specific first, Most general first, MOst recently used, Least recently used, Time tagged, Ranking (macht Prolog -> einmal anfangs reihenfolge festlegen)
## Systeme
### Forward Chaining
- Regel auf Daten anwenden
- => erzeugt neue Daten
- neue Daten erfüllen Eingangsbedingung weiterer REgeln

### Backward Chaining
> [!hint] macht [[Prolog Interpreter]]

- Es werden Aussagen angegeben, welche gelten müssen
- Produktionen erzeugen die nötigen Aussagen für die Regelseite als Datenelemente