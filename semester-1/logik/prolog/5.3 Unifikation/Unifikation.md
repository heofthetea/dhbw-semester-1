> Prolog-Terme t und s sind _unifizierbar_, wewnn es eine Substitution $\sigma$ gibt, die die in s und t enthaltenen Variablen so an Terme bindet, sodass $\sigma(t) = \sigma(s)$ gilt.


## Unterschiede zu Prädikatenlogik
- keine strikte Trennung zwischen Funktionssymbolen und Prädikaten
	- $X$ ist unifizierbar mit $woman(mia)$.
- kein Occurs-Check
	- $X$ ist unifizierbar mit $father(X)$.
	- Abhilfe: `unify_with_occurs_check(X, father(X))`.

## Unifikation und Stelligkeit
![[stelligkeit_unifikationi.png]]


## Expliziter Aufruf: '='
- ist erfolgreich, wenn Argumente unifizierbar sind
- gibt die für die Unifikation notwendigen Variablenbindungen zurück
	-  ansonsten: $false$ 

```
1) ?- X = mia.
X = mia.

2) ?- woman(X) = woman(mia).
X = mia.

3) ?- loves(X, vincent) = loves(mia, X).
false.

4) ?- loves(mia, vincent) = loves(X, X).
false.

5) ?- knows(fathher(vincent),X) = knows(Y, mother(mia)).
X = mother(mia),
Y = father(vincent).
```

zu 3) - Variable kann nur an _einen_ Term gebunden werden


## In Anfragen
![[Unifikation in Anfragen]]


## Negierte Unifikation
![[Negierte Unifikation]]