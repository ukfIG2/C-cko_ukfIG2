#include <stdio.h>
#include <string.h>

int main(){
    char str1[] = "Bratislava";
    char str2[] = {'N', 'i', 't', 'r', 'a' , '\0'};
    char meno[25], priezvisko[25];

    int i;

    puts("Tvoje meno:");
    fgets(meno, 25, stdin);

    puts("Tvoje priezvisko:");
    fgets(priezvisko, 25, stdin);

    puts(str1);
    printf(str2);
    printf("\nVolas sa %s %s.\n", meno, priezvisko);

    return 0;
}
