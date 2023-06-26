#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define texto_a "Imprimir o tamanho da string S1. Em seguida, copie a String S1 para uma outra String e concatene a palavra “concatenada” ao fim da String copiada"
#define texto_b "Comparar a string S1 com uma nova string S2 fornecida pelo usuário e imprimir o resultado da comparação. Em seguida, deve-se exibir na tela o resultado da concatenação das 2 Strings"
#define texto_c "Contar quantas vezes um dado caractere C1 aparece na string S1. Em seguida, deve-se substituir a primeira ocorrência do caracter C1, pelo caracter C2. Os caracteres C1 e C2 serão lidos pelo usuário"
#define texto_d "Verificar se uma string S2 é substring de S1. A string S2 também deve ser informada pelo usuário"

int main()
{

    char s1[80], aux;

    printf("Digite o valor de s1: ");
    fgets(s1, 80, stdin);
    s1[strlen(s1) - 1] = '\0';

    int op = 0;
    do
    {
        op = 0;
        printf("\n[1] %s\n", texto_a);
        printf("\n[2] %s\n", texto_b);
        printf("\n[3] %s\n", texto_c);
        printf("\n[4] %s\n\n", texto_d);

        printf("\nDigite uma opcao: ");
        scanf("%i", &op);
        getchar();

        switch (op)
        {
        case 1:
            printf("\nTamanho de s1: %li\n", strlen(s1));
            char string[80];
            strcpy(string, s1);
            // string[strlen(string) - 1] = '\0';
            strcat(string, "concatenada");
            printf("%s\n", string);

            printf("\nAperte enter para continuar...\n");
            scanf("%c", &aux);

            break;

        case 2:

            char s2[80];
            char str[80];

            strcpy(str, s1);

            printf("Digite s2: ");
            fgets(s2, 80, stdin);
            s2[strlen(s2) - 1] = '\0';

            if (strcmp(str, s2) == 0)
            {
                printf("Sao iguais!\n");
            }
            else
            {
                printf("Nao sao iguais!\n");
            }

            printf("%s", strcat(str, s2));

            printf("\nAperte enter para continuar...\n");
            scanf("%c", &aux);

            break;

        case 3:

            int count = 0;
            char c1, c2;

            strcpy(str, s1);

            printf("Digite c1: ");
            scanf("%c", &c1);
            getchar();

            printf("Digite c2: ");
            scanf("%c", &c2);
            getchar();

            for (int i = 0; i < strlen(str); i++)
            {
                if (str[i] == c1)
                {

                    if (count == 0)
                    {
                        str[i] = c2;
                    }

                    count++;
                }
            }
            printf("Contador: %i\n", count);
            printf("%s", str);

            printf("\nAperte enter para continuar...\n");
            scanf("%c", &aux);

            break;

        case 4:

            printf("Digite s2: ");
            fgets(s2, 80, stdin);
            s2[strlen(s2) - 1] = '\0';

            int a = 0;

            for (int i = 0; i < strlen(s1); i++)
            {
                if (s1[i] == s2[a])
                a++;
                {
                    if (a == strlen(s2))
                    {
                        printf("Eh substring\n");

                        printf("\nAperte enter para continuar...\n");
                        scanf("%c", &aux);
                    }
                }
            }

            printf("Nao eh substring\n");
            printf("\nAperte enter para continuar...\n");
            scanf("%c", &aux);

            break;

        default:
            op = 0;
            break;
        }

    } while (op != 0);

    return 0;
}
