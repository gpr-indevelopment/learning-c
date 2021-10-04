#include "stdlib.h"

typedef struct LinkedList* pLinkedList;

// Inicializa a lista heterogênea
pLinkedList init();

// Destrói o descritor da lista e todos os nós
void destroy(pLinkedList pLinkedList);

// Destrói a lista do parâmetro e retorna uma nova
pLinkedList restart(pLinkedList pLinkedList);

// Retorna o tamanho atual da lista
int getSize(pLinkedList pLinkedList);

// Insere um novo elemento no início da lista
void insertFirst(pLinkedList pLinkedList, void* element, int elementSize);

// Insere um elemento ao final da lista
void insertLast(pLinkedList pLinkedList, void* element, int elementSize);

// Insere um elemento em uma posição da lista (0-based index). Qualquer elemento que exista
// Na posição é descartado. Retorna 1 em caso de falha.
int insertPos(pLinkedList pLinkedList, void* element, int elementSize, int pos);

// Remove o primeiro elemento da lista.
void removeFirst(pLinkedList pLinkedList);

// Remove o último elemento da lista
void removeLast(pLinkedList pLinkedList);

// Remove um elemento em uma posição da lista (0-based index). 
// Retorna o elemento removido. Retorna 1 em caso de falha.
int removePos(pLinkedList pLinkedList, int pos);

// Retorna o primeiro elemento da lista
void* getFirst(pLinkedList pLinkedList);

// Retorna o último elemento da lista
void* getLast(pLinkedList pLinkedList);

// Retorna o elemento em uma posição (0-based index)
void* get(pLinkedList pLinkedList, int pos);