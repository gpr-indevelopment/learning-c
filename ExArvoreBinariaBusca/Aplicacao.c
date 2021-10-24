#include "ABB.h"
#include "stdlib.h"
#include "string.h"
#include "stdio.h"

#define SUCESSO 1
#define FRACASSO 0

void imprime(void *p)
{
    printf("%i ", *((int *)p));
}

int comparaDados(void *dado1, void *dado2)
{
    int n1 = *((int *)dado1);
    int n2 = *((int *)dado2);
    return n1 - n2;
}

int main(int argc, char **argv) {
    int op, numero,prior;
    pABB ptr;
    int novo, elementos;

    if((criaABB(&ptr, sizeof(int)))==FRACASSO) {
        printf("Erro na criação da arvore\n");
        exit(1);
    }

    fscanf(stdin, "%i", &elementos);
    printf("Número de inserções: %i\n", elementos);
    for (int i=0; i < elementos; i++) {
       fscanf(stdin, "%i", &novo);
       printf ("%d: ", i);
       if((insereABB(ptr, &novo, comparaDados))){
         printf("Inserido com sucesso [%d]\n", novo);
       } else{
        printf("Erro na insercao [%d]\n", novo);
      }
    }

    printf("\nImpressao dos elementos em ordem: ");
    percursoEmOrdem(ptr, imprime);
    printf("\n");

    printf("\nImpressao dos elementos em pre-ordem: ");
    percursoPreOrdem(ptr, imprime);
    printf("\n");

    printf("\nImpressao dos elementos em pos-ordem: ");
    percursoPosOrdem(ptr, imprime);
    printf("\n");

    fscanf(stdin, "%i", &elementos);
    printf("\nNúmero de buscas: %i\n", elementos);
    for (int i=0; i < elementos; i++) {
       fscanf(stdin, "%i", &novo);
       if((buscaABB(ptr, &novo, comparaDados))){
         printf("Buscado com sucesso [%d]\n", novo);
       } else{
        printf("Erro na remoção [%d]\n", novo);
      }
    }

    fscanf(stdin, "%i", &elementos);
    printf("\nNúmero de remoções: %i\n", elementos);
    for (int i=0; i < elementos; i++) {
       fscanf(stdin, "%i", &novo);
       //printf("DEBUG\n");
       if((removeABB(ptr, &novo, comparaDados))){
         printf("Removido com sucesso [%d]\n", novo);
       } else{
        printf("Erro na remoção [%d]\n", novo);
      }
    }

    destroiABB(&ptr);
    return 0;
}
