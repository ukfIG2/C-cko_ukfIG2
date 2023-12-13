#ifndef VEKTOR_H
#define VEKTOR_H

typedef struct {
    double x;
    double y;
    double z;
} Vector;

Vector addVectors(Vector v1, Vector v2);
Vector subtractVectors(Vector v1, Vector v2);
double dotProduct(Vector v1, Vector v2);
Vector crossProduct(Vector v1, Vector v2);
double magnitude(Vector v);
Vector normalize(Vector v);

#endif
