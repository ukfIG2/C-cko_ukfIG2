#include "graf.h"
#include <stdio.h>

int main() {
    TGraf graf;
    citaj(&graf, "vstup.txt");

    printf("Izolovane vrcholy: %d\n", izolovaneVrcholy(&graf));
    printf("Maximalny stupen vrchola: %d\n", maxStupenVrchola(&graf));
    printf("Minimalny stupen vrchola: %d\n", minStupenVrchola(&graf));
    printf("Je pravidelny: %s\n", jePravidelny(&graf) ? "ano" : "nie");
    printf("Je kompletny: %s\n", jeKompletny(&graf) ? "ano" : "nie");
    printf("Je eulerovsky: %s\n", jeEulerovsky(&graf) ? "ano" : "nie");

    return 0;
}
