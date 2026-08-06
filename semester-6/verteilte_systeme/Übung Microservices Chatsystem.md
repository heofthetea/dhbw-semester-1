[[Microservice]]

- Authentication Service ([[Identity Provider]])
- Message Broker (Rabbitmq)
- Client (z.B. Web Frontend, Service: UI Auslieferung)
- Backend Service (nutzt entweder Broker zum queuen von nachrichten oder macht das selber)
- Push Notifications Service
- Attachments (eigene [[Document Database]] für Attachments)
- Joinen von Chatrooms

### API Gateway



## Brainstorming

| Service                    | Verantwortung                                                                                                                               |
| -------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------- |
| User/Account               | Accountverwaltung, Kontakte, Online Status (kann auch externer Service sein)<br>Berechtigungen                                              |
| [[Client]]                 | Auslieferung der ui                                                                                                                         |
| Notification Service       | Push Benachrichtigungen                                                                                                                     |
| Message Service            | Annahme & Verarbeitung von Nachrichten<br>Persistenz der Chat Historie                                                                      |
| Group/Conversation Service | Erstellen & Verwalten von Gruppen                                                                                                           |
| Media Service              | Upload & Verwalten von Attachments (Fotos, Videos etc)                                                                                      |
| (Presence Service)         | Verwalten, ob user online ist<br>(rechtfertigung kommt dadurch, dass es dynamische daten sind die sich oft ändern und oft angefragt werden) |

### API -Gateway

- Verantwortlichkeiten:
	- [[Authentifizierung vs Authorisierung|Auth]]
	- [[Routing]] - Anfrage muss zum richtigen Service geroutet werden
		- z.B.: Service Registry
		- [[Application Load Balancer|ALB]]
	- [[TLS Terminierung]]