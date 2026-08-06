> Übersicht, welche Sicherheits-Domänen es gibt

> [!hint] das hier ist von der ID Austria ([[eID]] Österreichs)

[[Microservice]], [[Security by Design]]

![[Pasted image 20260212085217.png]]

#todo wird später drauf eingegangen

#### Was macht was?
 - **Userdomain**: Wo der Endnutzer sich befindet
	 - e.g. Smartphone, unsecured [[WLAN]], etc.
 - **VDA**: Vertrauens-Dienste-Anbieter ([[QTSP]])
	 - e.g. [[Digital Signature]]-Erstellungs-Einheit
 - **[[eIDAS]]-Domain**: [[eID]]s aus anderen EU Ländern
 - **SZRB** - Stammzahl-Registrierungs-Behörde
	 - für das Ableiten einer personenspezifischen ID
	 - dient der Anonymisierung (ein Bereichsspezifisches Kennzeichen kann nicht ohne Mehrinformation auf die physische Identität rückgeführt werden)
 - **Register-Domain**: Unterschiedliche Register (Melderegister, etc)
 - **Attribute-Provider-Domain**: Weitere Attribute
	 - z.B.: Der digitale Führerschein: Hat verschiedene Daten (Austellungsdatum, etc.)
	 - sind verschieden jedes Konzept
 - **IDA-Frontend-Domain**: Sicherstellen, dass alles was geholt wird, in einer korrekten und sicheren Form übermittelt wird
	 - ist in [[ISO 27001]]-zertifiziertem [[Data Center]]

## Wieso macht man das?
### Schnittstellen
- jede Domain hat ein anderes Sicherheitsniveau
	- (vgl. User Domain mit 270001-zertifikiertem RZ)
- => Jede Schnittstelle ist etwas, so man sich drüber Gedanken machen muss
- **Input** - und **Output** - Validierung

> [!hint] Jede Domain vertraut keiner anderen!
> Wenn irgendwo eine Domain komprimiert wird, kann das schnell erkannt werden

### Austauschbarkeit
- Wenn Domäne X komprimiert ist, kann sie sehr einfach ausgetauscht werden