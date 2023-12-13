#include <stdio.h>
#include <stdlib.h>

int compareIntegers(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *array = (int *)malloc(size * sizeof(int));

    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1; // Return an error code
    }

    printf("Enter %d integers for the array:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    qsort(array, size, sizeof(int), compareIntegers);

    printf("Sorted array: ");
    printArray(array, size);

    int searchValue;
    printf("Enter a value to search for: ");
    scanf("%d", &searchValue);

    int *result = (int *)bsearch(&searchValue, array, size, sizeof(int), compareIntegers);

    if (result != NULL) {
        printf("Value %d found in the array\n", searchValue);

        int count = 1;
        int *next = result + 1;

        while (next < array + size && *next == searchValue) {
            count++;
            next++;
        }

        printf("Number of occurrences: %d\n", count);
    } else {
        printf("Value %d not found in the array\n", searchValue);
    }

    free(array);

    return 0;
}
