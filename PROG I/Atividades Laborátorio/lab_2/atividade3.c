

#include <stdio.h>
#include <stdlib.h>

int main() {

    float n1, n2, n3, media;
    int op;

    printf("Digite 3 valores\n");

    printf("Número 1: ");
    scanf("%f", &n1);

    printf("Número 2: ");
    scanf("%f", &n2);

    printf("Número 3: ");
    scanf("%f", &n3);

    do {

        printf("Qual média deseja calcular? [1] Aritmética [2] Ponderada [3] Harmônica [0] Sair: ");
        scanf("%d", &op);

        if(op == 1) {
            media = (n1 + n2 + n3) / 3;
        }else if(op == 2) {
            media = ( (n1 * 3) + (n2 * 3) + (n3 * 4) ) / (3 + 3 + 4);
        }else if(op == 3) {
            media = 3 / ( (1/n1) + (1/n2) + (1/n3) );
        }

        if (op != 0)
            printf("Média = %.2f\n", media);

    }while(op != 0);

}