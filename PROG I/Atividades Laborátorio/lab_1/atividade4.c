#include <stdlib.h>
#include <stdio.h>

int main() {
	
	float base, altura;

	printf("Digite o valor da base: ");
	scanf("%f", &base);

    printf("Digite o valor da altura: ");
	scanf("%f", &altura);

	printf("Perimetro -> %.2f\n", (base * 2) + (altura * 2));
    printf("Area -> %.2f\n", base * altura);
	
	return 0;
}