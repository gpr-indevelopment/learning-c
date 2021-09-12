#include "Fila_privado.h"
#include "stdio.h"
#include "string.h"

pQueue init(int maxItems) {
    pQueue pQueue = malloc(sizeof(struct Queue));
    pQueue->start = 0;
    pQueue->end = 0;
    pQueue->max_items = maxItems;
    // Inicializado com calloc para que os elementos no array de int comecem em 0
    pQueue->item_sizes = calloc(maxItems, sizeof(int));
    // Aloca um array de ponteiros genéricos.
    pQueue->storage = malloc(sizeof(void*) * maxItems);
    pQueue->current_num_items = 0;
    return pQueue;
}

void* enqueue(pQueue pQueue, void* element, int elementSize) {
    if(isFull(pQueue) == 1) {
        return NULL;
    }
    pQueue->storage[pQueue->end] = malloc(elementSize);
    memcpy(pQueue->storage[pQueue->end], element, elementSize);
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
    memcpy(element_address, pQueue->storage[pQueue->start], dequeuedElementSize);
    free(pQueue->storage[pQueue->start]);
    pQueue->item_sizes[pQueue->start] = 0;
    if(++pQueue->start >= pQueue->max_items) {
        pQueue->start = 0;
    }
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
    int i;
    // Já que o storage guarda ponteiros, precisamos liberar o conteúdo deles
    for (i = 0; i < pQueue->max_items; i++) {
        int currentSize = pQueue->item_sizes[i];
        if(currentSize > 0) {
            free(pQueue->storage[i]);
        }
    }
    free(pQueue->storage);
    free(pQueue->item_sizes);
    free(pQueue);
}
