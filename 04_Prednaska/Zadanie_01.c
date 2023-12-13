#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void uprav(const char *vstupny_subor, const char *vystupny_subor) {
    FILE *vstup = fopen(vstupny_subor, "r");
    if (vstup == NULL) {
        perror("Chyba pri otváraní vstupného súboru");
        exit(EXIT_FAILURE);
    }

    FILE *vystup = fopen(vystupny_subor, "w");
    if (vystup == NULL) {
        perror("Chyba pri otváraní výstupného súboru");
        fclose(vstup);
        exit(EXIT_FAILURE);
    }

    char riadok[1000];

    while (fgets(riadok, sizeof(riadok), vstup) != NULL) {
        if (riadok[0] != '\0' && riadok[0] != '\n' && strncmp(riadok, "//", 2) != 0) {
            fputs(riadok, vystup);
        }
    }

    fclose(vstup);
    fclose(vystup);
}

int main() {
    uprav("vstup_01.txt", "vystup_01.txt");

    return 0;
}
