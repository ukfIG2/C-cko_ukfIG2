#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void pozdrav(){
    printf("Nazdar\n");
}

double obvod_obdlznika(double a, double b){
    //double c = 2*(a+b);
    return printf("%.2f\n",2*(a+b));
    //return printf("%.2f", c);
    // return 2*(a+b);
}

int je_trojuholnik(int a, int b, int c){

    if((a + b > c) && (a + c > b) && (b + c > a)){printf("Trojuholnik je\n");}
    else {printf("Trouholnik neni\n");}

}

void napln_pole_nahodne(int data[], int n, int a, int b){
    for(int i=0; i<n; i++){
        int cislo = a + (rand() % b);
        data[i] = cislo;
    }
}

void vypis_pole(int data[], int n){
    for(int i = 0; i<n; i++){printf("%d__%d\n",i , data[i]);}
    printf("\n");
}

void pomiesaj_pole(int data[], int n){
    for(int i=0; i<n; i++){
        int cislo = rand()%20;
        int a = data[i];
        data[i] = data[cislo];
        data[cislo] = a;
    }
}


int main(){
    int nejakeData[20];
    srand(time(NULL));

    pozdrav();                  //01
    obvod_obdlznika(2.5, 3.2);  //02
    je_trojuholnik(5, 8, 12);   //03
    je_trojuholnik(5, 2, 1);    //04
    napln_pole_nahodne(nejakeData, 20, 10, 100);    //05
    vypis_pole(nejakeData, 20);
    pomiesaj_pole(nejakeData, 20);
    vypis_pole(nejakeData, 20);

}
