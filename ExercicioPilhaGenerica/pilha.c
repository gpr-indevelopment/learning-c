#include "pilha_publico.h"
#include <stdlib.h>
#include <stdio.h>

struct Pilha {
    unsigned char *itens;
    int itemSize;
    int numItens;
    int topIndex;
} typedef pilha;

pPilha init(int numItens, int itemSize) {
    printf("Chamou a inicialização da pilha com %d itens e %d de tamanho\n", numItens, itemSize);
    unsigned char *itens;
    int intensSize = numItens*itemSize;
    printf("Itens size = %d\n", intensSize);
    itens = (unsigned char *)malloc (intensSize);
    pPilha pilha = (struct Pilha*) malloc(sizeof (struct Pilha));
    pilha->itemSize = itemSize;
    pilha->numItens = numItens;
    pilha->itens = itens;
    pilha->topIndex = 0;
    return pilha;
}

int isEmpty(pPilha pilha) {
    int result = 0;
    if(pilha->topIndex == 0) {
        result = 1;
    }
    return result;
}

int isFull(pPilha pilha) {
    int result = 0;
    if(pilha->topIndex == (pilha->numItens)) {
        result = 1;
    }
    return result;
}

void destroy(pPilha pilha) {
    free(pilha->itens);
    //free(pilha->itemSize);
    //free(pilha->numItens);
    //free(pilha->topIndex);
}

void fillPilha(pPilha pilha, void *pElemento) {
    int i, j, k = 0;
    for (i = 0; i < pilha->numItens; i++) {
        for(j = 0; j < pilha->itemSize;j++) {
            *(pilha->itens + k) = *((unsigned char *) (pElemento + j));
            k++;
        }
    }
}


void push(pPilha pilha, void *pElemento) {
    int i;
    int bottomByte = pilha->topIndex * pilha->itemSize;
    for(i = 0; i < pilha->itemSize;i++) {
        *(pilha->itens + bottomByte + i) = *((unsigned char *) (pElemento + i));
    }
    pilha->topIndex++;
}

void printContent(pPilha pilha) {
    int i;
    for(i = 0; i < pilha->numItens; ++i) {
        printf("Print: %d\n", *(pilha->itens + i*pilha->itemSize));
    }
}
