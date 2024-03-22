90 minuten
Richtlinie: ca. 1 minuto pro Punkt
alles sollte in gegebener Zeit machbar sein!!
Abiturprinzip: _Für jede Aufgabe ein neues Blatt_!
_Fachbegriffe_ sind relevant
nur, was _lesbar_ ist, wird bewertet
- (scheiße)


## Aufbau
### 1. fehlerhaftes C source file
- Syntaxfehler erkennen (Kommata, Semikolons, Klammern etc)
- ~10 minuten

### 2. Multiple Choice
- 10 Aussagen
- To choose: _true_ / _false_
- _Beispiel_: "Ein Unterprogramm kann 2 Parameter zurück geben."
- [https://university.quizacademy.io/course/CVAZFV](https://deref-web.de/mail/client/6WQRUJl9nuE/dereferrer/?redirectUrl=https%3A%2F%2Funiversity.quizacademy.io%2Fcourse%2FCVAZFV&lm)
- ~10 minuten

### 3. Kleinere Programme
- einmal ein Struktogramm
- _Beispiel_: "Mach aus for-loop nen while-loop."
- ggf. Prosatexte (Bsp: "Was ist Rekursion? - verbunden mit Transferaufgabe")

### 4. Größeres Programm
- "die guten von den nicht ganz so fitten trennen"
- Aufwand ~40 minuten (mitsamt Struktogramm)
- Beispiel: [[Quick Sort]], _EZB Kontrollsumme?_

## Hilfsmittel
- Keine eigenen Notizen!!
- _Anhang_ (15 - 20 Seiten) enthält:
	- https://elearning.dhbw-stuttgart.de/moodle/pluginfile.php/658880/mod_resource/content/1/Anhang_C_KlausurDS.pdf
	- alle Operatoren
	- ASCII-Tabelle
	- Prototypen der gängigen Funktionen

---
## Tipps
- $2^{16}$ unsigned = `0xffff`
- $2^{15}$ = `0x7fff`, because first 4 bits are $0111_{2}$ and thats $7_{16}$

- consider bit-shifting lul
- `struct` KEYWORD BEFORE NOT TYPEDEFFED STRUCTS
#### malloc
- cast `malloc` pointers
- for array of pointers (`mystruct **arr`):
	1. malloc the array with `malloc(sizeof(mystruct *))`
	2. then malloc each Struct in _for loop_

#### Bubble Sort
- Comparators for `sorted` and `sort` need to point in same direction (duh)
#### Quick Sort
[[Implementation Quick Sort]]
```python
quick_sort(arr, left, right):
	if left >= right:
		return
	pivot = partition()
	quick_sort(left half)
	quick_sort(right half)

partition(arr, left, right):
	# declare helper variables
	i_left, i_right, pivot
	while(i_left < i_right):
		find misplaced elements
		swap misplaced elements

		#adjust for i_left or i_right crossing pivot
		if i_left == pivot:
			pivot = i_right
		increase/decrease i_left and i_right

	return pivot
```