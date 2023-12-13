#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


    char* slabiky[] = {"ab", "ac", "ad", "ba", "bb", "bc", "ca", "cb", "cc"};
    int pocet_slabik = sizeof(slabiky) / sizeof(slabiky[0]);

    char* Nahodne_slovo(int pocet){
        char* slovo = malloc(sizeof(pocet) * 5 * sizeof(char));
        slovo[0] = '\0';

        for (int i = 0; i < pocet; i++)
        {
            int random_index = rand() % pocet_slabik;
            strcat(slovo, slabiky[random_index]);
        }

        return slovo;
    }

int main(){
    srand(time(NULL));
    char pom[2];
    int pocet;

    puts("Vloz cislo od 0-10.");
    fgets(pom, sizeof(pom), stdin);
    pocet = atoi(pom);
    printf("Nahodne slovo z %d poctu slabik je: %s\n", pocet, Nahodne_slovo(pocet));

    return 0;
}
