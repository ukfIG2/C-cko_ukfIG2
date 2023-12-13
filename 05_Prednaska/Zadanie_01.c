#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define ENTER '\n'
#define POCET_PRVKOV 10

#define naDruhu(x) ((x) * (x))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define jeVelke(c) ((c) >= 'A' && (c) <= 'Z')
#define jeMale(c) ((c) >= 'a' && (c) <= 'z')

int main() {
    printf("TRUE: %d\n", TRUE);
    printf("FALSE: %d\n", FALSE);

    printf("ENTER: %c\n", ENTER);

    printf("POCET_PRVKOV: %d\n", POCET_PRVKOV);

    int x = 5;
    printf("naDruhu(%d): %d\n", x, naDruhu(x));

    int a = 10, b = 20;
    printf("max(%d, %d): %d\n", a, b, max(a, b));
    printf("min(%d, %d): %d\n", a, b, min(a, b));

    char ch = 'A';
    printf("jeVelke('%c'): %d\n", ch, jeVelke(ch));

    ch = 'b';
    printf("jeMale('%c'): %d\n", ch, jeMale(ch));

    return 0;
}
