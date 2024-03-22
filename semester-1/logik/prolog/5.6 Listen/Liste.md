> Wie [[Doubly Linked List|Verkettete Liste]] in anderen Programmiersprachen

$$[Head\ | \ Tail]$$
### Head
- erstes Element der Liste
- beliebiger [[Term]]
### Tail
- Reste der Liste
- alles bis auf das _erste_ Element [[#Head]]
- _ist immer eine Liste_


### Beispiel
```
[ vincent | [ mia | [ jules | [ ]]]]
```
1. Element: vincent
2. Element: mia
3. Element: jules
4. [[Leere Liste]] markiert Ende der Liste


## Alternative Darstellung
- Aufzählung der Elemente
- `[vincent, mia, jules]`
- idR besser als head-tail Notation
- Notationen _können gemischt_ werden: `[vincent, mia | [jules]]`

### Vorteil Pipe-Schreibweise
- Flexibel, wenn Länge der Liste nicht bekannt ist -> "we know the head, the tail can be treated seperately"

## Beispiel
![[Pasted image 20240130150914.png]]

[[Verschachtelte Liste]]
