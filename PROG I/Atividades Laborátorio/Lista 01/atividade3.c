#include <stdlib.h>
#include <stdio.h>

int main() {

    //Codigo e candidatos/vaga do curso que possui o maior número de candidatos por vaga
    int m_cod = 0;
    float m_vagas = 0;

    int total;

    int cod;
    do {

        int vagas, candidatos_m, candidatos_f;

        printf("Codigo do curso: ");
        scanf("%d", &cod);

        if (cod == 0) {
            break;
        }
        
        printf("Numero de vagas: ");
        scanf("%d", &vagas);

        printf("Numero de candidatos do sexo masculino: ");
        scanf("%d", &candidatos_m);

        printf("Numero de candidatos do sexo feminino: ");
        scanf("%d", &candidatos_f);

        printf("\n");

        float can_por_vagas = (candidatos_f + candidatos_m) / vagas;
        int total_v = candidatos_f + candidatos_m;

        printf("Codigo do curso: %d\n", cod);
        printf("Numero de candidatos por vaga: %.2f\n", can_por_vagas);
        printf("Porcentagem de candidatos do sexo feminino: %.0f %%\n", (candidatos_f * 100.0) / total_v);
        printf("Porcentagem de candidatos do sexo masculino: %.2f %%\n", (candidatos_m * 100.0) / total_v);
        
        if (can_por_vagas > m_vagas) {
            m_vagas = can_por_vagas;
            m_cod = cod;
        }

        total += total_v;

    }while (cod != 0);
    
    printf("Codigo do curso com maior numero de candidatos por vaga: %d\n", m_cod);
    printf("Numero de candidatos por vaga desse curso: %f\n", m_vagas);
    printf("Total de participantes: %d", total);

    return 0;
}