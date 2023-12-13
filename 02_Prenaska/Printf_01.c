#include <stdio.h>

int main(){
    int a = 5256254;
    float b = 6556565.6556;
    printf("%d\n",a);
    printf("%10d\n\n",a); //vypise in 12 miestne s tym ze prve 0 budu null
    printf("ibs f %f\n",b);
    printf("3f %20f\n",b);  //20 miestne??
    printf("%.3f\n",b);
    printf("%2.2f\n",b);

}
