#include <stdio.h>

#define DOLNI 0
#define HORNI 300
#define KROK 20
int main(){
    int fahr;
    for(fahr = DOLNI; fahr<=HORNI; fahr+=KROK){
        printf("%3d %6.1f \n ", fahr, (5.0/9)*(fahr-32));
    }
}
