> Simpelster Flip-Flop
> Auch genannt: "Latch"
> Flipflop, der am günstigsten herzustellen ist

### Schaltsymbol
![[sr_ff_symbol.png]]
Namensgebung:
- **Set**: S-Eingang
	- Setzt $Q_{1}$ auf 1
- **Reset**: R-Eingang
	- Setzt $Q_{1}$ auf 0 zurück

### Wahrheitstabelle
| S | R | $Q_1$ |
| ---- | ---- | ---- |
| 0 | 0 | $Q_{1_{n-1}}$ |
| 0 | 1 | 0 |
| 1 | 0 | 1 |
| 1 | 1 | -X- |

### Schaltungstechnischer Aufbau
Aufbau ist analog mit NANDs und NORs

![[ff_nand.png]]
#### Unterscheidung NAND/NOR-Latch#
**Bei NAND Latches müssen die Eingänge invertiert werden!!**
--> ansonsten: Set und Reset Eingänge machen genau das Gegenteil ihrer angedachten Funktion

Unterschied liegt in _Wert_ des [[Verbotener Fall|verbotenen Falls]]:
- NAND: $Q_{1} = Q_{2} = 1$ 
- NOR:  $Q_{1} = Q_{2} = 0$ 



