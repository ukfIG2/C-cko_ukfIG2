#include <stdio.h>
#include <ctype.h>
#include <string.h>


int Kontrola_hesla(char *heslo){
    //int velkost = strlen(heslo);

    int velke_p = 0;
    int male_p = 0;
    int cislice = 0;
    int iny_znak = 0;

    if(strlen(heslo)<=10) {return 1;}
    for(int i=0; i<strlen(heslo); i++){
        if(isdigit(heslo[i])) {cislice++;}
        else if(islower(heslo[i])) {male_p++;}
        else if(isupper(heslo[i])) {velke_p++;}
        else                       {iny_znak++;}
    }
    if((male_p > 0) && (velke_p > 0) && (iny_znak > 0) && (cislice > 1)) {return 0;}
    /*printf("Malych je:%d, Velkych je:%d, inych je:%d, cislic je:%d",
           male_p, velke_p, iny_znak, cislice);*/


}

int main(){
    char heslo[128];
    printf("Zadaj heslo:\n");
    scanf("%s", heslo);
    //printf("%s\n",heslo);
    if(Kontrola_hesla(heslo)==0)    {printf("Heslo je dobre");}
    else {printf("Heslo je zle.");}




    return 0;
}
