#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Item Item;
typedef struct CircularLinkedList CircularLinkedList;

struct Item {
    int value;

    Item* next;
    Item* back;
};

struct CircularLinkedList {
    int size;

    Item* first;
    Item* last;
};

void CircularLinkedListInitialize(CircularLinkedList* list);

void CircularLinkedListInsertFront(CircularLinkedList* list, int value);

void CircularLinkedListShowFromBegin(CircularLinkedList* list);

void CircularLinkedListShowFromEnd(CircularLinkedList* list);

#endif
