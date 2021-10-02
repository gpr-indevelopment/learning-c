#include "stdlib.h"

typedef struct LinkedList* pLinkedList;

typedef struct Node* pNode;

// Inicializa a lista com o tamanho do elemento (homogênea)
pLinkedList init(int elementSize);

// Destrói o descritor da lista e todos os nós
void destroy(pLinkedList pLinkedList);

// Destrói a lista do parâmetro e retorna uma nova
pLinkedList restart(pLinkedList pLinkedList);

// Retorna o tamanho atual da lista
int getSize(pLinkedList pLinkedList);

// Insere um novo elemento no início da lista
void insertFirst();

// Insere um elemento ao final da lista
void insertLast(pLinkedList pLinkedList, void* element);

// Insere um elemento em uma posição da lista (0-based index). Qualquer elemento que exista
// Na posição é descartado. Retorna o elemento inserido.
void* insertPos(pLinkedList pLinkedList, void* element, int pos);

void removeFirst(pLinkedList pLinkedList);

void removeLast(pLinkedList pLinkedList);

void removePos(int pos);

void* getFirst(pLinkedList pLinkedList);

void* getLast(pLinkedList pLinkedList);

// Retorna o elemento em uma posição (0-based index)
void* get(pLinkedList pLinkedList, int pos);