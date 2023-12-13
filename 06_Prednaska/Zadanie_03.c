#include <stdio.h>

unsigned char rotateLeft(unsigned char byte, int n) {
    n = n % 8; // Zabezpečuje, aby posun bol v rozsahu 0-7

    return (byte << n) | (byte >> (8 - n));
}

int main() {
    unsigned char inputByte = 0xA0; // 10100000 v binárnom formáte

    printf("Pred rotáciou: 0x%X\n", inputByte);

    // Rotácia o 1 bit vľavo
    unsigned char rotatedByte = rotateLeft(inputByte, 1);

    printf("Po rotácii: 0x%X\n", rotatedByte);

    return 0;
}
