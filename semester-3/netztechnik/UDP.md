---
aliases:
  - Fire and Forget
---
¹> User Datagram Protocol

> [!info] Fire and Forget

[[verbindungslose Kommunikation]]

- sitzt auf auf [[IP]]
- Keine Garantien wie Acknowledgements
- Validiert source [[IP Adresse]] nicht
- [[Checksum]] ist _optional_
- dafür: deutlich schneller als [[TCP]]; deswegen gut für Streaming

> [!hint]- Video-Streaming ist oft [[UDP]], weil Verbindungsorientierte Kommunikation zu viel Overhead ist
> Wenn ein paket nicht da ist fehlt halt mal ein halbes frame oder so das juckt niemanden

## Anwendung
- Video Streaming
- [[DNS]]
- [[NetBIOS]]
## Header

![[Pasted image 20260311142137.png]]