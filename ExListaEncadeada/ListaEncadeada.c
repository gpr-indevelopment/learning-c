#include "stdlib.h"
#include "string.h"
#include "ListaEncadeada_privado.h"

pLinkedList init() {
    pLinkedList pLinkedList = malloc(sizeof(struct LinkedList));
    pLinkedList->head = NULL;
    pLinkedList->currentSize = 0;
    return pLinkedList;
}

int getSize(pLinkedList pLinkedList) {
    return pLinkedList->currentSize;
}

void* append(pLinkedList pLinkedList, void* element, int elementSize) {
    pLinkedList->currentSize++;
    if (pLinkedList->head == NULL) {
        pLinkedList->head = createNewNode(element, elementSize);
        return pLinkedList->head->element;
    } else {
        pNode lastNode = getLastNode(pLinkedList);
        lastNode->next = createNewNode(element, elementSize);
        return lastNode->next->element;
    }
}

void* prepend(pLinkedList pLinkedList, void* element, int elementSize) {
    pLinkedList->currentSize++;
    if (pLinkedList->head == NULL) {
        pLinkedList->head = createNewNode(element, elementSize);
    } else {
        pNode newHead = createNewNode(element, elementSize);
        newHead->next = pLinkedList->head;
        pLinkedList->head = newHead;
    }
    return pLinkedList->head->element;
}

void* getFirst(pLinkedList pLinkedList) {
    if (pLinkedList->head != NULL) {
        return pLinkedList->head->element;
    } else {
        return NULL;
    }
}

void* getLast(pLinkedList pLinkedList) {
    if (pLinkedList->head != NULL) {
        pNode lastNode = getLastNode(pLinkedList);
        return lastNode->element;
    } else {
        return NULL;
    }
}

void removeFirst(pLinkedList pLinkedList) {
    if (pLinkedList->head != NULL) {
        pLinkedList->currentSize--;
        pNode lastHead = pLinkedList->head;
        pLinkedList->head = pLinkedList->head->next;
        free(lastHead->element);
        free(lastHead);
    }
}

void removeLast(pLinkedList pLinkedList) {
    if (pLinkedList->head != NULL) {
        pLinkedList->currentSize--;
        pNode current = pLinkedList->head;
        pNode previous = NULL;
        while (current->next != NULL) {
            previous = current;
            current = current->next;
        }
        previous->next = NULL;
        free(current->element);
        free(current);
    }
}

pNode createNewNode(void* element, int elementSize) {
    pNode pNode = malloc(sizeof(struct Node));
    pNode->elementSize = elementSize;
    pNode->element = malloc(elementSize);
    memcpy(pNode->element, element, elementSize);
    pNode->next = NULL;
    return pNode;
}

pNode getLastNode(pLinkedList pLinkedList) {
    pNode current = pLinkedList->head;
    while (current->next != NULL) {
        current = current->next;
    }
    return current;
}

void destroy(pLinkedList pLinkedList) {
    while (getSize(pLinkedList) > 0) {
        removeFirst(pLinkedList);
    }
    free(pLinkedList);
}
