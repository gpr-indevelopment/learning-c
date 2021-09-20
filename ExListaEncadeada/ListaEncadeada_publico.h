#include "stdlib.h"

typedef struct LinkedList* pLinkedList;

pLinkedList init();

void* append(pLinkedList pLinkedList, void* element, int elementSize);

void* prepend(pLinkedList pLinkedList, void* element, int elementSize);

void* getFirst(pLinkedList pLinkedList);

void* getLast(pLinkedList pLinkedList);

void removeFirst(pLinkedList pLinkedList);

void removeLast(pLinkedList pLinkedList);

int getSize(pLinkedList pLinkedList);

void destroy(pLinkedList pLinkedList);