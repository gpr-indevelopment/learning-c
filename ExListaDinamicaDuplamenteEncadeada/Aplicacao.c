#include "stdlib.h"
#include "Aplicacao.h"

void whenInitializeListThenItsEmpty() {
    pLinkedList pLinkedList = init();
    int size = getSize(pLinkedList);
    if (size == 0) {
        printf("whenInitializeListThenItsEmpty: Success!\n");
    } else {
        printf("whenInitializeListThenItsEmpty: Failed!\n");
    }
    destroy(pLinkedList);
}

void whenInsertLastAndGetFirstThenSameElementReturns() {
    pLinkedList pLinkedList = init();
    int element = 4;
    insertLast(pLinkedList, &element, sizeof(int));
    int* returnedElement = getFirst(pLinkedList);
    if (*returnedElement == element) {
        printf("whenInsertLastAndGetFirstThenSameElementReturns: Success!\n");
    } else {
        printf("whenInsertLastAndGetFirstThenSameElementReturns: Failed!\n");
    }
    destroy(pLinkedList);
}

void whenInsertLastAndGetLastThenSameElementReturns() {
    pLinkedList pLinkedList = init();
    int element = 4;
    insertLast(pLinkedList, &element, sizeof(int));
    int* returnedElement = getLast(pLinkedList);
    if (*returnedElement == element) {
        printf("whenInsertLastAndGetLastThenSameElementReturns: Success!\n");
    } else {
        printf("whenInsertLastAndGetLastThenSameElementReturns: Failed!\n");
    }
    destroy(pLinkedList);
}

void whenListIsEmptyAndGetFirstThenReturnNull() {
    pLinkedList pLinkedList = init();
    int* returnedElement = getFirst(pLinkedList);
    if (returnedElement == NULL) {
        printf("whenListIsEmptyAndGetFirstThenReturnNull: Success!\n");
    } else {
        printf("whenListIsEmptyAndGetFirstThenReturnNull: Failed!\n");
    }
    destroy(pLinkedList);
}

void whenListIsEmptyAndGetLastThenReturnNull() {
    pLinkedList pLinkedList = init();
    int* returnedElement = getLast(pLinkedList);
    if (returnedElement == NULL) {
        printf("whenListIsEmptyAndGetLastThenReturnNull: Success!\n");
    } else {
        printf("whenListIsEmptyAndGetLastThenReturnNull: Failed!\n");
    }
    destroy(pLinkedList);
}

void whenInsertFirstAndRemoveFirstThenIsEmptyAndGetFirstIsNull() {
    pLinkedList pLinkedList = init();
    int element = 4;
    insertFirst(pLinkedList, &element, sizeof(int));
    removeFirst(pLinkedList);
    int* returnedElement = getFirst(pLinkedList);
    if (getSize(pLinkedList) == 0 && returnedElement == NULL) {
        printf("whenInsertFirstAndRemoveFirstThenIsEmptyAndGetFirstIsNull: Success!\n");
    } else {
        printf("whenInsertFirstAndRemoveFirstThenIsEmptyAndGetFirstIsNull: Failed!\n");
    }
    destroy(pLinkedList);
}

void whenInsertAndRestartThenNewListIsEmpty() {
    pLinkedList pLinkedList = init();
    int element = 4;
    insertFirst(pLinkedList, &element, sizeof(int));
    pLinkedList = restart(pLinkedList);
    int* returnedElement = getFirst(pLinkedList);
    if (getSize(pLinkedList) == 0 && returnedElement == NULL) {
        printf("whenInsertAndRestartThenNewListIsEmpty: Success!\n");
    } else {
        printf("whenInsertAndRestartThenNewListIsEmpty: Failed!\n");
    }
    destroy(pLinkedList);
}

void whenNewListGetElementAt0ReturnsNull() {
    pLinkedList pLinkedList = init(sizeof(int));
    int* returnedElement = get(pLinkedList, 0);
    if (returnedElement == NULL) {
        printf("whenNewListGetElementAt0ReturnsNull: Success!\n");
    } else {
        printf("whenNewListGetElementAt0ReturnsNull: Failed!\n");
    }
    destroy(pLinkedList);
}

void whenInsertElementAndGetPos0ThenReturns() {
    pLinkedList pLinkedList = init();
    int element = 4;
    insertFirst(pLinkedList, &element, sizeof(int));
    int* returnedElement = get(pLinkedList, 0);
    int* returnedElement2 = get(pLinkedList, 1);
    if (*returnedElement == element && returnedElement2 == NULL) {
        printf("whenInsertElementAndGetPos0ThenReturns: Success!\n");
    } else {
        printf("whenInsertElementAndGetPos0ThenReturns: Failed!\n");
    }
    destroy(pLinkedList);
}

