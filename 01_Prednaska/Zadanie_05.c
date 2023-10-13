#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int a;
    printf("Zadaj pocet pokusov\n");
    scanf("%d", &a);
    int zoznam[a];

    srand (time(NULL));

    for(int i=0;  i<a;  ++i){
        int b= 1+ (rand() % 5);
        int c= 1+ (rand() % 5);
        zoznam[i]=b+c;
       // printf("jednoltivo %d\n", zoznam[i]);
    }
    /*int Spolu;
    for(int i=0;  i<a;  ++i){
        Spolu+=zoznam[i];
    }*/
    //printf("Spolu %d \n",Spolu);
    for(int i=2;  i<=12; ++i){
        int pomoc;
        for(int j=0; j<a; ++j){
            //int pomoc;
            if(i==zoznam[j]) {pomoc++;}
            //printf("%d sa nachadza %d\n",i,pomoc);
        }
        float percento = (float) pomoc/a*100;
        //printf("%f, %d, %d\n",percento,a,pomoc);
        printf("%d sa nachadza %d krat, co je %.0f%\n",i,pomoc,percento);
        pomoc=0;
    }


    return 0;
}
