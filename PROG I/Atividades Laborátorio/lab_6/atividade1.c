#include <stdlib.h>
#include <stdio.h>

int main()
{

    int m[4][6];
    int n[6][4];

    int res[3][3];

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            scanf("%d", &m[i][j]);
        }
        
    }
    
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            scanf("%d", &n[i][j]);
        }
        
    }
    
    for (int i = 0; i < 6; i++) {

        for (int j = 0; j < 6; j++)
        {
            
            int a = 0;
            for (int h = 0; h < 4; h++)
            {
                a += (m[i][h] * n[h][j]); 
            }
            res[i][j] = a;
            printf("[%d][%d] = %d\n", i, j, res[i][j]);
        }
        
    }

    return 0;
}