#include <stdio.h>
#include <stdlib.h>

void processFile(const char *fileName, char key, int encrypt) {
    FILE *file = fopen(fileName, "rb+");

    if (file == NULL) {
        printf("Nepodarilo sa otvorit subor %s.\n", fileName);
        return;
    }

    int ch;
    while ((ch = fgetc(file)) != EOF) {
        int processedCh;
        if (encrypt) {
            processedCh = ch ^ key;
        } else {
            processedCh = ch ^ key;
        }
        fseek(file, -1, SEEK_CUR);
        fputc(processedCh, file);
    }

    fclose(file);
    if (encrypt) {
        printf("Subor %s bol uspesne zasifrovany.\n", fileName);
    } else {
        printf("Subor %s bol uspesne desifrovany.\n", fileName);
    }
}

int main() {
    int choice;
    char fileName[100];
    char key;

    printf("Vyberte operaciu:\n");
    printf("1. Sifrovanie\n");
    printf("2. Desifrovanie\n");
    scanf("%d", &choice);

    printf("Zadajte nazov suboru: ");
    scanf("%s", fileName);

    printf("Zadajte kluc (jednoznakovy): ");
    scanf(" %c", &key);

    if (choice == 1) {
        processFile(fileName, key, 1);
    } else if (choice == 2) {
        processFile(fileName, key, 0);
    } else {
        printf("Neplatna volba.\n");
        return 1;
    }

    return 0;
}
