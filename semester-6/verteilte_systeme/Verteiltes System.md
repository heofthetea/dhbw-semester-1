> [[Computer]]-System, dessen einzelne Kommunikations-Komponenten auf verschiedenen, unabhängigen [[Netzwerk]]-[[Host|Hosts]] liegen

- Jeder [[Host]] ist ein eigenständiger [[Computer]] -> Kommunikation [[Message-based Kommunikation|nachrichtenbasiert]] über [[netzwerk]]
- Aus Perspektive des Nutzers wirkt es kohärent als ein System
- Gesamtsystem hat eine gemeinsame Aufgabe/Mission/Ziel

> [!info] A distributed System is one on which I can't do any work because some machine I've never head of has crashed. ~ Some legend
### Vorteile
- [[Horizontal Scaling|Scalability]]
	- Allgemein Leistungssteigerung
- Ausfallsicherheit ([[HA Cluster#Failover]])
- Bessere Live-Updates/DevOps Shit
- Optimale Hardware-Nutzung

### Challenges
- Unreliable [[Netzwerk]]
- Netzwerk-Limitierungen (Latenz, Bandbreite)
- Sicherheit; größere Angriffsfläche
- Keine einheitliche [[Clock]]; Zeitsynchronisation
- Failover System (was mach ich wenn ein Host ausfällt)
- Synchronisation -> [[Nebenläufigkeit]]
- [[Verfügbarkeit Informationssysteme|Availability]]
- Kommunikation/Interaktion (Message loss, order)


## Beispiele
- lö [[Internet]]
- Web-Anwendungen
- [[IoT]] Anwendungen
- Firmen-interne Intranets
- [[Email Comunication]] (viele Mailserver, die sich synchronisieren)
- [[Microservice]]s
- [[Peer-to-Peer Network]] (Torrent)
- [[Serverless]]
- AI Data Centers


### Anti-Beispiel
- Simple [[Client Server Architecture]] mit Handy/server
- kein wirkliches System, weil keine Ausfallsicherheit (server weg -> tot), keine Verfügbarkeit