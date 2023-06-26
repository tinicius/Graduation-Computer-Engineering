#include <stdlib.h>
#include <stdio.h>

int main() {

    const int num_bois = 10;
    int boi_gordo_id = 0, boi_gordo_peso = 0;

    for(int i = 0; i < num_bois; i++) {

        int id = 0, peso = 0;

        printf("Boi %d\n", i);
        printf("ID: ");
        scanf("%d", &id);
        printf("Peso: ");
        scanf("%d", &peso);
        printf("\n");

        if(peso > boi_gordo_peso) {
            boi_gordo_peso = peso;
            boi_gordo_id = id;
        }
    }

    printf("ID: %d\n", boi_gordo_id);
    printf("Peso: %d\n", boi_gordo_peso);

    return 0;
}