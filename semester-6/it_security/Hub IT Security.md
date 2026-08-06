### General
- Es gibt noch irgendwan Klausurvorbereitung
- Grob besprechen was im Groben relevant ist

- [[Klausurvorbereitung IT Sicherheit]]
- [[Prüfungsfragen IT Sicherheit v2]]
- [[IT Security Alle Fragen]]

### PDF
- [[1 Grundlagen IT-Sicherheit SS-2026 Introduction to Security 1_0.pdf]]
- [[2 Grundlagen IT-Sicherheit SS-2026 IT-Security in the Lifecycle 1_0.pdf]]
- [[3 Grundlagen IT-Sicherheit Security Requirements SS-2026 1_0.pdf]]
- [[4 Grundlagen IT-Sicherheit Netzwerksicherheit SS-2026 1_0.pdf]]
- [[5 Grundlagen IT-Sicherheit SS-2026 Information Security Management 1_0.pdf]]
- [[6 Einfuehrung Kryptographie DHBW Stuttgart SS-2026.pdf]]
- [[7 Quantum Key Distribution DHBW Stuttgart SS-2026 1_0.pdf]]
- [[8 Security in Software Development DHBW Stuttgart SS-2026 1_0.pdf]]
- [[8 Business Continuity Management DHBW Stuttgart SS-2026 1_0.pdf]]
- [[9 Signature Solutions DHBW Stuttgart SS-2026 1_0.pdf]]


### Misc
- [[Schengen Informations System]]
- [[ECCG ACM]]

## Basics
- [[Grundlegendes Prinzip der Sicherheit]]
- [[Motivation IT Sicherheit]]
	- [[IT Sicherheit ist keine rein technische Affäre]]
- [[Perimeter-Sicherheit]]
- [[Domain Architektur]]
	- [[Security by Design]]
- [[IT Security Buzzwords]]
- [[Redundanz]]
- [[Herausforderungen für IT Sicherheit in Projekten]]
- [[Risikomatrix]] & [[Risikomanagement]]
- [[Authentifizierungsfaktoren]]
- [[Phasen eines Angriffs]]
- [[Insider Threat]]
- [[Weakness vs. Vulnerability]]
- [[Supply Chain Attack]]

### Terminology
- [[Goals of Cryptography]]
- [[Asset]]
- [[Threat Potential]]
- [[Cyber Kill Chain]]
- [[STRIDE Threat Model]]
	- [[Repudiation]]
- [[symmetric Encryption]]
- [[asymmetric Encryption]]
- [[Safety vs Security]]

## Lifecycle of Products
- ???? #todo

- [[7+1 Digital Security Touchpoints]]
- [[NIST SP 800-64 Lifecycle Model]]
- [[SGP SDLC Model]]

## Technical Basics
- [[Hash-Funktion]]
- [[Pseudo-random Function]]
- [[Kano Modell]]

## Network Security - FINALLYYY SOMETHING REMOTELY USEFUL
- [[4 Grundlagen IT-Sicherheit Netzwerksicherheit SS-2026 1_0.pdf]]
- [[Cybersecurity vs. IT Security]]
- [[Dual Vendor Strategy]]
- [[Security Policy]]
	- [[Whitelisting]]
	- [[Blacklisting]]
- Protocol Attacks
	- [[Angriffe auf IGMP]]
	- [[Angriffe auf IPv4]]
	- [[Angriffe auf UDP]]
	- [[Angriffe auf TCP]]
	- [[Man-in-the-Middle Attack]]
- [[Firewall]]
	- [[Arten von Firewalls]]
		- [[Packet Filtering Firewall]]
- [[Intrusion Detection]]
- [[TLS]]
- [[Authenticated Encrypion]]

### Sicherheitsmodelle
- [[7+1 Digital Security Touchpoints]]
- [[Biba Sicherheitsmodell]]
- [[Bell-Lapadula Sicherheitsmodell]]
- [[Wilson Sicherheitsmodell]]
## Organizational Security
(ich glaube der Mann & Hummel typ)
- [[5 Grundlagen IT-Sicherheit SS-2026 Information Security Management 1_0.pdf]]
- [[ISMS]]
- [[ISO 27001]]
	- [[RPO]]
	- [[RTO]]
	- [[Backup]]
