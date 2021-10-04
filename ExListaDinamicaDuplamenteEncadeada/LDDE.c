#include "stdlib.h"
#include "string.h"
#include "LDDE_privado.h"

pLinkedList init() {
    pLinkedList pLinkedList = malloc(sizeof(struct LinkedList));
    pLinkedList->currentSize = 0;
    pLinkedList->first = NULL;
    pLinkedList->last = NULL;
    return pLinkedList;
}

void* getFirst(pLinkedList pLinkedList) {
    if (getSize(pLinkedList) == 0) {
        return NULL;
    }
    int elementSize = pLinkedList->first->elementSize;
    void* result = malloc(elementSize);
    memcpy(result, pLinkedList->first->element, elementSize);
    return result;
}

void* getLast(pLinkedList pLinkedList) {
    if (getSize(pLinkedList) == 0) {
        return NULL;
    }
    int elementSize = pLinkedList->last->elementSize;
    void* result = malloc(elementSize);
    memcpy(result, pLinkedList->last->element, elementSize);
    return result;
}

void insertLast(pLinkedList pLinkedList, void* element, int elementSize) {
    pNode createdNode = createNode(element, elementSize);
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

void insertFirst(pLinkedList pLinkedList, void* element, int elementSize) {
    pNode createdNode = createNode(element, elementSize);
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

int insertPos(pLinkedList pLinkedList, void* element, int elementSize, int pos) {
    if (pos == 0) {
        insertFirst(pLinkedList, element, elementSize);
        pLinkedList->currentSize++;
        return 0;
    }
    pNode previousNode = getNodeAtPos(pLinkedList, pos-1);
    if (previousNode != NULL) {
        pNode insertedNode = createNode(element, elementSize);
        insertedNode->previous = previousNode;
        pNode existingNodeAtPos = previousNode->next;
        if (existingNodeAtPos != NULL) {
            insertedNode->next = existingNodeAtPos->next;
            destroyNode(existingNodeAtPos);
        }
        previousNode->next = insertedNode;
        pLinkedList->currentSize++;
        return 0;
    }
    return 1;
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

void removeLast(pLinkedList pLinkedList) {
    pNode last = pLinkedList->last;
    if (last->previous != NULL) {
        pNode newLast = last->previous;
        pLinkedList->last = newLast;
        newLast->next = NULL;
    } else {
        pLinkedList->last = NULL;
    }
    destroyNode(last);
    pLinkedList->currentSize--;
}

int removePos(pLinkedList pLinkedList, int pos) {
    if (pos == 0) {
        removeFirst(pLinkedList);
        pLinkedList->currentSize--;
        return 0;
    }
    pNode previousNode = getNodeAtPos(pLinkedList, pos-1);
    if (previousNode != NULL) {
        pNode nodeBeingRemoved = previousNode->next;
        if (nodeBeingRemoved != NULL) {
            previousNode->next = nodeBeingRemoved->next;
            nodeBeingRemoved->next->previous = previousNode;
            destroyNode(nodeBeingRemoved);
            pLinkedList->currentSize--;
            return 0;
        }
    }
    return 1;
}

pLinkedList restart(pLinkedList pLinkedList) {
    destroy(pLinkedList);
    return init();
}

void* get(pLinkedList pLinkedList, int pos) {
    void* result = NULL;
    pNode correspondingNode = getNodeAtPos(pLinkedList, pos);
    if (correspondingNode != NULL) {
        int elementSize = correspondingNode->elementSize;
        result = malloc(elementSize);
        memcpy(result, correspondingNode->element, elementSize);
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
    pNode->elementSize = elementSize;
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