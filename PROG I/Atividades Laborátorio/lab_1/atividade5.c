#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
	
	float raio;

	printf("Digite o raio do circulo: ");
	scanf("%f", &raio);

	printf("Perimetro -> %.2f\n", 2 * 3.14 * raio);
    printf("Area -> %.2f\n", 3.14 * pow(raio, 2));
	
	return 0;
}