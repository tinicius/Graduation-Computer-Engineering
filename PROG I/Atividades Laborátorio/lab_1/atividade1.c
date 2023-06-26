#include <stdlib.h>
#include <stdio.h>

int main() {
	
	int num;

	printf("Digite um número: ");
	scanf("%d", &num);

	printf("Antecessor -> %d\n", --num);
	printf("Sucessor -> %d\n", ++num);
	
	return 0;
}
