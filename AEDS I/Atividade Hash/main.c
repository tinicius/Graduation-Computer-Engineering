// #include "lista-circular.h"
// #include "lista-encadeada.h"
#include <time.h>

#include "matriz-esparsa.h"
int main() {
    // CircularLinkedList list;

    // CircularLinkedListInitialize(&list);

    // for (int i = 0; i < 10; i++) {
    //     CircularLinkedListInsertFront(&list, i);
    // }

    // CircularLinkedListShowFromBegin(&list);
    // CircularLinkedListShowFromEnd(&list);

    // LinkedList list;

    // LinkedListInitialize(&list);

    // for (int i = 0; i < 3; i++) {
    //     LinkedListInsertFront(&list, i);
    // }

    // LinkedListInsert(&list, 5, 5);
    // LinkedListInsert(&list, 4, 4);
    // LinkedListInsert(&list, 3, 3);
    // LinkedListInsert(&list, 6, 6);

    // LinkedListShowFromBegin(&list);

    SparseMatrix* matrix = (SparseMatrix*)malloc(sizeof(SparseMatrix));

    SparseMatrixInitialize(matrix);

    srand(time(0));

    SparseMatrixInsert(matrix, 0, 2, 3);
    SparseMatrixInsert(matrix, 0, 1, 2);
    SparseMatrixInsert(matrix, 0, 0, 1);

    LinkedListShowFromBegin(&matrix->rows[0]);

    SparseMatrixPrint(matrix);

    return 0;
}