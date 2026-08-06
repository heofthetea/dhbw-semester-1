---
aliases:
  - CIA Triad
---
> [!hint] These are only achievable through trust.
> (and cryptographic primitives)

> [!hint] Merkspruch: CIA (Confidentiality, Integrity, Availability)

## Confidentiality
- Message cannot be read from anyone else

## Integrity
- The Message has not been tampered with
- => [[Digital Signature]]

### Indesputability/Repudiation
- once sent, the sender cannot claim that it was not him who sent the message

## Authenticity
- The sender actually is who he claims to be

# Non-Core
## Availability
- Systems should stay [[Verfügbarkeit Informationssysteme|available]]
- REASONABLY available - too long waiting periods are also shit

## Repudiation
- Abstreitbarkeit
- Verträge etc.

## Reliability


## Accountability


# Trade-Offs
- langsame Kryptographie:
	- gute Confidentiality; Integrity für Signaturen
	- schlechtere Availability (langsamer halt nh)
