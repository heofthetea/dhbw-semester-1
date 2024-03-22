[[Programmentwurf_Probe.pdf]]
[[fucking_aufzug.c]]
### Gegeben
```c
typedef struct
{
	struct Stockwerk stw;
	int stw_anzahl, stw_soll, stw_ist, aktion;
} AUFZUG;


int main()
{
	AUFZUG lift;

	return 0;
}
```


### a)
```c
#include <stdint>

sruct Stockwerk
{
	int stockwerk_nummer;
	uint16_t statuswort;
	int angefordertes_zielstockwerk;
} Stockwerk;
```


### b)
#### b1)
- geht hard-coding mit 10?
```c
typedef struct
{
	struct Stockwerk **stockwerke;
	int stw_anzahl, stw_soll, stw_ist, aktion;
} AUFZUG;
```

#### b2)
- _reicht das???_ oder will der ne [[Doubly Linked List|Linked List]] / dynamic array haben
- --> JA WILL ER BRO TF
```c
typedef struct
{
	struct Stockwerk **stockwerke; // länge muss durch malloc() at runtime festgelegt werden
	int stw_anzahl, stw_soll, stw_ist, aktion;
} AUFZUG;
```


### c)
using [[#b1)]] obviously, duh
```c
AUFZUG *aufzugInit(int anzahlStockwerke)
{
	AUFZUG *lift = malloc(anzahlStockwerke * sizeof(Stockwerk) + 4 * sizeof(int));
	lift->stw_anzahl = anzahlStockwerke;
	for(int i = 0; i < anzahlStockwerke; i++) {
		lift->stockwerke->stockwerk_nummer = i + 1; // malloc initialization defaults to zeroes
	}
	return lift;
}


int main()
{
	AUFZUG lift;
	int anzahlStockwerke;
	scanf("%d", &anzahlStockwerke);
	
	lift = *aufzugInit(anzahlStockwerke);
}
```


### d)
in [[#c)]] direkt gelöst lol
nur ohne den Fehlerabfang, aber das haben wir nicht gemacht

### e)
```c
int main()
{
	AUFZUG *lift;
	int anzahlStockwerke;
	scanf("%d", &anzahlStockwerke);
	
	lift = aufzugInit(anzahlStockwerke);
	while(1)
	{
		aufzugStatus(lift);
		aufzugAktion(lift);
		sleep(1000);
	}
}
```


### f)
- 9. bit in 16-bit unsigned integer --> $2^{8} = 256$ 
- how does bit-shifting work again?

_Problem with this approach_: don't subtract $2^{8}$ but rather $2^{16}$, as the number is still **16 bits long bozo** 
```c
// 0 in 9th bit --> not on floor
int on_flor(uint16_t status)
{
	int flag = (status << 8) - 0xffff;
	return flag >= 0;
}

int get_stockwerk(uint16_t *statuses)
{
	int stockwerk;
	for(int i = 0; i < sizeof(statuses)/sizeof(uint16_t); i++) {
		if(on_floor(status[i])) {
			stockwerk = i;
			break;
		}
	}
	return stockwerk;
}
```

#### Aufruf aus main
```c
uint16_t statuses[anzahlStockwerke];
for(int i = 0; i < anzahlStockwerke; i++) {
	statuses[i] = lift->stockwerke[i];
}
int stockwerk_of_lift = get_stockwerk(statuses);
```
