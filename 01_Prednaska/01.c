#include <stdio.h>

int main() {
    int x, y, sucet;
    printf("Zadaj 1.cislo:");
    scanf("%d", &x);
    printf("Zadaj 2.cislo:");
    scanf("%d", &y);
    sucet = x+y;
    printf("priemer z %d a %d je %f\nlebo traktor\n", x,y,sucet/2.0);
    return 0;
}
