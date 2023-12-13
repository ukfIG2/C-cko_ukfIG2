#include <stdio.h>

int main(void) {
    int n, i, a[n];

    printf("pocet prvkov pola n = ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("%d. prvok = ", i + 1);
        scanf("%d", &a[i]);
    }

    printf("\npovodne pole:\n");

    for (i = 0; i < n; i++) printf("%d ", a[i]);

return 0;
}
