#include <stdio.h>
#include <string.h>

int my_strlen(const char *s){
    int dlzka = 0;
    while(s[dlzka] != '\0') {dlzka ++;}
    return dlzka-1;
}

void my_gets(char *s, int n){// n je maximálny počet znakov čítaných zo vstupu
    fgets(s, n, stdin);
}

void my_puts(const char *s){
    puts(s);
}

int main(){
    char pom[100];
    char pom2[100];

    puts("Zadaj retazec:");
    fgets(pom, sizeof(pom), stdin);
    printf("Dlzka retazca je: %d\n", my_strlen(pom));
    puts("my_gets");
    my_gets(pom2, 3);
    puts("my_puts");
    my_puts(pom2);

    return 0;
}
