[[DB_Kap01_Grundlagen_Stud.pdf]]
Komplett Skript: [[Skript Datenbanken I komplett.pdf]]
Buch: [[Alfons Kemper, André Eickler - Datenbanksysteme. Eine Einführung-Oldenburg Wissenschaftsverlag (2009).pdf]]
### Prüfungsleistung
- Klausur 60% im 4. Semester (60 min)
- Projekt: 40% in Semester 3 & 4 
	- we'll use [[PostgreSQL]]
- [[Tipps Klausur Datenbanken]]
- [[Klausur_Datenbanken_2021_Stud_-_Stark.pdf]]


## Fragenkatalog/Libraries
- [[Datenbanken Fragenkatalog]]
- [[Library Datenbanken 1]]
- [[Library Modellierung]]
- [[Library DB Normalisierung]]
- [[Library Relationale Algebra]]
- [[Library SQL]]
## Projekt
[Link zu moodöl](https://elearning.dhbw-stuttgart.de/moodle/mod/folder/view.php?id=394622)
[[DB_Semesteraufgabe_Studierende.pdf]]
[[Datenbanken Projekt]]
[[DB Beispiel Anforderungsanalyse]]
[[DB Projektidee Ticketsystem]]
[[DB Projektidee Scotland Yard]]
[[Graphdatenbank]]
[[Klassifizierung von Datenbankprodukten_Stud.pdf]]
[[graphdatenbanken_graph.pdf]]
## 01 Grundlagen
[[Datenbank]]
[[Begrifflichkeit Datenbank]]

[[Datenbanksystem]]
[[DBMS]]

[[Hierarchisches Datenmodell]]
[[Netzwerk]]
[[Relationale Datenbank]]
- [[Integration RDB]]
- [[Operation RDB]]
- [[Katalog]]
- [[Benutzersicht]]
- [[Konsistenzüberwachung]]
- [[Zugriffskontrolle RDB]]
- [[Transaktion]]
- [[Synchronisation RDB]]
- [[Datensicherung RDB]]

[[Datenbankmodell]]
[[Datenbankschema]]
[[Datenbanksprache]]

[[Drei-Schichten-Modell]]

[[Datenbank under the hood]]
[[DB Entwurfsprozess]]
[[ACID]]

#### Übungen
[[Übung DB Entwurf Universität]]
### Philosophical stuff lol
[[Von Zeichen zu Wissen]]
[[Information]]
[[Daten]]
[[partielle Schrift]]
[[Geschichte der Datenverarbeitung]]
[[Anforderungen an elektronische Informationsverarbeitung]]

---
## 02 Konzeptioneller Entwurf
[[DB_Kap02_Konzeptioneller DB-Entwurf_Stud.pdf]]

[[Beispiel Softwarehaus Miniwelt]]

[[DB Entwurfsprozess]]
- [[Anforderungsanalyse Datenbank]]
- [[ERM]]
	- [[Entität]]
	- [[Kardinalität]]
	- [[Relationship]]
		- [[n-stellige Relationship]]
		- [[Rekursive Relationship]]
		- [[Is-a Relationship]]
	- [[Attribut]]
		- [[Schlüsselattribut]]
		- [[Spezielle Attribute]]

[[Ablauf ERM Modellierung]]
- [[Sichtenkonsolidierung]]
[[Relationsrichtung eindeutig machen]]

[[Aggregation und Partitionierung]]
- [[Aggregation]]
	- [[Schwacher Entitätstyp]]
- [[Partitionierung]]

#### Übungen
[[Übung Modellierung Computer]]
[[Übung ERM]]
[[Übung ternäre Relation]]
- [[Übung Is-a Relationship]]

## 03 Logischer Entwurf
[[DB_Kap03_Logischer DB-Entwurf_Stud-1.pdf]]
[[Relation]]
[[Relationales Modell]]
- [[Relationship als Relation]]
- [[Rekursive Beziehung als Relation]]
- [[1-1 Beziehung als Relation]]
	- [[Is-a Relationship als Relation]]
- [[Aggregat als Relation]]
- [[n-stellige Relationship als Relation]]
[[Schema einer Relation]]
[[Instanz einer Relation]]
[[Schlüsselattribut]]
[[Relation zu Tabelle]]
[[ERM zu RM]]

[[Von ternärer zu binärer Beziehung]]
### Integrität
[[Referenzielle Integrität]]

### Übungen
[[Übung Anforderungen erstellen]]
[[Übung Relationen Softwarehaus]]
[[Übung ERM Bestellung]]

## 04 Normalisierung
- [[DB_Kap04_Normalisierung_Stud.pdf]]
- [[Normalisierung]]
	- [[1NF]]
	- [[2NF]]
	- [[3NF]]
		- [[Prüfen auf 3NF]]
		- [[Hüllentreue Zerlegung]]
	- [[BCNF]]
		- [[Gültige Zerlegung]]
		- [[Verlustlose Zerlegung]]
- [[Vorgehen Zerlegung]]
- [[Anomalie]]
- [[Projektion]]
- [[Funktionale Abhängigkeit]]
- [[Triviale Funktionale Abhängigkeit]]
	- [[Beispiel Funktionale Abhängigkeit]]
- [[Hülle einer funktionalen Abhängigkeit]]
	- [[Armstrong Axiome]]
- [[Superschlüssel]]
- [[Primattribut]]

#### Beispiele
- [[Beispiel Schlüsselkandidaten]]
- [[Übung 2NF]]
- [[Übung BCNF]]
- [[Übung Normalformen]]

### Gigantische Übung
[[Übung Tierpflege]]

# 4. Semester
### Scripts
```expander
path: datenbanken/scripts
```
[[Anl_Softwarehaus_schema_ohne_FK.sql]]
[[softwarehaus.sql]]

## 5. SQL & Postgres Basics
[[DB_Kap05_Einführung_DB-Entwurf_Stud.pdf]]
- [[SQL Geschichte]]
- [[SQL]] 
- [[PostgreSQL]]
	- [[psql]]
	- [[semester-3/datenbanken/docker-compose.yml|docker-compose]]
	- [[Postgres Architektur]]
	- [[SQL Ebenen]]
- [[DBMS im Vergleich]]
-  [[Mail an Stark Postgres locales]]
- [[dhlgres-Dockerfile]]

## 6. DDL & DML
[[DB_Kap06_1_SQL_DDL_DML_Stud.pdf]]

- [[DDL]]
	- [[SQL create]]
	- [[SQL create table]]
	- [[SQL Constraints]]
		- [[Übung Constraints]]
		- [[Datenbank Indexierung]]
	- [[SQL Drop Column]] 
	- [[Alter Table]]
	- [[Datentyp SQL]]
- [[DML]]
	- [[SQL INSERT]]
	- [[SQL COPY]]
	- [[SQL UPDATE]]
	- [[SQL DELETE]]
		- [[Löschregeln]]
		- [[Updateregeln]]
	- [[Zwischentabelle]]
	- [[SQL Drop Database]]

#### Übungen
- [[Gargantuan Übung Ternäre Beziehung SQL]]
- [[Übung Ternäre Beziehung SQL 1-1-1]] 
- [[Übung Löschregeln]]
- [[Löschregeln ternäre Beziehung]]
- [[Übung Softwarehaus interne Projekte]]

## 6.2 DQL
[[DB_Kap06_2_SQL_DQL_View_Stud.pdf]]
 - [[SQL select]]
	 - [[SQL order by]]
	 - [[SQL Prädikate]]
	 - [[Aggregatsfunktion]]
	 - [[SQL Group By]]
 - [[Abarbeitungsreihenfolge SELECT]]
 - [[Unterabfragen]]
	 - [[Sub-queries mit Relationen]]
 - [[Postgres SERIAL]]
 - [[Abarbeitung einer Abfrage]]
 - [[Unterschied Join und Kreuzprodukt]]
 - [[Join over multiple tables]]
 - [[SQL WITH AS]]

#### Übungen
- [[Übung Select]]
- [[Gargantuan Übung Select]]
- [[Übung Sub-queries]]
- [[Übung Sub-query insert]]
- [[Übung Serial durch Alter Table]]


## 7 Relationale Algebra
- [[DB_Kap07_Relationale Algebra_Stud.pdf]]
- [[Relation]]
- [[Relationale Algebra]]
	- [[Selektion]]
	- [[Projektion]]
	- [[Operationen auf Mengen]]
		- [[Vereinigung]]
		- [[Differenz von Relationen]]
		- [[RelAlg Kreuzprodukt]]
		- [[Umbenennung]]
	- [[Operationen auf Relationen]]
	- [[Operatorbaum]]
		- [[Optimierung Operatorbaum]]
- [[Verkettung]]
- [[RelAlg Aggregation]]
- [[RelAlg Schnitt]]
### Joins
- [[Equi Join]]
- [[Theta Join]]
- [[Natural Join]]
- [[Left outer Join]]
- [[Full Outter Join]]
- [[Semi Join]]

[[Equi Join.pptx]]
### Übungen
- [[Übung Relationale Algebra]]
- [[Übungen vorlesung 13]]


## 8 Views
- [[Benutzersicht]]
- [[SQL View]]
	- [[SQL View Rules]]
	- [[Einfügen in View]]
	- [[Datenunabhängigkeit von View]]
- [[SQL Trigger]]

### Übungen
- [[Übung Views]]


## 9 Transactions
- [[DB_Kap08_TCL_Mehrbenutz.pdf]]
- [[Transaktion]]
	- [[Bestellung Softwarehaus]]
	- [[ACID]]
	- [[Zustand einer Transaktion]]
	- [[Ablauf Transaktion]]
	- [[Nebenläufigkeit]]
		- [[Lost-Update Problem]]
		- [[Dirty Read]]
		- [[Non-Repeatable Read]]
		- [[Phantom Read]]
- [[Isolationslevel]]


## interne Speicherung
- [[DB_Kap09_Interne_Speicherung.pdf]]
## Postgres misc
- [[Postgres locale]]
- [[PGadmin backup]]