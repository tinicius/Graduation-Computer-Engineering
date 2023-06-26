// Supondo que a população da República Democrática dos Bruzundangas seja da
// ordem de 90.000.000 (noventa milhões) de habitantes com uma taxa anual de
// crescimento de 3% e que a população de um país União Federalista do Milano
// seja de aproximadamente 200.000.000 (duzentos milhões) de habitantes com
// uma taxa anual de crescimento de 1,5%. Usando o comando while, faça um
// algoritmo que calcule e escreva o número de anos necessários para que a
// população dos Bruzundangas alcance ou ultrapasse a população dos Milanos.
// Suponha que serão mantidas essas taxas de crescimento.

#include <stdio.h>
#include <stdlib.h>

int main() {

    int bruzu = 90000000, milano = 200000000, anos = 0;

    while(bruzu <= milano) {

        anos++;

        bruzu += bruzu * 0.03;
        milano += milano * 0.015;
    }

    printf("Anos: %d\", anos);

}