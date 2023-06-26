#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Item Item;
typedef struct LinkedList LinkedList;

struct Item {
    int value;
    int pos;
    
    Item* next;
};

struct LinkedList {
    int size;

    Item* first;
    Item* last;
};

void LinkedListInitialize(LinkedList* list);

void LinkedListInsert(LinkedList* list, int pos, int value);

void LinkedListInsertFront(LinkedList* list, int value);

void LinkedListShowFromBegin(LinkedList* list);

void LinkedListFind(LinkedList* list);

#endif
