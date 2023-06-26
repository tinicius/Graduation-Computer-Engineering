#include <stdio.h>
#include <stdlib.h>

int main() {

    float e1; 
    int n;
    float e2;

    printf("Digite um numero:");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        e1 = e1 + (i * i);
    }
     
    e2 = (n * (n + 1) * (2 * n + 1)) / 6;

    if(e1 == e2) {
        printf("Verdadeiro");
    }else {
        printf("Falso");
    }

    return 0;
}
