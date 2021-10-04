#include "stdlib.h"
#include "LDDE.h"

typedef struct Node* pNode;

struct LinkedList {
    pNode first;
    pNode last;
    int currentSize;
};

struct Node {
    void* element;
    int elementSize;
    pNode next;
    pNode previous;
};

pNode createNode(void* element, int elementSize);

void destroyNode(pNode pNode);

pNode getNodeAtPos(pLinkedList pLinkedList, int pos);