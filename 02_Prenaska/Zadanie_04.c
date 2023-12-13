#include <stdio.h>
#include <ctype.h>
#include <string.h>

int male_velke(char *s, int *m, int *v){
    *m = 0;
    *v = 0;
    if(*s =='\0') {return 0;}

    for(int i=0; i<strlen(s); i++){
        if(islower(s[i]))   {(*m)++;}
        else if(isupper(s[i]))      {(*v)++;}
    }
    return 1;
}

int main(){
    int male, velke;
    char retazec[100];

    printf("Zadaj retazec: ");
    scanf("%s", retazec);

    if(male_velke(retazec, &male, &velke) == 1) {printf("Retazec "
               "obsahuje %d malych a %d velkych pismen.", male, velke);}
    else {printf("Retazec je prazdny.");}
}
