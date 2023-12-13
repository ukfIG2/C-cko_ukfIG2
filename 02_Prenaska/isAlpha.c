#include <stdio.h>
#include <ctype.h>
int main()
{
    char c;

    printf("Enter a character: ");
    scanf("%c", &c);

    if (isalpha(c) == 0)
        printf("%c is not an alphabet.", c);
    else
        printf("%c is an alphabet.", c);

    return 0;
}
