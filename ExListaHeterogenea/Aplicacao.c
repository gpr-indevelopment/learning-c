#include "Aplicacao.h"

void whenQueueStartsThenItsEmpty() {
    pQueue pQueue = init(10);
    int resultIsEmpty = isEmpty(pQueue);
    if(resultIsEmpty == 1) {
        printf("whenQueueStartsThenItsEmpty: Success!\n");
    } else {
        printf("whenQueueStartsThenItsEmpty: Failed!\n");
    }
    destroy(pQueue);
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
    destroy(pQueue);
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
    destroy(pQueue);
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
    destroy(pQueue);
}

void whenDequeueAndQueueIsEmptyThenReturnsNull() {
    pQueue pQueue = init(10);
    int* dequeuedElement = dequeue(pQueue);
    if(dequeuedElement == NULL) {
        printf("whenDequeueAndQueueIsEmptyThenReturnsNull: Success!\n");
    } else {
        printf("whenDequeueAndQueueIsEmptyThenReturnsNull: Failed!\n");
    }
    destroy(pQueue);
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
    destroy(pQueue);
    free(dequeuedElement);
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
    destroy(pQueue);
    free(dequeuedElement1);
    free(dequeuedElement2);
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
    int* dequeuedElement2 = dequeue(pQueue);
    int* dequeuedElement3 = dequeue(pQueue);
    if(*dequeuedElement1 == someInt1 
        && *dequeuedElement2 == someInt2
        && *dequeuedElement3 == someInt3) {
        printf("whenEnqueueSameDataTypesThenDequeuesCorrectly: Success!\n");
    } else {
        printf("whenEnqueueSameDataTypesThenDequeuesCorrectly: Failed!\n");
    }
    destroy(pQueue);
    free(dequeuedElement1);
    free(dequeuedElement2);
    free(dequeuedElement3);
}

void whenAddDifferentDataTypesToQueueThenDequeuesCorrectly() {
    pQueue pQueue = init(3);
    char strElement[] = "Some_string";
    int someInt = 5;
    long someLong = 123456789111;
    enqueue(pQueue, &someInt, sizeof(int));
    enqueue(pQueue, &someLong, sizeof(long));
    enqueue(pQueue, strElement, sizeof(strElement));
    int* dequeuedElement1 = dequeue(pQueue);
    long* dequeuedElement2 = dequeue(pQueue);
    char* dequeuedElement3 = dequeue(pQueue);
    void* dequeuedElement4 = dequeue(pQueue);
    if(*dequeuedElement1 == someInt 
        && *dequeuedElement2 == someLong
        && strcmp(dequeuedElement3, strElement) == 0
        && dequeuedElement4 == NULL) {
        printf("whenAddDifferentDataTypesToQueueThenDequeuesCorrectly: Success!\n");
    } else {
        printf("whenAddDifferentDataTypesToQueueThenDequeuesCorrectly: Failed!\n");
    }
    destroy(pQueue);
    free(dequeuedElement1);
    free(dequeuedElement2);
    free(dequeuedElement3);
    free(dequeuedElement4);
}

void finalTest() {
    printf("Teste final do professor \n");
    pPilha pPilha, pPilha2;
    ppPilha pPilhaDequeued, pPilhaDequeued2;
    // Crie uma fila circular c/ 3 posições
    pQueue pQueue = init(3);
    // Crie 1 pilha c/ 10 posições
    criapilha(&pPilha, 10, sizeof(int));
    // Empilhe (0,1, ... 8) (empilhei na pilha1)
    int i, j;
    for(i = 0; i < 9; i++) {
        int currentI = i;
        empilha(pPilha, &currentI);
    }
    // enfileire a pilha
    enqueue(pQueue, &pPilha, sizeof(void *));
    // Crie 1 pilha c/ 10 posições
    criapilha(&pPilha2, 10, sizeof(int));
    // Empilhe (8,7, ... 0)
    for(j = 8; j >= 0; j--) {
        int currentJ = j;
        empilha(pPilha2, &currentJ);
    }
    // enfileire a pilha
    enqueue(pQueue, &pPilha2, sizeof(void *));
    // Desempilhe 4 elementos (não especificado, desempilhei a pilha 1 já que vai ser a primeira desenfileirada)
    int desemp1, desemp2, desemp3, desemp4, topoRet;
    desempilha(pPilha, &desemp1);
    desempilha(pPilha, &desemp2);
    desempilha(pPilha, &desemp3);
    desempilha(pPilha, &desemp4);
    // desenfileire a pilha
    pPilhaDequeued = dequeue(pQueue);
    // Imprima o topo da pilha retornada
    topo(*pPilhaDequeued, &topoRet);
    printf("Topo da pilha retornada: %d\n", topoRet);
    // Desenfileire a pilha
    pPilhaDequeued2 = dequeue(pQueue);
    // Destrua a pilha (destruí as duas)
    destroipilha(&pPilha);
    destroipilha(&pPilha2);
    // Destrua a fila
    destroy(pQueue);
    free(pPilhaDequeued);
    free(pPilhaDequeued2);
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
    finalTest();
}