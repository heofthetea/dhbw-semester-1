> [[Quantum Key Distribution]] mit [[One-Time-Pad]]

- ist [[Unconditional Hardness|unconditionally secure]] 

## Ablauf
1. Vollständig [[Zufallsvorgang|zufälliges]] [[Cryptographic Key|Schlüsselmaterial]] durch Quantum-based Zufall
2. [[#Datenübertragung]] durch [[Quantum Key Distribution]] mit [[Photon Polarization]] und [[Quantum Filter]]
3. Danach [[One-Time-Pad]]

## Datenübertragung
[[Basis|Messbasis]] wird kodiert: einer der orthogonalen Vektoren (horizontal/vertikal oder links-/rechtsdiagonal) beduetet logisch 1, der andere 0
Durch [[Quantum Filter]] wird hier gemessen

> [!warning] Problem: Manche Sachen kommen nicht an (die `-` Dinger)
> Lösung: Bob gibt Alice durch, mit welchen [[Basis|Basen]]  er gemessen hat
> => Alice kann dann rekonstruieren, was Bob gemessen hat
> Dear Eavesdropper aber weiß aufgrund der Codierung nichts!

![[Pasted image 20260320111408.png]]