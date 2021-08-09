#include <stdio.h>
#include <stdlib.h>

int main()
{
    // O enum cria um tipo novo com limite de valores
    enum {branco, preto, vermelho, azul} cores;
    cores = vermelho;
    printf("Minha cor tem valor %d\n", cores);
    // Não compila pois amarelo não foi definido no enum.
    // cores = amarelo;
    // printf("Minha cor tem valor %d\n", cores);
    enum {branco1=1,preto1=0,vermelho1=19, azul1} cores1;
    cores1 = branco1;
    printf("Minha cor tem valor %d\n", cores1);
    cores1 = vermelho1;
    printf("Minha cor vermelho custom tem valor %d\n", cores1);
    return 0;
}
