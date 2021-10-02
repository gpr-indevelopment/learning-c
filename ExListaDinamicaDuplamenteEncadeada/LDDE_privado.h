#include "stdlib.h"
#include "LDDE.h"

struct LinkedList {
    pNode first;
    pNode last;
    int currentSize;
    int elementSize;
};

struct Node {
    void* element;
    pNode next;
    pNode previous;
};

pNode createNode(void* element, int elementSize);

void destroyNode(pNode pNode);

pNode getNodeAtPos(pLinkedList pLinkedList, int pos);