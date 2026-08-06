- [[Signalverarbeitung]]
	- [[Mustererkennung vs. Detektion]]
	- [[Stochastisches Signal]]/[[Deterministisches Signal]]
	- [[ML Buzzwords]]

### kapitel 2 math
- [[Korrelation]] - Zusammenhang zwischen 2 Variablen
- [[Korrelationskoeffizient]] - Normierte [[Kovarianz]] $-1 \leq R \leq 1$
	- abhängig davon, welcher Koeffizient gewählt wird
- [[Kausalität]] (und Abgrenzung von Korrelation)
- [[Faltung]]
	- Veranschaulichung, wie ein [[Signal]] ein anderes berechnet
	- [[Korrelation]] mit gespiegeltem $y$ (immernoch kp why aber oke)
- [[Optimierung]]
	- MInimierung/Maximierung einer Zielfunktion unter Nebenbedingungen
		- => todo: formel aufschreiben
	- [[Konvexe Fläche]]


### Kap 3
- [[Ablauf Machine Learning]]
- [[Regression]] vs. [[Klassifikation]]
- Anforderungen an [[Daten]]
	- repräsentativ, divers, ausrechende Menge, (gute Labels)
- [[Überwachtes Lernverfahren]]
- [[Unüberwachtes Lernverfahren]]
	- teil-überwacht (große menge unlabelled, kleine menge labelled)
- was ist ein [[Merkmal]]
- [[Z-Transformation]]/Skalierung von merkmalen
- [[Entscheidungsgrenze]]
	- [[Overfitting]]
	- [[Underfitting]]
	- => [[Bias-Varianz Problem]]
- [[Merkmalsreduktion]]
	- [[Merkmalsselektion]]
	- [[Merkmalstransformation]]
- [[Klassifikatortraining]]
	- [[Trainingsdaten]]/Testdaten, [[Kreuzvalidierung]]
- [[Operativer Einsatz ML Modell]]
- Metriken
	- Datensatz balanciert?
	- false-positives schlimmer als false negatives?
- [[Konfusionsmatrix]]
	- [[Loss]]
	- derived metrics
		- [[Recall]]
		- [[Accuracy]]
		- [[F1-Score]]
		- etc.

### Kap 4
- [[Entscheidungstheoretischer Klassifikator]]
	- Arbeiten mit Bayes'scher Wahrscheinlichkeitsrechnung
	- -> bekannt: [[Loss]], [[A-priori Wahrscheinlichkeit]], [[Likelihood]]
	- [[Diskriminanzfunktion]] ausrechnen & auswählen
	- [[MBR Klassifikator]] => minimum [[Bayesian Risk]]
		- [[MAP Klassifikator]]
		- [[Maximum Likelihood Klassifikator]]
- [[Neyman-Pearson Klassifikator]], [[Minimax Klassifikator]]: [[A-priori Wahrscheinlichkeit]] unbekannt

> [!hint] Hier wissen, was wo erfordert ist (hier ist a-priori bekannt, hier nicht, etc.)

- [[Bayes Plugin]]
- [[Naive Bayes]]: Unabhängigkeit der [[Merkmal|merkmale]] werden angenommen
- [[Gaussian Mixture Model]]: Subklasse
- [[Template Matching]] -> aka. Distanzbasierte [[Klassifikation]] _ohne_ Entscheidungsgrenze
	- [[Nearest-Mean Klassifikator]]
	- [[K-Nearest Neighbours]]
- [[Support Vector Machine]]
	- [[Support Vektor]]
	- [[Soft-Margin SVM]] & [[Support Vector Machine|Hard-Margin SVM]]
	- nicht-lineare EGs: [[Feature Mapping]]; [[SVM Kernel]]
	- [[Multiclass SVM]]
- [[Decision Tree]]
	- [[Random Forest]]
- [[Clustering]]
	- [[k-mean Clustering]]
	- [[Fuzzy c-means]]

### Kapitel 7
- [[Neural Network]] (begriff vollvernetzt)
	- [[Neuron]]
	- [[Feed-Forward Neural Network]]
	- [[Activation Function]]
	- [[Training eines Neural Network]]
- [[Deep Learning]]: $L \geq 3$ (mindestens 3 hidden layer)
	- warum mehr schichten = besser
- [[Input Scaling und Batch Normalization]]
- [[Convolutional Neural Network]]
- [[Autoencoder]]