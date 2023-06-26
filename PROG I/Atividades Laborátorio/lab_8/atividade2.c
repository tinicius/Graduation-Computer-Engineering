#include <stdlib.h>
#include <stdio.h>

void printMatrix(char pascal[80][80], int lines) {

    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < lines; j++) {
            printf(" %c ", pascal[i][j]);
        }

        printf("\n");

    }
}

void readMatrixFromFile(char file[80], char matrix[80][80]) {

    FILE *arq;
    arq = fopen(file, "r");

    for (int i = 0; i < 10; i++) {
        
        for (int j = 0; j < 10; j++) {
            char c = getc(arq);
            matrix[i][j] = c;
        }
    
    }
    
    fclose(arq);

}

int main() {

    char file[80];
    char matrix[80][80];
    
    printf("Digite o nome do arquivo: ");
    scanf("%s", file);

    readMatrixFromFile(file, matrix);
    printMatrix(matrix, 10);

    return 0;
}