#include <stdio.h>

#define pis(text) printf("%s", text)

#define citaj(retezec) scanf("%s", retezec)

int main(void)
{
  char meno[100];

  pis("Ako sa volas?\n");

  citaj(meno);

  pis(meno);

  pis(" , si super!\n");

  return 0;
}
