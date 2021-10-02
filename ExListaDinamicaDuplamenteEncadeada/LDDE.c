#include "stdlib.h"
#include "string.h"
#include "LDDE_privado.h"

pLinkedList init(int elementSize) {
    pLinkedList pLinkedList = malloc(sizeof(struct LinkedList));
    pLinkedList->currentSize = 0;
    pLinkedList->elementSize = elementSize;
    pLinkedList->first = NULL;
    pLinkedList->last = NULL;
    return pLinkedList;
}

void* getFirst(pLinkedList pLinkedList) {
    if (getSize(pLinkedList) == 0) {
        return NULL;
    }
    return pLinkedList->first->element;
}

void* getLast(pLinkedList pLinkedList) {
    if (getSize(pLinkedList) == 0) {
        return NULL;
    }
    return pLinkedList->last->element;
}

void insertLast(pLinkedList pLinkedList, void* element) {
    pNode createdNode = createNode(element, pLinkedList->elementSize);
    pNode currentLast = pLinkedList->last;
    if (currentLast != NULL) {
        currentLast->next = createdNode;
        createdNode->previous = currentLast;
    }
    if (pLinkedList->first == NULL) {
        pLinkedList->first = createdNode;
    }
    pLinkedList->last = createdNode;
    pLinkedList->currentSize++;
}

void insertFirst(pLinkedList pLinkedList, void* element) {
    pNode createdNode = createNode(element, pLinkedList->elementSize);
    pNode currentFirst = pLinkedList->first;
    if (currentFirst != NULL) {
        currentFirst->previous = createdNode;
        createdNode->next = currentFirst;
    }
    if (pLinkedList->last == NULL) {
        pLinkedList->last = createdNode;
    }
    pLinkedList->first = createdNode;
    pLinkedList->currentSize++;
}

void* insertPos(pLinkedList pLinkedList, void* element, int pos) {
    if (pos == 0) {
        insertFirst(pLinkedList, element);
        return pLinkedList->first->element;
    }
    pNode previousNode = getNodeAtPos(pLinkedList, pos-1);
    if (previousNode != NULL) {
        pNode insertedNode = createNode(element, pLinkedList->elementSize);
        insertedNode->previous = previousNode;
        pNode existingNodeAtPos = previousNode->next;
        if (existingNodeAtPos != NULL) {
            insertedNode->next = existingNodeAtPos->next;
            destroyNode(existingNodeAtPos);
        }
        previousNode->next = insertedNode;
        pLinkedList->currentSize++;
        return element;
    }
    return NULL;
}

int getSize(pLinkedList pLinkedList) {
    return pLinkedList->currentSize;
}

void destroy(pLinkedList pLinkedList) {
    pNode nextNode = pLinkedList->first;
    while (nextNode != NULL) {
        pNode currentNode = nextNode;
        nextNode = currentNode->next;
        destroyNode(currentNode);
    }
    free(pLinkedList);
}

void removeFirst(pLinkedList pLinkedList) {
    pNode first = pLinkedList->first;
    if (first->next != NULL) {
        pNode newFirst = first->next;
        pLinkedList->first = newFirst;
        newFirst->previous = NULL;
    } else {
        pLinkedList->first = NULL;
    }
    destroyNode(first);
    pLinkedList->currentSize--;
}

pLinkedList restart(pLinkedList pLinkedList) {
    int elementSize = pLinkedList->elementSize;
    destroy(pLinkedList);
    return init(elementSize);
}

void* get(pLinkedList pLinkedList, int pos) {
    void* result = NULL;
    pNode correspondingNode = getNodeAtPos(pLinkedList, pos);
    if (correspondingNode != NULL) {
        result = correspondingNode->element;
    }
    return result;
}

pNode createNode(void* element, int elementSize) {
    pNode pNode = malloc(sizeof(struct Node));
    void* nodeElement = malloc(elementSize);
    memcpy(nodeElement, element, elementSize);
    pNode->element = nodeElement;
    pNode->next = NULL;
    pNode->previous = NULL;
    return pNode;
}

void destroyNode(pNode pNode) {
    free(pNode->element);
    free(pNode);
}

pNode getNodeAtPos(pLinkedList pLinkedList, int pos) {
    if (pos < 0 || getSize(pLinkedList) <= pos) {
        return NULL;
    }
    pNode currentNode = pLinkedList->first;
    for (int i = 0; i < pos; i++) {
        currentNode = currentNode->next;
    }
    return currentNode;
}