> [!question]- Werden Nachrichten Dauerhaft gespeichert?
> Kafka: ja
> MQ: je nach Broker

> [!question]- Werden mehrere Consumer unterstützt?
> ja
> MQ: ja

> [!question]- Ist Replay möglich
> ja
> MQ: ne



## ACKS = 1 vs ACKS = ALL
- wie viele Replicas müssen Daten erhalten, um als erhalten zu gelten
	- 1: nur der leader
	- all: alle replicas

