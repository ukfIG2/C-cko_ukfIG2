#include <stdio.h>

int main()
{
    int a = 65;
    char str[10];
    for(int i=a;    i<a+10;   i++){
        str[i] = i;
    }
    for(int i=a;    i<a+10;   i++){
        printf("%c",str[i]);
    }
    printf("\n");
    return 0;
}
