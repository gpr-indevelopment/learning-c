#include <Fila_publico.h>
#include <stdio.h>
#include <string.h>

void whenQueueStartsThenItsEmpty() {
    pQueue pQueue = init(10);
    int resultIsEmpty = isEmpty(pQueue);
    if(resultIsEmpty == 1) {
        printf("whenQueueStartsThenItsEmpty: Success!\n");
    } else {
        printf("whenQueueStartsThenItsEmpty: Failed!\n");
    }
}

void whenQueueIsDestroyedThenSuccess() {
    pQueue pQueue = init(10);
    destroy(pQueue);
    printf("whenQueueIsDestroyedThenItsNull: Success!\n");
}

void whenEnqueueThenReturnsTheQueuedElement() {
    pQueue pQueue = init(10);
    int element = 4;
    int* returnedElement = enqueue(pQueue, &element, sizeof(int));
    if(*returnedElement == element) {
        printf("whenEnqueueThenReturnsTheQueuedElement: Success!\n");
    } else {
        printf("whenEnqueueThenReturnsTheQueuedElement: Failed!\n");
    }
}

void whenQueueIsFullThenIsFull() {
    pQueue pQueue = init(1);
    int element = 4;
    enqueue(pQueue, &element, sizeof(int));
    enqueue(pQueue, &element, sizeof(int));
    int resultIsFull = isFull(pQueue);
    if (resultIsFull == 1) {
        printf("whenQueueIsFullThenIsFull: Success!\n");
    } else {
        printf("whenQueueIsFullThenIsFull: Failed!\n");
    }
}

void whenEnqueueOnFullListThenReturnsNull() {
    pQueue pQueue = init(1);
    int element = 4;
    int* enqueuedElement1 = enqueue(pQueue, &element, sizeof(int));
    int* enqueuedElement2 = enqueue(pQueue, &element, sizeof(int));
    if (enqueuedElement2 == NULL && *enqueuedElement1 == element) {
        printf("whenEnqueueOnFullListThenReturnsNull: Success!\n");
    } else {
        printf("whenEnqueueOnFullListThenReturnsNull: Failed!\n");
    }
}

void whenDequeueAndQueueIsEmptyThenReturnsNull() {
    pQueue pQueue = init(10);
    int* dequeuedElement = dequeue(pQueue);
    if(dequeuedElement == NULL) {
        printf("whenDequeueAndQueueIsEmptyThenReturnsNull: Success!\n");
    } else {
        printf("whenDequeueAndQueueIsEmptyThenReturnsNull: Failed!\n");
    }
}

void whenEnqueueAndDequeueTheSameElementReturns() {
    pQueue pQueue = init(10);
    int element = 4;
    int* enqueuedElement = enqueue(pQueue, &element, sizeof(int));
    int* dequeuedElement = dequeue(pQueue);
    if(*enqueuedElement == *dequeuedElement && *dequeuedElement == element) {
        printf("whenEnqueueAndDequeueTheSameElementReturns: Success!\n");
    } else {
        printf("whenEnqueueAndDequeueTheSameElementReturns: Failed!\n");
    }
}

void whenEnqueueAndMaxSizeIsOneThenDequeueCorrectly() {
    pQueue pQueue = init(1);
    int element1 = 4;
    char element2[] = "Some_string";
    enqueue(pQueue, &element1, sizeof(int));
    int* dequeuedElement1 = dequeue(pQueue);
    enqueue(pQueue, element2, sizeof(element2));
    char* dequeuedElement2 = dequeue(pQueue);
    if(*dequeuedElement1 == element1 && strcmp(dequeuedElement2, element2) == 0) {
        printf("whenEnqueueAndMaxSizeIsOneThenDequeueCorrectly: Success!\n");
    } else {
        printf("whenEnqueueAndMaxSizeIsOneThenDequeueCorrectly: Failed!\n");
    }
}

void whenEnqueueSameDataTypesThenDequeuesCorrectly() {
    pQueue pQueue = init(3);
    int someInt1 = 2;
    int someInt2 = 5;
    int someInt3 = 39;
    enqueue(pQueue, &someInt1, sizeof(int));
    enqueue(pQueue, &someInt2, sizeof(int));
    enqueue(pQueue, &someInt3, sizeof(int));
    int* dequeuedElement1 = dequeue(pQueue);
    printf("%d\n", *dequeuedElement1);
    int* dequeuedElement2 = dequeue(pQueue);
    printf("%d\n", *dequeuedElement2);
    int* dequeuedElement3 = dequeue(pQueue);
    if(*dequeuedElement1 == someInt1 
        && *dequeuedElement2 == someInt2
        && *dequeuedElement3 == someInt3) {
        printf("whenEnqueueSameDataTypesThenDequeuesCorrectly: Success!\n");
    } else {
        printf("whenEnqueueSameDataTypesThenDequeuesCorrectly: Failed!\n");
    }
}

void whenAddDifferentDataTypesToQueueThenDequeuesCorrectly() {
    pQueue pQueue = init(3);
    char strElement[] = "Some_string";
    int someInt = 5;
    long someLong = 123456789111;
    enqueue(pQueue, &someInt, sizeof(int));
    enqueue(pQueue, &someInt, sizeof(int));
    //enqueue(pQueue, strElement, sizeof(strElement));
    int* dequeuedElement1 = dequeue(pQueue);
    printf("%d\n", *dequeuedElement1);
    int* dequeuedElement2 = dequeue(pQueue);
    printf("%d\n", *dequeuedElement2);
    char* dequeuedElement3 = dequeue(pQueue);

    void* dequeuedElement4 = dequeue(pQueue);
    if(*dequeuedElement1 == someLong 
        && *dequeuedElement2 == someInt
        && strcmp(dequeuedElement3, strElement) == 0
        && dequeuedElement4 == NULL) {
        printf("whenAddDifferentDataTypesToQueueThenDequeuesCorrectly: Success!\n");
    } else {
        printf("whenAddDifferentDataTypesToQueueThenDequeuesCorrectly: Failed!\n");
    }
}

int main() {
    whenQueueStartsThenItsEmpty();
    whenQueueIsDestroyedThenSuccess();
    whenEnqueueThenReturnsTheQueuedElement();
    whenQueueIsFullThenIsFull();
    whenEnqueueOnFullListThenReturnsNull();
    whenDequeueAndQueueIsEmptyThenReturnsNull();
    whenEnqueueAndDequeueTheSameElementReturns();
    whenEnqueueAndMaxSizeIsOneThenDequeueCorrectly();
    whenEnqueueSameDataTypesThenDequeuesCorrectly();
    whenAddDifferentDataTypesToQueueThenDequeuesCorrectly();
}