void whenInsertAtPos1AndEmptyListThenFailure() {
    pLinkedList pLinkedList = init();
    int element = 4;
    int expectedInserted = insertPos(pLinkedList, &element, sizeof(int), 1);
    if (expectedInserted == 1) {
        printf("whenInsertAtPos1AndEmptyListThenFailure: Success!\n");
    } else {
        printf("whenInsertAtPos1AndEmptyListThenFailure: Failed!\n");
    }
    destroy(pLinkedList);
}

void whenInsertAtPos0AndEmptyListThenSuccess() {
    pLinkedList pLinkedList = init();
    int element = 4;
    int expectedInserted = insertPos(pLinkedList, &element, sizeof(int), 0);
    if (expectedInserted == 0) {
        printf("whenInsertAtPos0AndEmptyListThenSuccess: Success!\n");
    } else {
        printf("whenInsertAtPos0AndEmptyListThenSuccess: Failed!\n");
    }
    destroy(pLinkedList);
}

void whenListHas3ElementsAndInsertOnPos1ThenSuccess() {
    pLinkedList pLinkedList = init();
    char element1[] = "Vou colocar na lista!";
    int element2 = 5;
    int element3 = 6;
    insertLast(pLinkedList, element1, sizeof(element1));
    insertLast(pLinkedList, &element2, sizeof(int));
    insertLast(pLinkedList, &element3, sizeof(int));
    int element4 = 7;
    int insertPosStatus = insertPos(pLinkedList, &element4, sizeof(int), 1);
    char* returnedPos0 = get(pLinkedList, 0);
    int* returnedPos1 = get(pLinkedList, 1);
    int* returnedPos2 = get(pLinkedList, 2);
    if (insertPosStatus == 0
        && *returnedPos1 == element4
        && strcmp(returnedPos0, element1) == 0
        && *returnedPos2 == element3) {
        printf("whenListHas3ElementsAndInsertOnPos1ThenSuccess: Success!\n");
    } else {
        printf("whenListHas3ElementsAndInsertOnPos1ThenSuccess: Failed!\n");
    }
    destroy(pLinkedList);
}

void whenInsertFirstTwoElementsAndRemoveLastThenOnlySecondAddedElementExists() {
    pLinkedList pLinkedList = init();
    int element1 = 4;
    char element2[] = "Vou colocar na lista!";
    insertFirst(pLinkedList, &element1, sizeof(int));
    insertFirst(pLinkedList, element2, sizeof(element2));
    removeLast(pLinkedList);
    int actualSize = getSize(pLinkedList);
    char* returnedPos0 = get(pLinkedList, 0);
    int* returnedPos1 = get(pLinkedList, 1);
    if (actualSize == 1 && strcmp(returnedPos0, element2) == 0 && returnedPos1 == NULL) {
        printf("whenInsertFirstTwoElementsAndRemoveLastThenOnlySecondAddedElementExists: Success!\n");
    } else {
        printf("whenInsertFirstTwoElementsAndRemoveLastThenOnlySecondAddedElementExists: Failed!\n");
    }
    destroy(pLinkedList);
}

void whenInsertFirstTwiceAndGetLastThenFirstElementReturns() {
    pLinkedList pLinkedList = init();
    int element1 = 4;
    int element2 = 5;
    insertFirst(pLinkedList, &element1, sizeof(int));
    insertFirst(pLinkedList, &element2, sizeof(int));
    int* returnedLast = getLast(pLinkedList);
    if (*returnedLast == element1) {
        printf("whenInsertFirstTwiceAndGetLastThenFirstElementReturns: Success!\n");
    } else {
        printf("whenInsertFirstTwiceAndGetLastThenFirstElementReturns: Failed!\n");
    }
    destroy(pLinkedList);
}

void whenInsertFirstAndLastAndGetLastThenFirstSecondElementReturns() {
pLinkedList pLinkedList = init();
    int element1 = 4;
    char element2[] = "Vou colocar na lista!";
    insertFirst(pLinkedList, &element1, sizeof(int));
    insertLast(pLinkedList, element2, sizeof(element2));
    char* returnedLast = getLast(pLinkedList);
    if (strcmp(returnedLast, element2) == 0) {
        printf("whenInsertFirstAndLastAndGetLastThenFirstSecondElementReturns: Success!\n");
    } else {
        printf("whenInsertFirstAndLastAndGetLastThenFirstSecondElementReturns: Failed!\n");
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
    whenInsertAndRestartThenNewListIsEmpty();
    whenNewListGetElementAt0ReturnsNull();
    whenInsertElementAndGetPos0ThenReturns();
    whenInsertAtPos1AndEmptyListThenFailure();
    whenInsertAtPos0AndEmptyListThenSuccess();
    whenListHas3ElementsAndInsertOnPos1ThenSuccess();
    whenInsertFirstTwoElementsAndRemoveLastThenOnlySecondAddedElementExists();
    whenInsertFirstTwiceAndGetLastThenFirstElementReturns();
    whenInsertFirstAndLastAndGetLastThenFirstSecondElementReturns();
}