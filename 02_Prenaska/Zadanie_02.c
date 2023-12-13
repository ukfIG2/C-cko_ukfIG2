#include <stdio.h>
#include <string.h>

int main(){
    //char str1 = "Nieco Nieco";
    //char str2 = {'N', 'i', 'e', 'c', 'o', 'l', 'e', 'b', 'o', '\0'};
    //puts("Nieco nieco");
    //puts("Lebo lebo");
    char prvy[50], druhy[50];
    strcpy(prvy, "Nieco nieco.");
    strcpy(druhy, "Lebo lebo.");
    //Vypis zoznamov
    puts(prvy);
    puts(druhy);
    //Dlzka retazca
    printf("Dlzka retazca 1: %d\n", strlen(prvy));
    printf("Dlzka retazca 2: %d\n", strlen(druhy));



    return 0;
}
