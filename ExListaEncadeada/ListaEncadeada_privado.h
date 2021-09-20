#include "stdlib.h"
#include "ListaEncadeada_publico.h"

typedef struct Node* pNode;

struct LinkedList {
    pNode head;
    int currentSize;
};

struct Node {
    void* element;
    int elementSize;
    pNode next;
};

pNode createNewNode(void* element, int elementSize);

pNode getLastNode(pLinkedList pLinkedList);