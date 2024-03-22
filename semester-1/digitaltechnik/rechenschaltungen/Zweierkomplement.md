>  Darstellung einer [[signed]] Binären Zahl.

Vorzeichenbit 0 --> positiv
Vorzeichenbit 1 --> negativ

## Verfahren
> [!info] Verfahren ist für Codierung und Decodierung gleich.
1. Invertiere die Zahl
2. addiere 1

> [!warning] Enthält die Zahl führende Nullen, müssen diese selbstverständlich auch Invertiert werden!!
## Beispiel
Decodierung: $110010$
Signing Bit 1 --> negativ
1. invertieren: $001101$
2. addiere 1: $001110$ 
==> $110010$ im Zweierkomplement ist $-14_{10}$  