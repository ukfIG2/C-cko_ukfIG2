#include <stdio.h>

int main(){
    int a=0;

    for(int i=33;  i<=127;  ++i){
        if(a%10==0) getchar();
        a++;
        printf("%d : %c \n", i,i);
    }

    return 0;
}
