#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define tam 5

int main() {

    char carros[tam][80];
    double consumo[tam];

    int maior_consumo_pos = 0;
    double maior_consumo = 0;

    for (int i = 0; i < tam; i++)
    {
        printf("Digite o modelo do carro:");
        fgets(carros[i], 80, stdin);

        printf("Digite o consumo do carro:");
        scanf("%lf", &consumo[i]);
        getchar();

        if (consumo[i] >= maior_consumo) {
            maior_consumo = consumo[i];
            maior_consumo_pos = i;
        }

        printf("\nLitros para 1000km: %.2lf\n\n", 1000/consumo[i]);
    
    }

    printf("Modelo mais econômico: %s\n", carros[maior_consumo_pos]);

    return 0;
}