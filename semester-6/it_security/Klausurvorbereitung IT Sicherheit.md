## Beschreiben Sie in ihren eigenen Worten, was sie aus der Lehrveranstalatung mitgenommenhaben und begründen Sie Ihre Auswahl in eigenen Worten
- meint er wirklich so
- "IT Sicherheit ist ein kompletter blödsinn" wäre valid (volle Punktzahl lol)+

## Listen Sie die 7+1 Digital Security Touchpoints auf,  erklären dies eund weisen deren Anwendung in den einzelnen Lebenszyklusphasen software-intensiver Produkte zu. Sortieren Sie die Security Touchpoints nach Effektivität. Erklären Sie in eigenen worten, wodurch die unterschiedliche Effektivitätnzustande kommt. Listen sie drei alternative Lebenszyklusmodelle auf (ohne erklärung).
#todo AUF JEDEN FALL ANSCHAUEN

- [[7+1 Digital Security Touchpoints]]

## Erklären Sie das Bell La-Padula Sicherheitsmodell. Welche Eigenschaft (aus der [[Goals of Cryptography|CIA Triad]]) wird mit der Druchestzung ovn Mandatory Access Clontrol vor allem geschützt? Welche  anwendbaren Regeln werden vor einem Zugriff überprüft?
- [[Goals of Cryptography]]


## Listen Sie anhand von vier Gruppen mögliche Security Controls ("Maßnahmen") auf und erklären diese. In welcher Form können solche Security Controls klassifiziert ewrden und daher vorkommen? Geben Sie Beispiele an und erklären Sie die Gruppen in eigenen Worten. Ist es sinnvoll Security Controls zu kombinieren? (Begründung)
- [[Technical Security Controls]]
- [[Organizational Security Controls]]
- vier gruppen -> [[ISO 27001#Kontrollgruppen]]
- technisch und organisatorische Controls (password policies vs. organisatorisch "nicht teilen")
- Trade-offs zwischen Security controls (z.B. Vertrauenswürdigkeit vs. Integrität)
	- (eine Control kann nicht alles machen ([[Digital Signature]] löst nicht Vertrauenswürdigkeit))
	- 

## Arbeiten Sie die Unterschiede zwischen "Security Target", "Protection Profile", "TOE" (Target of evaluation) und "TSF" (Target of Evaluation Security Functions)  heraus und beschreiben diese. Beantworten Sie auch die Frage, welche Formen von "Security Anforderungen" im Zusammenhang mit Common-Criteria-Zertifizierungen für kryptografische Produkte auftreten können.
- Securty Function Requirements (SFR)
	- z.B. welche Verfahren werden verwendet?
- Securty Assurance Requirements (SAR)

## Wie ist der Pfad vom Asset zum Angriff graphisch darstellbar? Erklären Sie diesen sowie die Unterschiede zwischen Threat Agent, Threat, Vulnerability und Consequence (Loss).


## Beschreiben Sie den Output Feedback Mode des [[AES]] im Verschlüsselungsmodus. Wird dabei ein Initialisierungsvektor verwendet? Wenn ja wann bzs. bei welchem Block, wenn nein, warum nicht? Erfolgt die Verschlüsselung mittels Blöcken oder in Datenströmen und erklären Sie warum es sich um Blöcke (oder Ströme) handelt?
- Block Cipher: feste Datengröße, die verschlüsselt wird (wenn Paket größer ist, wird sie in Blöcke aufgeteilt)
- Stream Cipher: Es wird immer [[Bit]]-weise verschlüsselt
	- ist einfach nur Block Cipher mit Blockgröße 1

## Erklären Sie das Konzept von [[TLS]] Cipher Suites (in Verbindung mit TLS 1.2 oder TLS 1.3) und deren Bedeutung. Geben Sie ein Beispiel und erklären Sie dieses.

- Key Negotiation... ?
- Unterschied:
	- 1.3 hat [[RSA]] nicht mehr im Standard
	- => Cipher Suites deswegen kürzer ([[Elliptic Curves]])