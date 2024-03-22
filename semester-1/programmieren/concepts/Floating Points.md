> IEEE754

[[Floats.pdf]]

![[double_in_memory.png]]

[[negative_powers_of_2.pdf]]


\1. Bit: Vorzeichen-Bit
Charakteristik: Exponential-Darstellung der Zahl (festgelegt (design): 
- 8 bit für float
- 11 bit für double
)
Mantisse: Nachkommazahl

#### Umrechnung
Bsp: $12.625 = 2 * 6.1325 = 2 * 2 * 3.15625 = 2 * 2 * 2* 1.578125 = 2^{3}*1.578125$
==> Vorkomma-Zahl _so lange_ aufteilen, bis _eine 1_ vor dem Komma steht
(oder, wenn vorkomma-Zahl kleiner als 1: so lange mit 2 _multiplizieren_)
--> Verfahren genannt: _Normierung_

Nachkomma-Stelle: Nacheinander _abziehen_
$0.578125 = 0.5 * 0.078125 = 0.5 + 0.0625 + 0.015625 = 2^{-1} + 2^{-4} = 2^{-6} = 0.100101_2$  

Vorkommazahl:
Get into Charakteristik:
zähle Anzahl der Zweien, 
_Offset_ = 127 = $0111\ 1111_2$
$Offset + Potenz = 127 + 3 = 130 = 1000\ 0010_2$ 

==> Wird Zusammengefügt mit Vorzeichenbit

==>zusammengefügt:
$1100\,0001\,0100\,1010_2$



## Doubles
Offset = 1023
Charakteristik hier länger (11 bit)


## Warum? GLEIT-Kommazahl
Charakteristik beschreibt: _wo_ steht das Komma
Kommt ins Spiel bei der Normalisierung:
$12.625 = 0.12625 * 10^{2}$ 
$= 0.0012625 * 10^4$

--> Liegt daran, dass 1.xxx multipliziert wird - "1." als multiplikatives Element useless

## Aufgabe: Das ganze Programmieren


[[double_conversion.c]]

### Little endian Darstellung
Bytes in reihenfolge tauschen --> kleinstes Byte steht vorne
Sinn: Abschließende Nullen können ignoriert werden