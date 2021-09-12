#include "Fila_publico.h"
#include "stdio.h"
#include "string.h"
#include "pilha_publico.h"

void whenQueueStartsThenItsEmpty();
void whenQueueIsDestroyedThenSuccess();
void whenEnqueueThenReturnsTheQueuedElement();
void whenQueueIsFullThenIsFull();
void whenEnqueueOnFullListThenReturnsNull();
void whenDequeueAndQueueIsEmptyThenReturnsNull();
void whenEnqueueAndDequeueTheSameElementReturns();
void whenEnqueueAndMaxSizeIsOneThenDequeueCorrectly();
void whenEnqueueSameDataTypesThenDequeuesCorrectly();
void whenAddDifferentDataTypesToQueueThenDequeuesCorrectly();
void finalTest();