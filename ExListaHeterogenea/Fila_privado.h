#include "stdlib.h"
#include "Fila_publico.h"

struct Queue {
    // Índice do início da fila (primeiro a ser atendido)
    int start;
    // Índice do último da fila
    int end;
    // Número máximo de itens, informado no init
    int max_items;
    // Array que guarda o tamanho dos itens na fila, suporte a heterogeneidade
    int* item_sizes;
    // Array de ponteiros para os elementos guardados na fila
    void** storage;
    // Número atual de itens, suporta o isFull e o isEmpty
    int current_num_items;
};