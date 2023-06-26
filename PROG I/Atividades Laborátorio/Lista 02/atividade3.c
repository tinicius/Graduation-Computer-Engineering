#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{

    char frase[80];
    char final[80];

    printf("Digite uma frase: ");
    fgets(frase, 80, stdin);

    int h = 0;

    for (int i = 0; i < strlen(frase); i++)
    {
        frase[i] = tolower(frase[i]);
    }

    for (int i = 0; i < 80; i++)
    {
        final[i] = '\0';
    }

    for (int i = 0; i < strlen(frase); i++)
    {
        final[strlen(final)] = frase[i + h];

        if (frase[i + h] == 't')
        {

            char aux[20];

            for (int j = 0; j < 7; j++)
            {
                aux[j] = frase[i + h + j];
            }

            if (strcmp(aux, "teclado") == 0)
            {
                for (int j = 1; j < 7; j++)
                {
                    final[strlen(final)] = frase[i + j + h];
                }

                strcat(final, " ou mouse");
                h += 6;
            }
        }

        
    }

    printf("%s", final);
    
    return 0;
}
