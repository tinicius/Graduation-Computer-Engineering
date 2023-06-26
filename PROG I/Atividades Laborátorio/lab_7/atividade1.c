#include <stdlib.h>
#include <stdio.h>

#define N 3

int main() {

    int matriz[N][N];
    int count = 0;
    int soma_linha = 0, soma_coluna = 0;
    int soma_diagonal_s = 0, soma_diagonal_p = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("> ");
            scanf("%d", &matriz[i][j]);
        }
    }
    
    for (int i = 0; i < 3; i++) {
        soma_linha = 0;
        soma_coluna = 0;

        for (int j = 0; j < 3; j++) {
            soma_linha += matriz[i][j];
            soma_coluna += matriz[j][i];

            if ((i + j) == (N - 1)) {
                soma_diagonal_s += matriz[i][j];
            }
        }

        if (soma_linha != soma_coluna) {
            count++;
        } 

        soma_diagonal_p += matriz[i][i];
    }

    if (soma_linha != soma_diagonal_p || soma_linha != soma_diagonal_s) {
        count++;
    } 

    if (count != 0) {
        printf("Não é um quadrado mágico");
    } else {
        printf("É um quadrado mágico");
    }
    
    return 0;
}