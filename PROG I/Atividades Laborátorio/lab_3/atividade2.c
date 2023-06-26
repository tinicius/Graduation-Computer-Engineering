#include <stdlib.h>
#include <stdio.h>

int main()
{

    int t, n1, n2;

    printf("Digite o numero de termos:");
    scanf("%d", &t);

    printf("Digite o primeiro termo:");     
    scanf("%d", &n1);

    printf("Digite o segundo termo:");     
    scanf("%d", &n2);

    printf("%d %d ", n1, n2);

    for (int i = 0; i < t; i++)
    {
        int n3 = n2 + n1;

        n1 = n2;
        n2 = n3;

        printf("%d ", n3);
    }
    
    return 0;
}
