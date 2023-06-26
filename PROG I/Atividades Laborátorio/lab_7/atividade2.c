#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define n 10

int main() {

    int vetor[n];
    float fracao;
    float somatorio = 0, media = 0;
    double res;

    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
        media += vetor[i];
    }

    media = media / n;
    fracao =  (1 / ((float) n - 1));

    for (int i = 0; i < n; i++) {
        somatorio += pow((vetor[i] - media), 2);
    }
    
    res = sqrt(fracao * somatorio);

    printf("%lf\n%lf\n%lf\n", somatorio, fracao,res);

    return 0;
}