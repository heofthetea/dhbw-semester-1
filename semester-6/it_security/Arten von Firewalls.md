## Stateful Inspection
> [[Stateful]] Packet Filtering Firewall

- besitzt einen [[State]] 
	- z.B. in einer [[Datenbank]]
- Prüfungen erfolgen abhängig vom [[State]]

![[Pasted image 20260311143726.png]]

## Application-Proxy
- [[Layer 7]]
- Funktioniert wie ein Gateway
- Kann auch Anwendungs-Pakete lesen
	- -> mehr aufwand, aber ggf. mehr Information

![[Pasted image 20260311143802.png]]

## Circuit Level Proxy
> Application-Proxy Firewall aber auf [[Layer 4]]

- z.B. [[iptables]] ist das

![[Pasted image 20260311143831.png]]

## Web-Application Firewalls
- Hauptidee: [[DDoS]] erkennen und abfangen

> [!hint] PSAD can be made into a WAF