- [[KPI, KGI and KRI]]
- Rechtsgrundlagen in EU:
	- [[eIDAS]]
	- [[Cyber Resiliance Act]]
	- Cyber Security Act (Artikel 22 [[NIS2]])
- [[Electronic Signature]]; [[Signatur vs Seal]]
- [[Entsorgen von kritischen Daten]]

### ISMS Fundamentals
- [[ISMS Top-Down vs Bottom-Up]]
- [[ISMS Certification]]
	- [[ISO 27001 State of Applicability]]
- [[Goals of Cryptography|CIA Triad]]
- [[Vertraulichkeitsstufen]]
- [[Security Controls]]
	- [[Organizational Security Controls]]
	- [[Technical Security Controls]]
- [[PDCA Cycle]]
- [[Risikobehandlung]]
	- [[Wirtschaftlich sinnvolle Risikobehandlung]]
	- [[Risiken abwägen]]
- [[4 Anforderungen an IS Policies]]
- [[Erfolgsfaktoren für ein ISMS]]
- [[Vorteile und Nachteile eines ISMS]]
	- [[Qualität]]

### ISO 27001
- [[ISO 27001]]
	- [[ISO 27001 State of Applicability]]
	- [[ISO 2700x Familie]]
- [[ISMS Quick Wins]]

### Building an ISMS
- [[10 Steps to build an ISMS]]
- [[x509 certificate]]


## Introduction to Cryptography
- [[Encryption]]
- [[Goals of Cryptography|CIA Triad]]
	- [[Security Tradeoffs]]
- [[Security Design Principle]]
	- [[Attacks on Cryptographic Algorithms]]
- Sicherheits-Ebenen
	- [[Computational Hardness]]
	- [[Provable Hardness]]
	- [[Unconditional Hardness]]
- [[Diffie-Hellman Key Exchange]]
- [[One-Time-Pad]]
- [[Vernam Schema]]
- [[PQC]] 
- [[Message Authentication Code]]

#### Randomness
- [[Pseudo-random Function]]
- [[Seed]] 
- [[Perfekter Zufall]]
	- [[Quantum RNG]]
	- [[Linux Randomness]]

### Basics
- [[Encryption]]
- [[Kerckhoff Prinzip]]
- [[Kryptografisches Primitiv vs. Protokoll]]

### Symmetrisch
- [[symmetric Encryption]]
- [[Block Cipher]]
- [[Stream Cipher
- [[AES]]
	- [[AES Modi]] 
	- [[AES State]]

### Assymetrisch
- [[asymmetric Encryption]]
	- [[Private Key]]
	- [[Public Key]]
- [[Digital Signature]]

#### Zertifikate
- [[PKI System]]
- [[Certificate]]
	- [[CSR|Certificate Signing Request]]
	- [[Certificate Authority]]
	- [[Certificate Hierarchy]]
- [[x509 certificate]]
- [[CA Certificate]]


### Hash Funktionen
- [[Hash-Funktion]]
	- [[Kollisionsresistenz]]
	- [[Pre-Image Resistance]]
	- [[Second Pre-Image Resistance]]
- [[Keyed Hash Function]]
- [[Unkeyed Hash Function]]
- [[SHA-256]]
- [[Hash Funktionen in Payment Mechanismen]]
- [[Token]]
- [[Attacks on Hash Functions]]


### Symmetrische Authentifizierung
- [[Message Authentication Code]]

## Tangente zu Quantum Computing😑
- [[Quantum Key Distribution]]
- [[Qubit]]
- [[Photon Polarization]]
- [[Bloch Sphere]]
	- [[Heisenbergsche Unschärferelation]]
- [[Polarized Beam Splitter]]
- [[Quantum Filter]]
	- [[Basis]]
- [[BB84 Protocol]]
	- [[Security of BB84]]

## Defensive Programming (okay nichts spannendes mehr)
- [[Safe Programming]]
- [[Secure Programming]]
- [[CVSS]]
- [[Software Deficit]]
- [[Authentication]], [[Authorization]] und [[Encryption|Cryptography]] 
- [[Session-based Authentication]]
- [[10 Principles of Software Security]]
- [[CWE]]
- [[Password]]
	- [[Password Bruteforce]]
	- [[Dictionary Attack]]
	- [[Password Spraying]]
	- [[Replay Attack]]
- [[TOTP]]

### Patterns
- [[Circle of Trust]]
- [[Identity Provider]]
- [[Authenticator Pattern]]