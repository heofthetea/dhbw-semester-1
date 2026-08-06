[[Autoencoder]]

1. [[Regressatortraining]] des [[Autoencoder|Autoencoders]] NUR auf Normaldaten \[citation needed]
2. Threshhold $S_{u}$ (output - input) festlegen: $MSE(AE) > T_{l}$ => [[Anomalie]] ([[Mean Squared Error|MSE]])
	1. $T_{l}$ ist als Parameter optimierbar

### Parameter/Hyperparameter
- $T_{l}$: Threshhold
- Aufbau des [[Autoencoder]]: Größe des Latent Space; sowie encoding/decoding schichten
- Sequenzlänge $s$: Wie viele Events werden als Input an den AE gefüttert

![[Pasted image 20260619164635.png]]