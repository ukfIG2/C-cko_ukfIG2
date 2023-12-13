#include <stdio.h>

int main(){
int cislo = 42;
int *ukazatelNaCislo; // Deklarácia ukazovateľa na int

// Použitie adresového operátora na priradenie adresy premennej ukazateľa
ukazatelNaCislo = &cislo;

// Vypíšeme adresu a hodnotu premennej pomocou ukazovateľa
printf("Adresa premennej 'cislo': %p\n", &cislo);
printf("Adresa premennej 'ukazatelNaCislo': %p\n", ukazatelNaCislo);
printf("Hodnota premennej 'cislo': %d\n", cislo);
printf("Hodnota, na ktorú ukazuje 'ukazatelNaCislo': %d\n", *ukazatelNaCislo);
}
