#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main () {

    double x_graus, x_rad, cos_n = 1;
    int n, pot = 0, fat = 1;

    printf("Digite o valor de x: ");
    scanf("%lf", &x_graus);

    x_rad = x_graus * (M_PI / 180);

    printf("Digite o valor de n: ");
    scanf("%d", &n);

    for (int i = 1; i < n; i++){

        pot += 2;
        fat = 1;

        for(int j=pot; j>0; j--) {
            fat = fat * j;
        }

        if(i % 2 == 0) {
            double den = pow(x_rad, pot);

            cos_n += den / fat;
        } else {
            double den = pow(x_rad, pot);
            
            cos_n -= den / fat;
        }
        
    }
    
    printf("Cosseno calculado com n termos: %lf\n", cos_n);
    printf("Valor da função COS(X): %lf\n", cos(x_rad));

    printf("Diferenca: %lf\n", cos_n - cos(x_rad));

    return 0;
}