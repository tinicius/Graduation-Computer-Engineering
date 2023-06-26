#include <stdlib.h>
#include <stdio.h>

int main() {

    float massa_inicial, massa_atual = 0;
    int tempo_s = 0, tempo_m = 0, tempo_h = 0;

    printf("Digite a massa inicial: ");
    scanf("%f", &massa_inicial);

    massa_atual = massa_inicial;

    while (massa_atual > 0.5)
    {
        massa_atual = massa_atual / 2;
        tempo_s += 50;
    }

    printf("Massa inicial: %.2f\n", massa_inicial);
    
    tempo_h = tempo_s / 3600;
    tempo_m = (tempo_s % 3600) / 60;
    tempo_s = (tempo_s % 3600) % 60;

    printf("Horas: %i\n", tempo_h);
    printf("Minutos: %i\n", tempo_m);
    printf("Segundos: %i\n", tempo_s);

    return 0;
}