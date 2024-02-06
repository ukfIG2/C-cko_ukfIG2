/*
 ============================================================================
 Name        : Gabris_Zaverecna_praca.c
 Author      : Gabris_Ivan
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Uloha 1
typedef struct {
    char adresat[50];
    char miesto_dorucenia[100];
    float hmotnost;
    int poistene;
} TBalik;

//Uloha 1
void nacitajUdaje(TBalik **poleBalikov, int *pocetBalikov) {
    FILE *subor = fopen("udaje.txt", "r");

    if (subor == NULL) {
        printf("Subor sa nepodarilo otvorit.\n");
        exit(EXIT_FAILURE);
    }

    fscanf(subor, "%d", pocetBalikov);

    *poleBalikov = (TBalik*)malloc(sizeof(TBalik) * (*pocetBalikov));

    for (int i = 0; i < *pocetBalikov; i++) {
        fscanf(subor, "%s %s %f %d", (*poleBalikov)[i].adresat, (*poleBalikov)[i].miesto_dorucenia, &(*poleBalikov)[i].hmotnost, &(*poleBalikov)[i].poistene);
    }

    fclose(subor);
}

void vypisUdaje(TBalik *poleBalikov, int pocetBalikov) {
    for (int i = 0; i < pocetBalikov; i++) {
        printf("Adresat: %s, Miesto dorucenia: %s, Hmotnost: %.2f, Poistene: %d\n", poleBalikov[i].adresat, poleBalikov[i].miesto_dorucenia, poleBalikov[i].hmotnost, poleBalikov[i].poistene);
    }
}

// Uloha 2
//Porovnaj z min na max
int porovnaj(const void *a, const void *b) {
    TBalik *balikA = (TBalik*)a;
    TBalik *balikB = (TBalik*)b;

    // Porovnavanie podla hmotnosti
    if (balikA->hmotnost < balikB->hmotnost) {
        return -1;
    } else if (balikA->hmotnost > balikB->hmotnost) {
        return 1;
    } else {
        // Ak su hmotnosti rovnake, porovnavame podla poplatku
        float poplatokA = balikA->poistene ? 4.5 : 3.0;
        float poplatokB = balikB->poistene ? 4.5 : 3.0;

        if ((balikA->hmotnost + poplatokA) < (balikB->hmotnost + poplatokB)) {
            return -1;
        } else if ((balikA->hmotnost + poplatokA) > (balikB->hmotnost + poplatokB)) {
            return 1;
        } else {
            return 0;
        }
    }
}

//porovnaj z max na min
/*int porovnaj(const void *a, const void *b) {
    TBalik *balikA = (TBalik*)a;
    TBalik *balikB = (TBalik*)b;

    // Porovnavanie podla hmotnosti
    if (balikA->hmotnost > balikB->hmotnost) {
        return -1;  // Change to -1 for higher to lower sorting
    } else if (balikA->hmotnost < balikB->hmotnost) {
        return 1;   // Change to 1 for higher to lower sorting
    } else {
        // Ak su hmotnosti rovnake, porovnavame podla poplatku
        float poplatokA = balikA->poistene ? 4.5 : 3.0;
        float poplatokB = balikB->poistene ? 4.5 : 3.0;

        if ((balikA->hmotnost + poplatokA) > (balikB->hmotnost + poplatokB)) {
            return -1;  // Change to -1 for higher to lower sorting
        } else if ((balikA->hmotnost + poplatokA) < (balikB->hmotnost + poplatokB)) {
            return 1;   // Change to 1 for higher to lower sorting
        } else {
            return 0;
        }
    }
}*/

// Uloha 3
int porovnajPodlaAdresata(const void *hladanyAdresat, const void *balik) {
    const char *searchName = (const char *)hladanyAdresat;
    const char *packageName = ((const TBalik *)balik)->adresat;

    //printf("Comparing: %s with %s\n", searchName, packageName);

    return strcasecmp(searchName, packageName);
}

float najdiHmotnostiPodlaAdresata(TBalik *poleBalikov, int pocetBalikov, const char *adresat) {
    TBalik hladanyBalik;
    strcpy(hladanyBalik.adresat, adresat);

    TBalik *najdenyBalik = bsearch(&hladanyBalik, poleBalikov, pocetBalikov, sizeof(TBalik), porovnajPodlaAdresata);

    float hmotnost = 0.0;
    int pocetVyskytov = 0;

    if (najdenyBalik != NULL) {
        int index = najdenyBalik - poleBalikov;
        int i = index;

        while (i >= 0 && strcasecmp(poleBalikov[i].adresat, adresat) == 0) {
            hmotnost += poleBalikov[i].hmotnost;
            i--;
            pocetVyskytov++;
        }

        i = index + 1;
        while (i < pocetBalikov && strcasecmp(poleBalikov[i].adresat, adresat) == 0) {
            hmotnost += poleBalikov[i].hmotnost;
            i++;
            pocetVyskytov++;
        }
    } else {
        printf("Adresat %s neexistuje.\n", adresat);
    }

    printf("Pocet vyskytov, je: %d\n", pocetVyskytov);
    return hmotnost;
}

// Uloha 4
void zapisHmotnostiDoSuboru(TBalik *poleBalikov, int pocetBalikov, const char *subor, const char *miesto) {
    FILE *vystup = fopen(subor, "w");

    if (vystup == NULL) {
        printf("Subor sa nepodarilo otvorit na zapis.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < pocetBalikov; i++) {
        if (strcmp(poleBalikov[i].miesto_dorucenia, miesto) == 0) {
        	fprintf(vystup, "Adresat: %s, Hmotnost: %.2f\n", poleBalikov[i].adresat, poleBalikov[i].hmotnost);
        }
    }

    fclose(vystup);
}

int main() {
    // Uloha 1
    TBalik *poleBalikov;
    int pocetBalikov;

    puts("Uloha 1\nNacitaj udaje.txt");
    nacitajUdaje(&poleBalikov, &pocetBalikov);

    puts("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");

    vypisUdaje(poleBalikov, pocetBalikov);

    puts("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n");

    // Uloha 2
    qsort(poleBalikov, pocetBalikov, sizeof(TBalik), porovnaj);
    puts("Uloha 2\nUsporiadat podla hmotnosti a ceny baliku.");

    puts("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");

    vypisUdaje(poleBalikov, pocetBalikov);

    puts("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n");

    // Uloha 3
    puts("Uloha 3\nNacitaj udaje.txt");
    //Najpr zoradime Adresatov.
    qsort(poleBalikov, pocetBalikov, sizeof(TBalik), porovnajPodlaAdresata);

    puts("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");

    vypisUdaje(poleBalikov, pocetBalikov);

    const char *hladanyAdresat = "Jozef";
    float hmotnost = najdiHmotnostiPodlaAdresata(poleBalikov, pocetBalikov, hladanyAdresat);

    if (hmotnost != 0.0) {
        printf("Hmotnost balikov pre adresata %s je %.2f kg.\n", hladanyAdresat, hmotnost);
    } else {
        printf("Adresat %s neexistuje.\n", hladanyAdresat);
        return 0;
    }

    puts("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n");

    // Uloha 4
    puts("Uloha 4\nVlozenie do subora vystup.txt");
    const char *cieloveMiesto = "Nitra";
    zapisHmotnostiDoSuboru(poleBalikov, pocetBalikov, "vystup.txt", cieloveMiesto);

    free(poleBalikov);


    return 0;
}
