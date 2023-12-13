#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} TBod;

double computeLength(TBod *points, int numPoints) {
    double length = 0;
    for (int i = 1; i < numPoints; i++) {
        length += sqrt(pow(points[i].x - points[i - 1].x, 2) + pow(points[i].y - points[i - 1].y, 2));
    }
    return length;
}

int main() {
    int numPoints;
    printf("Enter the number of points: ");
    scanf("%d", &numPoints);

    TBod *points = (TBod *)malloc(numPoints * sizeof(TBod));

    if (points == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    printf("Enter the coordinates of the points:\n");
    for (int i = 0; i < numPoints; i++) {
        printf("Point %d: ", i + 1);
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }

    double length = computeLength(points, numPoints);
    printf("Length of the line: %lf\n", length);

    free(points);

    return 0;
}
//Pri spustany z terminalu treba dat gcc Zadanie2.c -lm
