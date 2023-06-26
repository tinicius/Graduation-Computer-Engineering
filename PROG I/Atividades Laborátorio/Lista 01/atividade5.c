#include <stdlib.h>
#include <stdio.h>

int main () {

    int turmas, alunos_aprovados = 0, reprovados_geral = 0, total_alunos = 0;

    printf("Digite o numero de turmas: ");
    scanf("%d", &turmas);

    for(int i = 0; i < turmas; i++) {

        int alunos, nota_total_turma = 0, reprovados_turma;
        float media;

        printf("Digite o numero de alunos da turma %d: ", i);
        scanf("%d", &alunos);

        total_alunos += alunos;

        for (int j = 0; j < alunos; j++) {

        int nota;

        printf("Digite a nota do aluno %d da turma %d: ", j, i);
        scanf("%d", &nota);

        nota_total_turma += nota;

        if (nota >= 60) {
            alunos_aprovados++;
        }else {
            reprovados_turma++;
            reprovados_geral++;
        }

        }

        media = (float) nota_total_turma / alunos;
        printf("Media da turma: %.2f\n", media);
        printf("Pecentual de reprovados da turma: %.2f %%\n", (100 * reprovados_turma) / alunos);

    }

    printf("\nAlunos aprovados: %d\n", alunos_aprovados);
    printf("Pecentual de todas as turmas: %.2f %%\n", (100 * reprovados_geral) / total_alunos);

    return 0;
}