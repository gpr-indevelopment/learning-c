#include <Fila_privado.h>
#include <stdio.h>
#include <string.h>

pQueue init(int maxItems) {
    pQueue pQueue = malloc(sizeof(struct Queue));
    int itemSizesArray[maxItems];
    pQueue->start = 0;
    pQueue->end = 0;
    pQueue->max_items = maxItems;
    pQueue->item_sizes = itemSizesArray;
    pQueue->storage = NULL;
    pQueue->current_allocated_mem = 0;
    pQueue->current_num_items = 0;
    return pQueue;
}

void* enqueue(pQueue pQueue, void* element, int elementSize) {
    resolveCircularMechanism(pQueue);
    pQueue->current_allocated_mem += elementSize;
    if (pQueue->storage == NULL) {
        pQueue->storage = malloc(elementSize);
        memcpy(pQueue->storage, element, elementSize);
    } else {
        pQueue->storage = realloc(pQueue->storage, pQueue->current_allocated_mem);
        void* destAddr = pQueue->storage + pQueue->current_allocated_mem;
        memcpy(destAddr, element, elementSize);
    }
    pQueue->item_sizes[pQueue->end] = elementSize;
    pQueue->end++;
    return element;
}

void* dequeue(pQueue pQueue) {
    int dequeuedElementSize = pQueue->item_sizes[pQueue->start];
    pQueue->start
    return &element;
}

int isEmpty(pQueue pQueue) {
    int result = 0;
    if (pQueue->start == 0 && pQueue->end == 0) {
        result = 1;
    }
    return result;
}

int isFull(pQueue pQueue) {
    int result = 0;
    if (pQueue->end >= pQueue->max_items) {
        result = 1;
    }
    return result;
}

void destroy(pQueue pQueue) {
    free(pQueue->item_sizes);
    free(pQueue->storage);
    free(pQueue);
}

void resolveCircularMechanism(pQueue pQueue) {
    if(pQueue->end >= pQueue->max_items) {
        pQueue->end = 0;
        pQueue->start+=1;
    }
    if(pQueue->start >= pQueue->max_items) {
        pQueue->start = 0;
    }
}
