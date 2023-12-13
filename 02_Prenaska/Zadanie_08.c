#include <stdio.h>
#include <string.h>

char* my_strcpy(char *str1, const char *str2)
{
    return strcpy(str1, str2);
    //return(str2, str1);
}
char* my_strcat(char *str1, const char *str2)
{
    return strcat(str1, str2);
}
void my_reverse(char *str)
{
    int dlzka = strlen(str);
    char zrkadlo[dlzka];
    for (int i = 0; i < dlzka; i++)
    {
        char pom = str[i];
        zrkadlo[i] = str[dlzka - i - 2];
        zrkadlo[dlzka - i - 1] = pom;
    }
    printf("%s\n", zrkadlo);
}

int main() {
    //my_strcpy
    char x[] = "nieco nieco";
    char y[] = "lebo lebo";
    /*printf("char x=%s, char y=%s\n", x,y);
    printf("my_strcpy: %s\n", my_strcpy(x, y)); //skopiruje druhy a prehodí ho do prveho (preco ked prehodim premenne, tak nefunguje)
    printf("char x=%s, char y=%s\n\n", x,y);*/
    //my_strcat
    /*printf("char x=%s, char y=%s\n", x,y);
    printf("my_strcat: %s\n", my_strcat(x, y)); //spojí oba retazce do jedneho
    printf("char x=%s, char y=%s\n", x,y);*/

    my_reverse(x); //obrati retazec

    return 0;
}
