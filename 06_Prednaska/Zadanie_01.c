#include <stdio.h>

#define DVA_NA_31 2147483648

void binarne(unsigned n) {
    unsigned i;

    for (i = DVA_NA_31; i; i = i >> 1) {
        if (i & n)
            printf("1");
        else
            printf("0");
    }
    printf("\n");
}

int main() {
    unsigned operand1, operand2, vysledek;

    printf("Zadajte prve cele cislo: ");
    scanf("%u", &operand1);

    printf("Zadajte druhe cele cislo: ");
    scanf("%u", &operand2);

    // AND
    vysledek = operand1 & operand2;
    printf("AND: %u & %u = %u\n", operand1, operand2, vysledek);
    binarne(vysledek);

    // OR
    vysledek = operand1 | operand2;
    printf("OR: %u | %u = %u\n", operand1, operand2, vysledek);
    binarne(vysledek);

    // XOR
    vysledek = operand1 ^ operand2;
    printf("XOR: %u ^ %u = %u\n", operand1, operand2, vysledek);
    binarne(vysledek);

    // NOT
    vysledek = ~operand1;
    printf("NOT: ~%u = %u\n", operand1, vysledek);
    binarne(vysledek);

    // Bitovy posun doprava
    vysledek = operand1 >> 1;
    printf("Bitovy posun doprava: %u >> 1 = %u\n", operand1, vysledek);
    binarne(vysledek);

    // Bitovy posun dolava
    vysledek = operand1 << 1;
    printf("Bitovy posun dolava: %u << 1 = %u\n", operand1, vysledek);
    binarne(vysledek);

    return 0;
}
