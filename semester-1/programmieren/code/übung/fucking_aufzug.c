

#include <stdint.h>

struct Stockwerk
{
    int stockwerk_nummer;
    uint16_t statuswort;
    int angefordertes_zielstockwerk;
}
Stockwerk;


typedef struct
{
    struct Stockwerk **stockwerke;
    int stw_anzahl, stw_soll, stw_ist, aktion;
} AUFZUG;


AUFZUG *aufzugInit(int anzahlStockwerke)
{
    AUFZUG *lift = malloc(anzahlStockwerke * sizeof(Stockwerk) + 4 * sizeof(int));
    lift->stw_anzahl = anzahlStockwerke;

    for (int i = 0; i < anzahlStockwerke; i++)
    {
        lift->stockwerke[i]->stockwerk_nummer = i + 1; // malloc initialization defaults to zeroes
    }
    return lift;
}

int main()

{
    AUFZUG *lift;
    int anzahlStockwerke;
    scanf("%d", &anzahlStockwerke);

    lift = aufzugInit(anzahlStockwerke);
    while (1)
    {
        uint16_t statuses[anzahlStockwerke];
        for (int i = 0; i < anzahlStockwerke; i++)
        {
            statuses[i] = lift->stockwerke[i];
        }
        int stockwerk_of_lift = get_stockwerk(statuses);
        // aufzugStatus(lift);
        // aufzugAktion(lift);
        sleep(1000);
        printf("hi");
    }

}


// 0 in 9th bit --> not on floor
int on_floor(uint16_t status)
{
    int flag = (status << 9) - 256;
    return flag >= 0;
}

int get_stockwerk(uint16_t *statuses)
{
    int stockwerk;
    for (int i = 0; i < sizeof(statuses) / sizeof(uint16_t); i++)
    {
        if (on_floor(statuses[i]))
        {
            stockwerk = i;
            break;
        }
    }
    return stockwerk;
}



