#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"

#define SUCESSO 1
#define FRACASSO 0

// Complexidade dele é igual a (1+n)*n/2 o que dá n²
int bubblesort(vsort *st_bubble) {
  int n = st_bubble->nro_elementos, i, j, nextItMax = n-1, noSwapFlag = 0;
  st_bubble->vOrdenado = calloc(n, sizeof(int));
  copy(st_bubble->vEntrada, st_bubble->vOrdenado, n);
  st_bubble->nro_comparacoes = 0;
  st_bubble->nro_trocas = 0;
  for (i = 0; i < n && noSwapFlag == 0; i++) {
    noSwapFlag = 1;
    for (j = 0; j < nextItMax; j++) {
      st_bubble->nro_comparacoes++;
      if (st_bubble->vOrdenado[j] > st_bubble->vOrdenado[j + 1]) {
        swap(&st_bubble->vOrdenado[j], &st_bubble->vOrdenado[j + 1], &st_bubble->nro_trocas);
        noSwapFlag = 0; 
      }
    }
    nextItMax--;
  }
  return SUCESSO;
}

// A principal diferença entre o buble e o select é que no bubble
// Precisamos fazer swaps o tempo inteiro, enquanto o select faz diversas
// Comparações, acha o menor elemento e faz swap uma unica vez.

//Por outro lado, o bubble permite um critério de early stopping, e o 
//Select não.
int selectsort(vsort *st_select) {
  int n = st_select->nro_elementos, i, j;
  st_select->nro_comparacoes = 0;
  st_select->nro_trocas = 0;  
  st_select->vOrdenado = calloc(n, sizeof(int));
  copy(st_select->vEntrada, st_select->vOrdenado, n);
  for (i = 0; i < n; i++) {
    int currentSmallest = i;
    for (j = i + 1; j < n; j++) {
      st_select->nro_comparacoes++;
      if (st_select->vOrdenado[j] < st_select->vOrdenado[currentSmallest]) {
        currentSmallest = j;
      }
    }
    swap(&st_select->vOrdenado[i], &st_select->vOrdenado[currentSmallest], &st_select->nro_trocas);
  }
  return SUCESSO;
}

int insertsort(vsort *st_insert) {
  int n = st_insert->nro_elementos, i, j;
  st_insert->nro_comparacoes = 0;
  st_insert->nro_trocas = 0;  
  st_insert->vOrdenado = calloc(n, sizeof(int));
  copy(st_insert->vEntrada, st_insert->vOrdenado, n);
  for (i = 1; i < n; i++) {
    for (j = i; j > 0; j--) {
      st_insert->nro_comparacoes++;
      if (st_insert->vOrdenado[j] < st_insert->vOrdenado[j-1]) {
        swap(&st_insert->vOrdenado[j], &st_insert->vOrdenado[j-1], &st_insert->nro_trocas);
      } else {
        break;
      }
    }
  }
  return SUCESSO;
}

int copy(int* from, int* to, int numElements) {
  for (int i = 0; i < numElements; i++) {
    to[i] = from[i];
  }
}

void swap(int* from, int* to, int* swapCounter) {
  int temp = *from; 
  *from = *to; 
  *to = temp; 
  *swapCounter = *swapCounter + 1;
}