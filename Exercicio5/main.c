#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
Faça um programa que modifique as vogais de uma frase.
O programa deve ler uma frase (max. 100 caracteres) e armazeá-la num vetor.
Imprimir a frase lida trocando as vogais, isto é, trocar 'a' pelo 'u', 'e' pelo 'o', 'i' pelo 'u', 'o' pelo 'a' e o 'u' pelo 'e'.
Usar uma função void (procedimento) para realizar a troca e uma função para realizar a impressão da frase trocada.
A função deve ter como parâmetro um ponteiro char referente ao vetor.
Dica: Use a função gets() da biblioteca string.h para realizar a leitura da frase.
Use o switch para realizar as trocas. Só considere as letras minúsculas.
**/

void printarFraseTrocada(char *frase) {
    printf("Frase trocara: %s\n", frase);
}

void trocarVogal(char *frase) {
    int i;
    for(i=0;i<strlen(frase);i++) {
        switch (frase[i]) {
            case 'a':
                frase[i] = 'u';
                break;
            case 'e':
                frase[i] = 'o';
                break;
            case 'i':
                frase[i] = 'u';
                break;
            case 'o':
                frase[i] = 'a';
                break;
            case 'u':
                frase[i] = 'e';
                break;
            default:
                break;
        }
    }
}

int main()
{
    printf("Digite uma frase de até 100 caracteres\n");
    char frase[100];
    fgets(frase, 100, stdin);
    trocarVogal(frase);
    printarFraseTrocada(frase);
    return 0;
}
