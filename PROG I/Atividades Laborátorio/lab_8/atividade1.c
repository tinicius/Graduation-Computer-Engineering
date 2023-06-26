#include <stdlib.h>
#include <stdio.h>

/*

Solicite ao usuário que ele digite o nome de 2 arquivos e faça uma função
que receba 3 nomes de arquivos (os 2 digitados e o terceiro que será o
nome do arquivo de resultado) e crie um terceiro arquivo com o conteúdo
dos 2 arquivos concatenados.

*/

void writeFile(char file1[80], char file2[80], char file3[]) {

    char content[256];

    FILE *arq;

    arq = fopen(file1, "r");
    fgets(content, 256, arq);
    fclose(arq);

    arq = fopen(file3, "a");
    fputs(content, arq);
    fclose(arq);

    arq = fopen(file2, "r");
    fgets(content, 256, arq);
    fclose(arq);

    arq = fopen(file3, "a");
    fputs(content, arq);
    fclose(arq);

}

int main() {

    char file1[80], file2[80];
    
    printf("Digite o nome do arquivo 1: ");
    scanf("%s", file1);

    printf("Digite o nome do arquivo 2: ");
    scanf("%s", file2);

    writeFile(file1, file2, "a3.txt");

    return 0;
}