- im Kern immernoch [[Message Queue]] Pub/Sub pattern
	- Consumer speichern, welche daten er zuletzt bekommen hat 
	- ABER: Consumer [[Polling|pollen]] eher, es ist nicht wirklich [[Event-driven Architecture|event-driven]]
- Daten werden retained in der [[Queue]] auch nach consumption -> ermöglicht [[Random Access auf Arrays|Arbitrary Reads]]
- Vereint:
	- [[Message Queue]]
	- Event Log
	- Streaming Plattform
	- [[Horizontal Scaling]]
	- [[Persistent Volume|Persistence]]

> [!hint] Namensherkunft: "Kafka ist write-optimized - wie der Schriftsteller"

## Kafka Connect
- Framework to integrate Kafka with other systems

## Apache Flink
- Sonething to do [[Java Stream|Stream]] operations on the messages in the [[Queue]]


## Konsistenz
- Daten werden nicht bei jedem Write repliziert
	- Follower replizieren [[asynchronous]]