#include <stdio.h>
#include <limits.h>

float max_value(float x, float y, float z){
    float max=INT_MIN;
    if (x >= y && x >= z) {
        max = x;
    } else if (y >= x && y >= z) {
        max = y;
    } else {
        max = z;
    }
    return max;
}

int main(){
    int R, G, B;
    float C, M, Y, K;
    printf("Type number: 123|0\n");
    scanf("%d", &R);
    printf("Type number: 44|0\n");
    scanf("%d", &G);
    printf("Type number: 94|0\n");
    scanf("%d", &B);

    if(R==0 & G==0 & B==0) printf("CMYK = 0, 0, 0, 1\n ");
    else {

        float R_= R / 255.0;
        float G_= G / 255.0;
        float B_= B / 255.0;

        K = 1.0-max_value(R_,G_,B_);

        C = (1.0-R_-K)/(1.0-K);
        M = (1.0-G_-K)/(1.0-K);
        Y = (1.0-B_-K)/(1.0-K);

        printf("CMYK = (%.2f, %.2f, %.2f, %.2f)\n)", C, M, Y, K);
    }
    return 0;
}


