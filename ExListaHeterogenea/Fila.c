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
    pQueue->current_start_mem_offset = 0;
    return pQueue;
}

void* enqueue(pQueue pQueue, void* element, int elementSize) {
    if(isFull(pQueue) == 1) {
        return NULL;
    }
    pQueue->current_allocated_mem += elementSize;
    if (pQueue->storage == NULL) {
        pQueue->storage = malloc(pQueue->current_allocated_mem);
        memcpy(pQueue->storage, element, pQueue->current_allocated_mem);
    } else {
        pQueue->storage = realloc(pQueue->storage, pQueue->current_allocated_mem);
        void* destAddr = pQueue->storage + pQueue->current_allocated_mem - elementSize;
        memcpy(destAddr, element, elementSize);
    }
    pQueue->item_sizes[pQueue->end] = elementSize;
    if(++pQueue->end >= pQueue->max_items) {
        pQueue->end = 0;
    }
    pQueue->current_num_items++;
    return element;
}

void* dequeue(pQueue pQueue) {
    if(isEmpty(pQueue) == 1) {
        return NULL;
    }
    int dequeuedElementSize = pQueue->item_sizes[pQueue->start];
    void *element_address = malloc(dequeuedElementSize);
    memcpy(element_address, pQueue->storage + pQueue->current_start_mem_offset, dequeuedElementSize);
    pQueue->current_start_mem_offset += dequeuedElementSize;
    if(++pQueue->start >= pQueue->max_items) {
        pQueue->start = 0;
        pQueue->current_start_mem_offset = 0;
    }
    pQueue->current_allocated_mem-=dequeuedElementSize;
    pQueue->current_num_items--;
    return element_address;
}

int isEmpty(pQueue pQueue) {
    int result = 0;
    if (pQueue->current_num_items == 0) {
        result = 1;
    }
    return result;
}

int isFull(pQueue pQueue) {
    int result = 0;
    if (pQueue->current_num_items >= pQueue->max_items) {
        result = 1;
    }
    return result;
}

void destroy(pQueue pQueue) {
    free(pQueue->storage);
    free(pQueue);
}
