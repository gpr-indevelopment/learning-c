#include "stdlib.h"

typedef struct LinkedList* pLinkedList;

typedef struct Node* pNode;

pLinkedList init();

void destroy(pLinkedList pLinkedList);

void restart(pLinkedList pLinkedList);

int getSize(pLinkedList pLinkedList);

void insertFirst();

void insertLast(pLinkedList pLinkedList, void* element);

void insertPos(int pos);

void removeFirst(pLinkedList pLinkedList);

void removeLast(pLinkedList pLinkedList);

void removePos(int pos);

void* getFirst(pLinkedList pLinkedList);

void* getLast(pLinkedList pLinkedList);

void* get(int pos);