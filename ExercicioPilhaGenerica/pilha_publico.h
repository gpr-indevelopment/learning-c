#ifndef PILHA_PUBLICO_H
#define PILHA_PUBLICO_H

typedef struct Pilha * pPilha;

pPilha init(int numItens, int itemSize);

int isEmpty(pPilha pilha);

int isFull(pPilha pilha);

void destroy(pPilha pilha);

void push(pPilha pilha, void *pElemento);

void fillPilha(pPilha pilha, void *pElemento);

void printContent(pPilha pilha);

#endif
