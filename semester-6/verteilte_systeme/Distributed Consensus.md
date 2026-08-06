> Wie RabbitMQ z.B. seine [[Queue]]s synchronisiert

- [[Nachricht|Nachrichten]] werden replikiert
- [[Queue]] wird veriteilt über verschiedene [[Knoten]]
	- jeder [[Knoten]] muss die ganze [[Queue]] speichern
	- ungerade -> einer [[Knoten]] ist der Master und verwaltet schreib/lesevorgänge

> [!hint] Bei Write: Die Mehrheit der [[Knoten]] müssen [[Backwards Error Correction|acknowledgen]], dass sie die Nachricht erhalten haben


![[Pasted image 20260310105556.png]]

## Algorithmus
(im Detail yeeeeeeeeeeeeeee)