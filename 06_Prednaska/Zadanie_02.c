#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define NUM_SECONDS 6000 // 100 minút simulácie

typedef struct {
    uint8_t fuel : 1;       // palivo
    uint8_t power : 1;      // elektrická energia
    uint8_t radio : 1;      // rádiové spojenie
    uint8_t tv_signal : 1;  // televízny signál
    uint8_t water : 1;      // voda
    uint8_t air : 1;        // vzduch
    uint8_t food : 1;       // jedlo
    uint8_t waste : 1;      // odpad
} Status;

int main() {
    Status status;
    FILE *file = fopen("simulation_data.bin", "wb");

    if (file == NULL) {
        printf("Nepodarilo sa otvoriť súbor pre záznamy.\n");
        return 1;
    }

    for (int second = 0; second < NUM_SECONDS; ++second) {
        status.fuel = rand() % 2;
        status.power = rand() % 2;
        status.radio = rand() % 2;
        status.tv_signal = rand() % 2;
        status.water = rand() % 2;
        status.air = rand() % 2;
        status.food = rand() % 2;
        status.waste = rand() % 2;

        fwrite(&status, sizeof(Status), 1, file);
    }

    fclose(file);
    printf("Simulácia dokončená. Výsledky sú uložené v súbore 'simulation_data.bin'.\n");

    return 0;
}
