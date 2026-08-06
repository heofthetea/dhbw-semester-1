
> [!info] Motivation: [[Deep Learning]] tendiert zum [[Overfitting]]  => Challenge: Modell finden, dass guten Zwischenweg findet ([[Bias-Varianz Problem]])

## L2-Regularisierung
> Bestrafung große Gewichte

## Early Stopping
> Abbruch des Trainings bei Stagnation eines Fehlermaßes

## Data Augmentation
> Künstliche Vergrößerung des Trainingsdatensets durch Generierung realistischer Samples

- Idee: mehr Trainingsdaten => weniger Overfitting (oke)
## Ensemble Learning
> Abmilderung von Zufallseffekten (??)

- vgl. [[Random Forest]] (mehrere Netze trainieren)

## Dropout
> Zufällig [[Neuron|Neuronen]] in jedem Batch deaktivieren

- Idee: Modell zwingen zu generalisieren (weil unvorhersehbar ist, welche Synapsen tatsächlich existieren werden)

> [!hint] Wird quasi überall gemacht