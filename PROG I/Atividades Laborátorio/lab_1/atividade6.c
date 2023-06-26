// O custo ao consumidor, de um carro novo, é a soma do custo de fábrica com a
// percentagem do distribuidor e dos impostos (aplicado ao custo da fábrica). Supondo
// que a percentagem do distribuidor seja de 28% e os impostos de 45%, faça um
// algoritmo para ler o custo de fábrica de um carro e escrever o custo ao consumidor.

#include <stdlib.h>
#include <stdio.h>

int main() {
	
	float custo_final, custo_fab;

	printf("Digite o custo de fabrica: ");
	scanf("%f", &custo_fab);

    custo_final = custo_fab + custo_fab * 0.28 + custo_fab * 0.45;

	printf("Custo final -> %.2f\n", custo_final);
	
	return 0;
}