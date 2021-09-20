#include "stdlib.h"
#include "Aplicacao.h"

void whenAppendThenSameElementReturns() {
    pLinkedList pLinkedList = init();
    int appended = 2;
    int* actualAppended = append(pLinkedList, &appended, sizeof(int));
    if (*actualAppended == appended) {
        printf("whenAppendThenSameElementReturns: Success!\n");
    } else {
        printf("whenAppendThenSameElementReturns: Failed!\n");
    }
    destroy(pLinkedList);
}

void whenPrependThenSameElementReturns() {
    pLinkedList pLinkedList = init();
    int prepended = 2;
    int* actualPrepended = prepend(pLinkedList, &prepended, sizeof(int));
    if (*actualPrepended == prepended) {
        printf("whenPrependThenSameElementReturns: Success!\n");
    } else {
        printf("whenPrependThenSameElementReturns: Failed!\n");
    }
    destroy(pLinkedList);
}

void whenEmptyThenSizeIs0() {
    pLinkedList pLinkedList = init();
    int size = getSize(pLinkedList);
    if (size == 0) {
        printf("whenEmptyThenSizeIs0: Success!\n");
    } else {
        printf("whenEmptyThenSizeIs0: Failed!\n");
    }
    destroy(pLinkedList);   
}

void whenAppendAndPrependThenSizeIs2() {
    pLinkedList pLinkedList = init();
    int prepended = 2;
    char* appended = "Vou colocar na lista!";
    prepend(pLinkedList, &prepended, sizeof(int));
    append(pLinkedList, appended, sizeof(appended));
    if (getSize(pLinkedList) == 2) {
        printf("whenAppendAndPrependThenSizeIs2: Success!\n");
    } else {
        printf("whenAppendAndPrependThenSizeIs2: Failed!\n");
    }
    destroy(pLinkedList);
}

void whenAppendAndPrependAndRemoveLastAndGetFirstThenPrependReturns() {
    pLinkedList pLinkedList = init();
    int prepended = 2;
    char* appended = "Vou colocar na lista!";
    prepend(pLinkedList, &prepended, sizeof(int));
    append(pLinkedList, appended, sizeof(appended));
    removeLast(pLinkedList);
    int* actualGetFirst = getFirst(pLinkedList);
    int* actualGetLast = getLast(pLinkedList);
    if (*actualGetFirst == prepended && *actualGetLast == prepended) {
        printf("whenAppendAndPrependAndRemoveLastAndGetFirstThenPrependReturns: Success!\n");
    } else {
        printf("whenAppendAndPrependAndRemoveLastAndGetFirstThenPrependReturns: Failed!\n");
    }
    destroy(pLinkedList);
}

void whenAppendAndPrependAndRemoveFirstAndGetLastThenAppendReturns() {
    pLinkedList pLinkedList = init();
    int prepended = 2;
    char appended[] = "Vou colocar na lista!";
    prepend(pLinkedList, &prepended, sizeof(int));
    append(pLinkedList, appended, sizeof(appended));
    removeFirst(pLinkedList);
    char* actualGetFirst = getFirst(pLinkedList);
    char* actualGetLast = getLast(pLinkedList);
    if (strcmp(actualGetFirst, appended) == 0 && strcmp(actualGetLast, appended) == 0) {
        printf("whenAppendAndPrependAndRemoveFirstAndGetLastThenAppendReturns: Success!\n");
    } else {
        printf("whenAppendAndPrependAndRemoveFirstAndGetLastThenAppendReturns: Failed!\n");
    }
    destroy(pLinkedList);
}

int main() {
    whenAppendThenSameElementReturns();
    whenPrependThenSameElementReturns();
    whenEmptyThenSizeIs0();
    whenAppendAndPrependThenSizeIs2();
    whenAppendAndPrependAndRemoveLastAndGetFirstThenPrependReturns();
    whenAppendAndPrependAndRemoveFirstAndGetLastThenAppendReturns();
}