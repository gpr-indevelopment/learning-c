#include <Fila_publico.h>
#include <stdio.h>

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

int main() {
    whenQueueStartsThenItsEmpty();
    whenQueueIsDestroyedThenSuccess();
    whenEnqueueThenReturnsTheQueuedElement();
    whenQueueIsFullThenIsFull();
    whenEnqueueAndDequeueTheSameElementReturns();
}