#include <stdlib.h>
#include <stdio.h>

#define TAM 15

int main()
{

    int vetor[TAM], n;

    for (int i = 0; i < TAM; i++)
    {

        printf("-> ");
        scanf("%i", &n);

        vetor[i] = n;
    }

    for (int i = 0; i < TAM; i++)
    {
        if (vetor[i] == 0)
        {
            for (int j = i; j < TAM; j++)
            {
                vetor[j] = vetor[j + 1];
            }
        }
    }

    return 0;
}