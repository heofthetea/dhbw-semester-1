## Funktionale Anforderungen


## Nichtfunktionale Anforderungen
- Konsistenz - Nutzer sehen Nachrichten in der selben Reihenfolge, wie sie gesendet wurden ([[Eventual Consistency]])
- Performance (Latenz)
- Sicherheit/Datenschutz ([[Goals of Cryptography]])
- Skalierbarkeit
- Fehlertoleranz



## System
```mermaid
flowchart LR
	Benutzer["Benutzer (Web/Mobile)"] --> Cluster
	Cluster --> Authentifizierungsservice
	Cluster --> Monitoring-System
	Cluster --> C[Push-Notification-Service]
```


> [!warning] App Stores, Gesetze, Nutzer, ... sind auch Teil des Systemkontextes