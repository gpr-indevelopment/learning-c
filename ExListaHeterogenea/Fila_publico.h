#include "stdlib.h"

typedef struct Queue * pQueue;

pQueue init(int maxItems);

void* enqueue(pQueue pQueue, void* element, int elementSize);

void* dequeue(pQueue pQueue);

int isEmpty(pQueue pQueue);

int isFull(pQueue pQueue);

void destroy(pQueue pQueue);