#include <stdio.h>
#include <assert.h>

void vypisPrvky(int a[], int n, int h) {
    assert(h >= 0 && h < n);

    for (int i = 0; i <= h; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int pole[] = {1, 2, 3, 4, 5};
    int velkostPola = sizeof(pole) / sizeof(pole[0]);
    //printf("%d\n",sizeof(pole));
    //printf("%d\n",sizeof(pole[0]));

    vypisPrvky(pole, velkostPola, 2);

    return 0;
}
