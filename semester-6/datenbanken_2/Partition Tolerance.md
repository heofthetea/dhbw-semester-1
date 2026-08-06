> Kann ein [[Verteiltes System]] weiter arbeiten, auch wenn ein Teil des Systems ausfällt


- bei fehlender Toleranz:
	- Knoten 3 fällt aus -> dadurch sind die anderen beiden auch down

![[Pasted image 20260305103042.png]]


## Partitioning
- multiple [[Server|servers]] use heartbeats to know whether the others are still available
	- one [[Distributed Data storage]]: only master can write
- now this network drops out -> how do I know whether master is dead or just cannot respond?

> [!warning] There are never allowed to be two masters!!!!

