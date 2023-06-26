#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, count = 1;

    printf("Digite o numero de linhas:");
    scanf("%d", &n);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf("%d ", count + j);
        }

        printf("\n");
        count += i;
        
    }
    return 0;

}