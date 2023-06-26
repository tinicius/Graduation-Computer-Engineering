#include <stdio.h>
#include <stdlib.h>

int main() {

    int n, den = 1;
    float result = 0;

    printf("Digite o numero de termos:");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        float fatorial = 1;

        for (int j = i + 1; j > 0; j--)
        {
            fatorial *= j;
        }

        if (i % 2 == 0) {
            result += fatorial / den;
            den = den * 2 + 1;
        }else {
            result -= fatorial / den;
            den = den * 2 + 1;
        }

    }
    
    printf("%f", result);

    return 0;
}