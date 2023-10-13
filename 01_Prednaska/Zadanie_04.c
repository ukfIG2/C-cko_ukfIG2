#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

int main(){
    int team_1_VYHRY = 0;
    int team_2_VYHRY = 0;
    int Kolo = 0;
    char znaky[] = {"KNP"};

    srand (time(NULL));

    while(team_1_VYHRY<5 && team_2_VYHRY<5){
    //while(true){
        //if(team_1_VYHRY==5) break;
       // if(team_2_VYHRY==5) break;
        int Hrac1 = rand() % 3;
        int Hrac2 = rand() % 3;
        //Remiza
        if(Hrac1==0 && Hrac2==0) {++Kolo;}
        if(Hrac1==1 && Hrac2==1) {++Kolo;}
        if(Hrac1==2 && Hrac2==2) {++Kolo;}

        if(Hrac1==0 && Hrac2==1) {team_1_VYHRY++; ++Kolo;}
        if(Hrac1==0 && Hrac2==2) {team_2_VYHRY++; ++Kolo;}

        if(Hrac1==1 && Hrac2==0) {team_2_VYHRY++; ++Kolo;}
        if(Hrac1==1 && Hrac2==2) {team_1_VYHRY++; ++Kolo;}

        if(Hrac1==2 && Hrac2==0) {team_1_VYHRY++; ++Kolo;}
        if(Hrac1==2 && Hrac2==1) {team_2_VYHRY++; ++Kolo;}

        printf("%d. kolo: %c x %c -> %d:%d\n",Kolo,znaky[Hrac1],znaky[Hrac2],team_1_VYHRY,team_2_VYHRY);
    }

    return 0;
}
