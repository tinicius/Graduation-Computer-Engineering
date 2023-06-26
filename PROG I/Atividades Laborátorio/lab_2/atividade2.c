// Uma empresa deseja presentear seus funcionários com um bônus de
// Natal, cujo valor é definido do seguinte modo:
// a. Funcionários do sexo masculino com tempo de casa superior a 15
// anos terão direito a um bônus de 20% do seu salário;
// b. As funcionárias com tempo de casa superior a 10 anos terão direito
// a um bônus de 25% do seu salário; e
// c. os demais funcionários terão direito a um bônus de R$ 100,00.
// Faça um algoritmo que leia o código do funcionário, o sexo, o
// tempo de trabalho (em anos) e o salário. O algoritmo deve calcular
// o valor do bônus

#include <stdio.h>
#include <stdlib.h>

int main() {

    int cod_fun, anos, sexo;
    float salario, bonus;

    printf("Código do funcionário:");
    scanf("%d", &cod_fun);

    printf("Sexo do funcionário: [1] Masculino [2] Feminino: ");
    scanf("%d", &sexo);

    printf("Tempo de trabalho do funcionário:");
    scanf("%d", &anos);

    printf("Sálario do funcionário:");
    scanf("%f", &salario);

    if (sexo == 1) {

        if (anos > 15) {
            bonus = salario * 0.2;
        } else {
            bonus = 100;
        }

    }else {

        if (anos > 10) {
            bonus = salario * 0.25;
        } else {
            bonus = 100;
        }

    }

    printf("Bonus: %.2f\n", bonus);

    return 0;
}