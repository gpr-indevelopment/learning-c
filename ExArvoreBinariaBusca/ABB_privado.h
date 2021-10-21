#include <ABB.h>

typedef struct Node* pNode;

struct ABB {
    int currentSize;
    int elementSize;
    pNode rootNode;
};

struct Node {
    void* element;
    pNode leftChildNode;
    pNode rightChildNode;
};

pNode createNode(void* element, int elementSize);

void findAndInsertRecursive(pNode origin, void* element, int elementSize, int (* cmp)(void *p1, void *p2));

void destroySubTreeRecursive(pNode origin);

int findRecursive(pNode origin, void *item, int (* cmp)(void *p1, void *p2));

void visitNodesRecursive(pNode origin, void (* processa)(void *p));