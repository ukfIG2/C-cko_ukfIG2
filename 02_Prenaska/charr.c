#include <stdio.h>

int main(){
    int z;
    z = getchar();
    while(z != EOF){
        putchar(z);
        z = getchar();
    }
}
