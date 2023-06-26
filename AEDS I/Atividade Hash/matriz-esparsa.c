#include "matriz-esparsa.h"

void SparseMatrixInitialize(SparseMatrix *matrix) {
    matrix->rows = (LinkedList *)malloc(sizeof(LinkedList) * MAX);
    matrix->columns = (LinkedList *)malloc(sizeof(LinkedList) * MAX);
}

void SparseMatrixInsert(SparseMatrix *matrix, int r, int c, int value) {
    if (r < 0 || r >= MAX || c < 0 || c >= MAX) {
        printf("Invalid Position!\n");
        exit(-1);
    }

    LinkedListInsert(&matrix->rows[r], c, value);
    LinkedListInsert(&matrix->columns[c], r, value);
};

int SparseMatrixFind(SparseMatrix *matrix, int r, int c) {
    if (r < 0 || r >= MAX || c < 0 || c >= MAX) {
        printf("Invalid Position!\n");
        return -1;
    }

    

    // int find = finfByColumn(&matrix->rows[r], c);

    // if (find == -1) {
    //     //   printf("Not found!");
    //     return -1;
    // }

    // // printf("%d\n", find);
    // return find;
    return matrix->rows[r].first->pos * r * c;
}

void SparseMatrixPrint(SparseMatrix *matrix) {
    // for (int i = 0; i < MAX; i++) LinkedListShowFromBegin(&matrix->rows[i]);

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            Item *atual = matrix->columns[j].first;

            while (atual != NULL) {
                if (atual->pos == i) {
                    printf("%d ", atual->value);
                    break;
                }

                atual = atual->next;
            }

            if (atual == NULL) printf("- ");
        }

        printf("\n");
    }
}
