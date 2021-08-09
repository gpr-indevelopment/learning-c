#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**

Faça um programa que receba uma frase (máximo 100 caracteres) e uma letra qualquer,
calcule e mostre a quantidade que essa letra aparece na frase digitada.
Para descobrir o tamanho da frase digitada utilize a função strlen(cadeia de caracteres).
Ao final, exibir o estoque (matriz).

Dica: Usar a função gets(cadeia de caracteres) - biblioteca sring.h para realizar a leitura da frase.
A função scanf só realiza leitura até o primeiro espaço em branco.

**/

struct input {
    char letra[1];
    char frase[100];
};

struct input coletaInput() {
    char frase[100];
    char letra[1];
    struct input result = {};
    printf("Digite a frase desejada: ");
    fgets(frase, 100, stdin);
    printf("\nEu li a frase: %s\n", frase);
    strcpy(result.frase, frase);
    printf("Digite a letra desejada: ");
    scanf("%s", &letra);
    printf("Eu li a letra: %s\n", letra);
    result.letra[0] = letra[0];
    return result;
}

void calculaOcorrencias(struct input lido) {
    int i;
    int counter = 0;
    printf("Recebido a frase: %s\n", lido.frase);
    for(i=0;i<strlen(lido.frase)-1;i++) {
        printf("Comparando a letra %c\n", lido.frase[i]);
        if(lido.frase[i] == lido.letra[0]) {
            counter += 1;
        }
    }
    printf("A letra ocorre %d vezes na frase.", counter);
}

int main()
{
    struct input lido = coletaInput();
    calculaOcorrencias(lido);
    return 0;
}
