#include <stdlib.h>
#include <Fila_publico.h>

struct Queue {
    int start;
    int end;
    int max_items;
    int current_allocated_mem;
    int current_num_items;
    int current_start_mem_offset;
    int* item_sizes;
    void* storage;
};