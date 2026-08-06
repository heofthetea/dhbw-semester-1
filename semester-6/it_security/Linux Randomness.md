---
aliases:
  - dev urandom
  - dev random
---
- Entropy Pool wird im Hintergrund immer mit Umgebungs-Entropie aufgefüllt
- [[Prozess Blocking|blocking]] pool: etwas sicherer
	- wenn Entropiepool aufgebraucht ist: [[Prozess Blocking|blockiert]], bis Entropy Pool wieder aufgefüllt wurde
- [[asynchronous|non-blocking]] pool:
	- blockiert nie => ich bekomme _immer_ sofort neue Zufallszahl
	- Qualität nach aufgebrauchtem [[Entropie]] Pool ist nicht mehr ideal zufällig
- [[Entropie]] Counter: merkt sich, ob der Pool aufgefüllt werden muss

![[Pasted image 20260319154006.png]]


## When to use which?
- für kritische Anwendungen: `/dev/random` 
- für weniger kritische: `/dev/urandom`