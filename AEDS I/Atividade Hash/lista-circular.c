#include "lista-circular.h"

void CircularLinkedListInitialize(CircularLinkedList* list) {
    list->size = 0;
    list->first = NULL;
    list->last = NULL;
}

void CircularLinkedListInsertFront(CircularLinkedList* list, int value) {
    Item* item = (Item*)malloc(sizeof(Item));

    item->value = value;

    list->last = item;
    list->size++;

    if (list->size == 0) {
        list->first = item;
        item->next = item;

        return;
    }

    Item* aux = list->last;  // end

    item->next = list->first;

    aux->next = item;
}

void CircularLinkedListShowFromBegin(CircularLinkedList* list) {
    if (list->size == 0) {
        printf("Empty list!");
        return;
    }

    Item* aux = list->first;

    int count = 0;

    while (aux != NULL) {
        printf("%d ", aux->value);
        aux = aux->next;

        count++;
        if (count == list->size) break;
    }

    printf("\n");
}

void CircularLinkedListShowFromEnd(CircularLinkedList* list) {
    if (list->size == 0) {
        printf("Empty list!");
        return;
    }

    Item* aux = list->last;

    int count = 0;

    while (aux != NULL) {
        printf("%d ", aux->value);
        aux = aux->back;

        count++;
        if (count == list->size) break;
    }

    printf("\n");
}