> Split a product up into multiple small, independent services

- allows for fast Scalability
- one service can be used in multiple contexts
- Communication between services through [[Message-based Kommunikation]], [[REST]] or [[RPC]]

 > [!hint] "Wenn ein microservice stirbt, und alles andere abstürzt, ist es eigentlich ein verteilter Monolith" 🗣
 

> [!hint] Monitoring/[[DBMS]] ist _kein_ eigener Service, sondern ist Teil eines Services.
## Tatsächliches Beispiel
- Webshop
- jeder [[Microservice]] hat seine _eigene_ Datenbank!!

![[Pasted image 20260303092220.png]]