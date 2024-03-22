[[NS-Diagramm Annuitäten]]

```python

def calculate_annuität():
	double darlehen: int, zinssatz in range(0, 1), anfangs_tilgung in range(0, 1)
	restschuld = darlehen
	monatliche_annuität = get_annuität(darlehen)
	monatszins = zinssatz / 12
	monat = 0
	bezahlte_zinsen = 0
	
	while restschuld > 0:
		
		zinsanteil = restschuld * monatszins
		bezahlte_zinsen += zinsanteil
		
		tilgungsanteil = monatliche_annuität - zinsanteil
		restschuld = restschuld - tilgungsanteil
		
		if monat % 12 == 0: # first month of year
			print(monat / 12, restschuld, zinsanteil, tilgungsanteil)
	
	
		monat += 1
		if(restschuld + (restschuld * monatszins) < monatliche_annuität):
			zinsanteil = restschuld * monatszins
			bezathlte_zinsen += zinsanteil
		
			restschuld = 0;
	
	print(f"Laufzeit: {monat / 12} Jahre, {monat % 12} monate, {bezahlte_zinsen} bezahlte Zinsen")



def get_annuität(kapital):
	return kapital * (zinssatz + anfangs_tilgung) / 12

```
