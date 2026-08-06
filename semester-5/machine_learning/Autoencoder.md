> Training eines [[Neural Network]] zum eigenständigen extrahieren wichtiger [[Merkmal|Merkmale]]

- [[Unüberwachtes Lernverfahren]]
- Repräsentation: numerische Darstellung von Rohdaten
- [[Evaluation eines Modells|Evaluation]] basierend auf Ähnlichkeit von Output zu Input
- anwendung z.B. zur [[Merkmalsreduktion|Dimensionsreduzierung]] (weiterarbeiten mit Repräsentation im Bottleneck)
- Kompression
- [[Anomaliedetektion]] -> man hat was, was am Ende nicht sinnvoll rekonstruiert werden kann (dann muss das ne Anomalie sein)

## Aufbau
![[Pasted image 20251205142058.png]]
- Bottleneck (**Latent-Space**): codierte Version des INputs
	- weniger [[Neuron|Neuronen]] -> das Modell zwingen, nur einen Teil der Merkmale (die wichtigsten) zu extrahieren

## idk beispiel bcs it looks cool
- 784 Neuronen weil: so viele Pixel hat das Bild
![[Pasted image 20251205142229.png]]