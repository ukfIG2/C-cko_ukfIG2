#include <stdio.h>
#include <stdlib.h>
int main(){
    int a[10];
    for(int i=0; i<sizeof(a); ++i){
        a[i] = a[i] + 1;
        printf("%d",a[i]);
    }

    return 0;
}
