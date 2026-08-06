> Basic Network Security durch Regeln

Basic functionality with [[#Connection Table]]:
1. For outgoing packet ([[Client]] -> [[Server]]): add entry to Table
2. For incoming packet: Check whether packet matches an outbound connection in Table
	1. if yes: all good
	2. if no: Block the packet
3. Enforce further rules (i.e. blocking of specific domains, etc) through [[Blacklisting]]/[[Whitelisting]]

=> Requires [[P2P Hole Punching]] to get around

> [!hint] It makes a lot of sense to combine that with [[NAT]], essentially throwing a [[Firewall]] together with the [[NAT]] table at the edge of a [[Privater IP-Addressraum|Local Network]]
## Connection Table
- Basically, Firewall keeps track of all inbound and outpound connections
	- For [[TCP]]: Whether connection is alive can be determined based on whether SYN or FIN packets have arrived
	- For [[UDP]]: Timeouts after which connections are removed from the table

|Source IP|Destination IP|Transport Protocol|Source Port|Destination Port|
|---|---|---|---|---|
|192.168.0.2|198.51.100.0|TCP|12345|443|
|192.168.0.2|198.51.100.1|UDP|12345|53|
|...|...|...|...|...|
