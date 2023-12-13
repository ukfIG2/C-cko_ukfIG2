 
#include <stdio.h>
#include <stdlib.h>

int **pole2d(int m, int n, int h) {
    int **array = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        array[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            array[i][j] = h;
        }
    }
    return array;
}

void print2DArray(int **array, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int m = 8, n = 6, h = 5;
    int **result = pole2d(m, n, h);
    print2DArray(result, m, n);

    // Free allocated memory
    for (int i = 0; i < m; i++) {
        free(result[i]);
    }
    free(result);

    return 0;
}
