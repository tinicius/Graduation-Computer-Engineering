#ifndef SPARSE_MATRIX_H
#define SPARSE_MATRIX_H

#include "lista-encadeada.h"

typedef struct SparseMatrix SparseMatrix;

#define MAX 10

struct SparseMatrix {
    LinkedList *rows;
    LinkedList *columns;
};

// void initialize(SparseMatrix *matrix){
//     // matrix->rows = malloc(sizeof(List) * MAX);
//     //
// };

void SparseMatrixInitialize(SparseMatrix *matrix);

void SparseMatrixInsert(SparseMatrix *matrix, int r, int c, int value);

int SparseMatrixFind(SparseMatrix *matrix, int r, int c);

void SparseMatrixPrint(SparseMatrix *matrix);

#endif