![[Pasted image 20251121145825.png|300]]
### pdf
- [[Kapitel0_Organisatorisches.pdf]]
- [[Kapitel1_Introduction.pdf]]
- [[Kapitel2_Mathematische_Grundlagen.pdf]]
- [[Kapitel3_Grundlagen_ML.pdf]]
- [[Kapitel4_Bayes.pdf]]
- [[Kapitel5_Supervised.pdf]]
- [[Kapitel6_Unsupervised.pdf]]
- [[Kapitel7_DeepLearning.pdf]]
- [[Beispielaufgaben_Klausur.pdf]]
### Prüfungsleistung
- Klausur
- beidseitig _handgeschrieben_ -> Tablet okay
- Aufgaben:
	- Man muss nicht viel rechnen (yay)
	- Online multiple choice oder so
	- Konzepte verstanden haben
	- vergleichbar mit Übungsblättern (yes machen)
- Fragensammlung (so was ähnliches wie Altklausuren ig)
	- Algorithmen machen ist nicht klausurrelevant -> vmtl. ziemlich Betriebssysteme-ahh Klausur
- [[ML Quick Fire über das ganze Semester]]
### Libraries (Lock in)
- [[Library ML Basics]]
- [[Library ML Training]]
- [[Library ML Entscheidungstheorie]]

## Signalverarbeitung
- [[Sensor]]
- [[Deterministisches Signal]]
- [[Stochastisches Signal]]
- [[Signalverarbeitunsregeln]]
- [[Signalverarbeitung]]
	- [[Modellbasierte Signalverarbeitung]]
	- [[Lernbasierte Signalverarbeitung]]
- [[Mustererkennung vs. Detektion]]

### Machine Learning
- [[Starke KI]]
- [[Schwache KI]]
- [[ML Buzzwords]]
	- [[Künstliche Intelligenz]]
	- [[Machine Learning]]
	- [[Neural Network]]
	- [[Deep Learning]]
- [[Ablauf Machine Learning]]

## Grundlagen
> [!hint] im Detail nicht klausurrelevant
- [[Regression]]
- [[Klassifikation]]
### Math
- [[Arithmetisches Mittel|Mittelwert]]
- [[Standardabweichung]] ($\frac{1}{n}$ definition)
- [[Korrelation]]
- [[Korrelationsanalyse]] (Untersuchung eines Zusammenhangs)
	- [[Kovarianz]] (um Mittelwert bereinigte Signale korrelieren)
- [[Kovarianzmatrix]]
- [[Korrelationskoeffizient|Pearson-Korrelationskoeffizient]]
	- [[Rangkorrelationen]]
- [[Kausalität]]

#### Korrelation und Faltungshit
- [[Faltung]]
	- [[Faltung in Bildbearbeitung]]
	- [[Zweidimensionale Faltung]]
- [[Wahrscheinlichkeit]]
	- [[Operationen auf Wahrscheinlichkeiten]]
	- [[Unabhängige Ereignisse]]
- [[Satz von Bayes]]
- [[Stetige Verteilung]]

### Optimierung
- [[Constraint Satisfaction Problem]]
- Suchraum
- [[konvexe und konkave Funktionen]]
	- [[Konvexe Fläche]]
- [[Gradient Descent]]
- [[Entscheidungsgrenze]]
	- [[Overfitting]]
	- [[Underfitting]]
- [[Linear Programming]]

### Merkmalsreduktion
- [[Vor- und Nachteile von vielen Merkmalen]]
- [[Merkmal]]
- [[Merkmalsreduktion]]
	- [[Merkmalstransformation]]
	- [[Merkmalsselektion]]
	- [[Merkmalsreduktion durch NN]]
### Trainingsphasen
- [[Klassifikatortraining]]
- [[Operativer Einsatz ML Modell]]
- [[Hyperparameter]]
- [[Active Learning]]
	- [[Pool-based active learning]]
- [[One-Class Classification]]

### Evaluation
- [[Evaluation eines Modells]]
	- [[Fehlerrate|Error Rate]]
	- [[Konfusionsmatrix]]
	- [[Accuracy]]
- [[Kreuzvalidierung]]

#### Fancier
- [[Entropie]]
- [[Binary Cross Entropy]] (binary classification on a [[Sigmoid]]-scaled output)
- [[Focal Loss]]

### Übungen
- [[Übung Müdigkeitserkennung in Autos]]
- [[Übung Anforderung an medizinisches ML System]]
- [[Übungsfragen Kapitel 3]]
## Probabilistische Entscheidungstheorie
- [[Klasse]]
- [[Entscheidungstheoretischer Klassifikator]]
- [[Baumübersicht ML Modelle]]
	- [[A-priori Wahrscheinlichkeit]]
	- [[A-posteriori Wahrscheinlichkeit]]
	- [[Verbundswahrscheinlichkeit]]
	- [[Likelihood]]
	- [[Evidenz]]
- [[Test eines Klassifikators]]
	- [[Fehlerrate|Error Rate]]
	- [[Loss]]
		- [[01-Loss]]
		- [[Bayesian Risk]]
		- [[Conditional Risk]]
	- [[Likelihood Ratio Test]]
		- [[Diskriminanzfunktion]]
- [[MBR Klassifikator]]
- [[MAP Klassifikator]]
- [[Maximum Likelihood Klassifikator]]
- [[Minimax Klassifikator]]
- [[Neyman-Pearson Klassifikator]]

## Überwachtes Lernen
- [[Überwachtes Lernverfahren]]
- [[Bayes Plugin]]
	- [[ML Parameterschätzung]]
- [[Naive Bayes]]
- [[Gauss Klassifikator]]
	- [[Gaussian Mixture Model]]

### Distanzbasiert
- [[Template Matching]]
	- [[K-Nearest Neighbours]]
	- [[Nearest-Mean Klassifikator]]
- [[Diskriminanzfunktion]]
- [[Support Vector Machine]]
	- [[Training einer LDF]]
	- [[Support Vektor]]
	- [[Soft-Margin SVM]]
	- [[Feature Mapping]]
	- [[SVM Kernel]]
	- [[Multiclass SVM]]

### Nochmal Bäume
- [[Decision Tree]]
	- [[Random Forest]]
		- [[Bagging]]
## Unüberwachtes Lernen
- [[k-mean Clustering]]
- [[Principle Component Analysis]]

## 7. Neural nets & deep learning
- [[Neural Network]]
	- [[Neuron]]
	- [[Feed-Forward Neural Network]]
	- [[Activation Function]]
	- [[Training eines Neural Network]]
		- [[Initialisierung Synapsengewichte]]
		- [[Backpropagation]]
- [[Deep Learning]]
- [[Input Scaling und Batch Normalization]]
- [[Regularisierung DNN]]

#### Angewandt
- [[Keras]]
- [[Keras Neural Network Deployment using LiteRT]]

### Whacky derivatives
- [[Convolutional Neural Network]]
- [[Autoencoder]]
	- [[Variational Autoencoder]]
- [[Generative AI]]
- [[Recurrent Nerual Network]]
- [[Transfer Learning]]