#include <stdio.h>
#include <stdlib.h>

int main() {
    char filename[100];

    printf("Zadajte meno suboru: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        perror(filename);
        return 1;
    }

    int c;
    while ((c = fgetc(file)) != EOF) {
        putchar(c);
    }

    fclose(file);

    return 0;
}
