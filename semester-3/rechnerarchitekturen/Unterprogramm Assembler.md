---
aliases:
  - CALL
  - Funktionsaufruf
---
> ist ein [[Makro]]

- [[Adresse]] des [[Programm Counter|Adresszählers]] wird auf [[Stack]] geworfen
  - nach return kann der nächste Befehl in Order ausgeführt werden

```asm
CALL label;
```

- Ende:

```asm
RET;
```

- [[semester-2/algorithmen/Stack#pop|pops]] the stack

> [!warning] Bevor das Unterprogramm definiert wird, muss eine [[Endlosschleife]] eingebaut werden - ansonsten liest das RET einfach irgendeinen Wert vorm [[Stack]]!

### Wichtig

- **immer** CALL - RET
- **nie** CALL - JMP
- **nie** JMP - RET
- möglich:
  - CALL - JMP -RET
  - CALL - CALL - RET - RET

## Beispiel

```asm
	HP1
	HP2
	CALL x
	HP3
	HP4
	CALL x

X:  UP1
	UP2
	RET
```

### Ablauf

1. (evtl. Parameterübergabe: Register, Speicher, Stack)
2. (evtl Retten von Status: PSW, Register,... - _eher unüblich_)
3. CALL
   1. Rücksprungadresse = `(PC)` = Adresse des nächsten Befehls
   2. merken (via [[Stack]] ([[i386]]) oder [[Register]] ([[RISC]]))
4. (evtl. Retten von Status durch Hardware (automatisch))
5. Verzweigen `(PC) = UP adr.`
6. UP abarbeiten
7. (evtl. Retten von Status, Software im UP)
8. (evtl. Parameter lesen von HP)
9. (evtl. Parameter schreiben für HP)
10. (evtl. Status restaurieren)
11. RET `(PC) <- gemerkte Rücksprungadresse`
12. (evtl Status restaurieren durch Hardware)
13. HP macht weiter
14. (evtl Status restaurieren)
15. (evtl. Parameterübergabe von UP)

> [!hint] Restoring sorgt dafür, dass Unterprogramm [[Register]], [[Akkumulator]] etc. manipulieren kann, ohne dass Hauptprogramm was davon mitbekommt

#### Kurz

1.  [[Programm Counter]] merken (über [[Stack]])
2.  [[Programm Counter]] auf [[Adresse]] des 1. Befehls des Unterprogramms setzen
3.  (UP abarbeiten)
4.  Nach return: [[Stack]] poppen; [[Programm Counter]] zurück setzen
