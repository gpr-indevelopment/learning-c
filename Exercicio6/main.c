#include <stdio.h>
#include <stdlib.h>

/**
Escreva um programa que declare uma matriz 10x10 de inteiros.
Você criar uma função void (procedimento) para inicializar a matriz com zeros usando um ponteiro para a matriz.
Faça outra função void para preencher depois a matriz com os números de 99 a 0,
também usando ponteiro para matriz como parâmetro.
Por fim, o programa deve imprimir a matriz.
**/

void imprimirMatriz(int *matriz) {
    int i;
    for(i=0;i<100;i++) {
        int linha = i/10 + 1;
        int coluna = 11 - (linha*10 - i);
        printf("matriz[%d][%d] = %d\n", linha, coluna, *matriz);
        matriz++;
    }
}

void preencherMatriz(int *matriz) {
    int i;
    for(i=0;i<100;i++) {
        *matriz = rand() % 100;
        matriz++;
    }
}

void inicializarMatrizComZeros(int *matriz) {
    int i;
    for(i=0;i<100;i++) {
        *matriz = 0;
        matriz++;
    }
}

int main()
{
    int matriz[10][10];
    inicializarMatrizComZeros(matriz);
    preencherMatriz(matriz);
    imprimirMatriz(matriz);
    return 0;
}
