#include "lista-encadeada.h"

void LinkedListInitialize(LinkedList* list) {
    list->size = 0;
    list->first = NULL;
    list->last = NULL;
}

void LinkedListInsertFront(LinkedList* list, int value) {
    Item* item = (Item*)malloc(sizeof(Item));

    item->value = value;

    if (list->size == 0) {
        list->first = item;
        list->last = item;

        item->next = NULL;
        item->pos = 0;

        list->size++;

        return;
    }

    Item* aux = list->last;  // end

    list->last = item;

    item->next = NULL;
    item->pos = aux->pos + 1;

    aux->next = item;

    list->size++;
}

void LinkedListInsert(LinkedList* list, int pos, int value) {
    Item* item = (Item*)malloc(sizeof(Item));

    item->value = value;
    item->pos = pos;

    // Inserindo no inicio
    list->first = item;
    list->last = item;

    item->next = NULL;

    list->size++;

    // Percorrendo a lista
    Item* novo = list->first;

    Item* atual = list->first->next;

    while (atual != NULL) {
        if (novo->pos > atual->pos) {
            atual->next = novo;

            novo->next = atual->next;

            // Item* aux = atual;
            // atual = novo;
            // novo = aux;
            atual = atual->next;
            novo = novo->next;
        } else
            break;
    }
}

void LinkedListShowFromBegin(LinkedList* list) {
    if (list->size == 0) {
        printf("Empty list!\n");
        return;
    }

    Item* aux = list->first;

    while (aux != NULL) {
        // printf("[%d] = %d ", aux->pos, aux->value);
        printf("%d ", aux->value);

        aux = aux->next;
    }

    printf("\n");
}

void LinkedListFind(LinkedList* list) {}
