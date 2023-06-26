// O hotel Xulambs® cobra R$ 95,00 por dia e mais uma taxa de serviços. A
// taxa de serviços é de: 2,50 por dia, se número de diárias < 15; 1,50 por
// dia, se número de diárias = 15; e 0,50 por dia, se número de diárias > 15.
// Faça um algoritmo que lê o número de diárias e calcula o total a ser pago
// pelo cliente

#include <stdio.h>
#include <stdlib.h>

int main() {

    int diarias = 0;
    float valor_t = 0.0;

    printf("Números de diárias:");
    scanf("%d", &diarias);

    valor_t += 95 * diarias; 

    if (diarias < 15) {
        valor_t += 2.5 * diarias;
    }else if (diarias = 15) {
        valor_t += 1.5 * diarias;
    }else {
        valor_t += 0.5 * diarias;
    }

    printf("Preço final: %.2f\n", valor_t);

    return 0;
}