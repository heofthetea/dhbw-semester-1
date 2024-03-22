#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include <stdbool.h>


int main()
{
    double darlehen = 1e6;
    double zinssatz = .05;
    double anfangs_tilgung = .01;

    double restschuld = darlehen;
    double monatszins = zinssatz / 12;
    double monatliche_annuität = darlehen * (zinssatz + anfangs_tilgung) / 12;
    int monat = 0;
    double bezahlte_zinsen = 0;

    while (restschuld > 0)
    {
        double zinsanteil = restschuld * monatszins;
        bezahlte_zinsen += zinsanteil;

        double tilgungsanteil = monatliche_annuität - zinsanteil;
        restschuld -= tilgungsanteil;
        
        if(monat % 12 == 0) {
            printf("\nJahr: %2d, Restschuld: %.2f, Zinsanteil: %.2f, Tilgungsanteil: %.2f", monat / 12, restschuld, zinsanteil, tilgungsanteil);

        }

        monat ++;
        if(restschuld + (restschuld * monatszins) < monatliche_annuität) {
            zinsanteil = restschuld * monatszins;
            bezahlte_zinsen += zinsanteil;

            restschuld = 0;
        }
    }   

    printf("\n\n Abgeschlossen nach %d Jahren, %d Monaten mit %lf bezahlten Zinsen.", (int)monat / 12, monat % 12, bezahlte_zinsen);
}

