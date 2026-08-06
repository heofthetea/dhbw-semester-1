---
aliases:
  - Session
---
> [!error]- Problem: [[HTTP]] ist [[Stateless]]
> Lösungsansätze:
> - Übertragung von hidden fields in [[HTML form]]
> - Speichern in [[Cookie]]
> - Übertragung per [[URL]]
> - Speichern von Informationen in Datei
> - Speichern in [[Datenbank]]

- in der Regel realisiert durch eine session [[Schlüssel|ID]] in  [[Cookie|cookies]]
- Session Data werden temprorär in Server gecached

> [!warning] Nach successful [[Authentication]]: Session ID Ändern!
> - sonst kann angreifer während Login Prozess die Session kapern -> und behält die einfach nach der Authentication

## in PHP
- konfiguriert in `php.ini`
- `session_start()` - [[Singleton]] -> bei jedem Skript aufrufen
- `session_destroy()` - löscht alle temporären Daten & [[Cookie]]