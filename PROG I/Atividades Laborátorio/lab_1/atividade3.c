#include <stdlib.h>
#include <stdio.h>

int main() {
	
	int num1, num2;

	printf("Digite um número: ");
	scanf("%d", &num1);

	printf("Digite um número: ");
	scanf("%d", &num2);
	
	printf("Dividendo: %d\n", num1);
	printf("Divisor: %d\n", num2);
	printf("Quociente: %d\n", num1 / num2);
	printf("Resto: %d\n", num1 % num2);
	
	return 0;
}
