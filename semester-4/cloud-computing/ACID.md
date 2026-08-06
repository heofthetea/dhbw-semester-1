> Anforderungen an [[Transaktion|Transaktionen]]

### Atomicity
- [[Atom]]
- Eine [[Transaktion]] ist die kleinste, nicht mehr sinnvoll unterteilbare Einheit. Erscheint von außen als eine vollständige Einheit.
### Consistency
- [[Konsistenzüberwachung]]/[[Referenzielle Integrität]]
- Die [[Datenbank]] befindet sich **immer** in einem [[Konsistenzüberwachung|konsistentem]] Zustand
- wenn nicht: [[Rollback]] 
### Isolation
- Jede [[Transaktion]] ist voneinander isoliert, und beeinflussen sich nicht gegenseitig.
- Eine [[Transaktion]] ist bis zu ihrem Commit für andere Transaktionen unsichtbar
### Durability
- Alle Aktionen einer abgeschlossenen [[Transaktion]] bleiben persistent in der [[Datenbank]] erhalten (selbst nach Systemabsturz)