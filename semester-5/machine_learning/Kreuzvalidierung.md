---
aliases:
  - cross validation
---
> mehrfaches [[Klassifikatortraining]] mit unterschliedlichen Datensplits -> Performance und [[Evaluation eines Modells|Evaluationsmetriken]] über Mittelwert und Standardabweichung angeben

> [!hint] Löst das **Problem**: [[Klassifikatortraining]] einmal mit einem Datensplit durchführen -> Möglichkeit, dass Performance auf Zufallseffekten basiert

- Cyclical Folding:
	- Mehrere Folds machen (i.e. Teile des Datensatzes)
	- Jeden Fold einmal als Trainingsdaten zurückhalten
- Bei kleinen Datensätzen: 3 Folds (bei zwei weiß man gar nicht was die regel ist)