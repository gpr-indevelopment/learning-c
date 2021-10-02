#include "stdlib.h"
#include "Aplicacao.h"

void whenInitializeListThenItsEmpty() {
    pLinkedList pLinkedList = init(sizeof(int));
    int size = getSize(pLinkedList);
    if (size == 0) {
        printf("whenInitializeListThenItsEmpty: Success!\n");
    } else {
        printf("whenInitializeListThenItsEmpty: Failed!\n");
    }
    destroy(pLinkedList);
}

void whenInsertLastAndGetFirstThenSameElementReturns() {
    pLinkedList pLinkedList = init(sizeof(int));
    int element = 4;
    insertLast(pLinkedList, &element);
    int* returnedElement = getFirst(pLinkedList);
    if (*returnedElement == element) {
        printf("whenInsertLastAndGetFirstThenSameElementReturns: Success!\n");
    } else {
        printf("whenInsertLastAndGetFirstThenSameElementReturns: Failed!\n");
    }
    destroy(pLinkedList);
}

void whenInsertLastAndGetLastThenSameElementReturns() {
    pLinkedList pLinkedList = init(sizeof(int));
    int element = 4;
    insertLast(pLinkedList, &element);
    int* returnedElement = getLast(pLinkedList);
    if (*returnedElement == element) {
        printf("whenInsertLastAndGetLastThenSameElementReturns: Success!\n");
    } else {
        printf("whenInsertLastAndGetLastThenSameElementReturns: Failed!\n");
    }
    destroy(pLinkedList);
}

void whenListIsEmptyAndGetFirstThenReturnNull() {
    pLinkedList pLinkedList = init(sizeof(int));
    int* returnedElement = getFirst(pLinkedList);
    if (returnedElement == NULL) {
        printf("whenListIsEmptyAndGetFirstThenReturnNull: Success!\n");
    } else {
        printf("whenListIsEmptyAndGetFirstThenReturnNull: Failed!\n");
    }
    destroy(pLinkedList);
}

void whenListIsEmptyAndGetLastThenReturnNull() {
    pLinkedList pLinkedList = init(sizeof(int));
    int* returnedElement = getLast(pLinkedList);
    if (returnedElement == NULL) {
        printf("whenListIsEmptyAndGetLastThenReturnNull: Success!\n");
    } else {
        printf("whenListIsEmptyAndGetLastThenReturnNull: Failed!\n");
    }
    destroy(pLinkedList);
}

void whenInsertFirstAndRemoveFirstThenIsEmptyAndGetFirstIsNull() {
    pLinkedList pLinkedList = init(sizeof(int));
    int element = 4;
    insertFirst(pLinkedList, &element);
    removeFirst(pLinkedList);
    int* returnedElement = getFirst(pLinkedList);
    if (getSize(pLinkedList) == 0 && returnedElement == NULL) {
        printf("whenInsertFirstAndRemoveFirstThenIsEmpty: Success!\n");
    } else {
        printf("whenInsertFirstAndRemoveFirstThenIsEmpty: Failed!\n");
    }
    destroy(pLinkedList);
}

int main() {
    whenInitializeListThenItsEmpty();
    whenInsertLastAndGetFirstThenSameElementReturns();
    whenInsertLastAndGetLastThenSameElementReturns();
    whenListIsEmptyAndGetFirstThenReturnNull();
    whenListIsEmptyAndGetLastThenReturnNull();
    whenInsertFirstAndRemoveFirstThenIsEmptyAndGetFirstIsNull();
}