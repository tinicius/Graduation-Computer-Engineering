#include <stdlib.h>
#include <stdio.h>

void printPascalTriangle(int pascal[80][80], int lines) {

    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < lines; j++) {

            if (i >= j)
                printf(" %d ", pascal[i][j]);
            
        }

        printf("\n");

    }
}

void readLines(int* lines) {
    printf("Digite o número de linhas:");
    scanf("%d", lines);
}

void calculatePascalTriangle(int matriz[80][80], int lines) {
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < lines; j++) {

            if (i == j || j == 0)
                matriz[i][j] = 1;
            
            else {
                for (int k = 0; k < (i - 1); k++) {
                    matriz[i][k + 1] = matriz[i - 1][k] + matriz[i - 1][k + 1];
                }
            }
        }
    }
}

int main() {

    int lines;
    readLines(&lines);

    int pascal[80][80];
    calculatePascalTriangle(pascal, lines);
    
    printPascalTriangle(pascal, lines);

    return 0;
}