#include <stdio.h>
#include "vektor.h"

int main() {
    Vector v1 = {1.0, 2.0, 3.0};
    Vector v2 = {4.0, 5.0, 6.0};

    Vector sum = addVectors(v1, v2);
    Vector difference = subtractVectors(v1, v2);
    double dot = dotProduct(v1, v2);
    Vector cross = crossProduct(v1, v2);
    double mag = magnitude(v1);
    Vector norm = normalize(v1);

    printf("Sum: (%.2f, %.2f, %.2f)\n", sum.x, sum.y, sum.z);
    printf("Difference: (%.2f, %.2f, %.2f)\n", difference.x, difference.y, difference.z);
    printf("Dot Product: %.2f\n", dot);
    printf("Cross Product: (%.2f, %.2f, %.2f)\n", cross.x, cross.y, cross.z);
    printf("Magnitude: %.2f\n", mag);
    printf("Normalized: (%.2f, %.2f, %.2f)\n", norm.x, norm.y, norm.z);

    return 0;
}
