#include <stdio.h>
//#include <string.h>

int main(){

    int chars = 0;
    int words = 1;
    int lines = 1;

    char x;
    char lastCh = ' ';

    while ((x = getchar()) != EOF)
    {
        if (x == ' ' && (lastCh >= 'a' && lastCh <= 'z'))   { words++; }
        if (x == '\n')  { lines++; }
        if (x >= 'a' && x <= 'z') { chars++; }  //only alphabetic letters
        lastCh = x;
    }
    printf("\nchars: %d\nwords: %d\nlines: %d\n", chars, words, lines);

    return 0;
}
