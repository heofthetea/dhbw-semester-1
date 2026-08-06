[[i386]] [[x86 Registers]]

- bei einem [[Unterprogramm Assembler|Funktionsaufruf]] können Funktionsparameter über [[Register]] weiter gegeben werden
- ABER: es gibt nur 6 Register
	- alles, was mehr ist, muss über memory [[Call Stack|Stack Frames]] gelöst werden; aber [[Memory]] ist langsam

> [!warning] Für bestmögliche Performance: Anzahl der Parameter einer Funkion auf max. 6 pointer reduzieren.