#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Estrutura de dados heterogênea é aquela com tipos diferentes nos campos.
    struct {
        int idade;
        char nome[30];
        char nomeMae[30];
    } rg;
    rg.idade = 26;
    // Lembrando que não da pra fazer atribuição direta em um array.
    strcpy(rg.nome, "Gabriel Robaina");
    strcpy(rg.nomeMae, "Luciene Robaina");
    // Em struct cada campo tem um endereço de memória diferente.
    printf("Minha idade é %d\n", rg.idade);
    printf("Endereço: %x\n", &rg.idade);
    printf("Meu nome é %s\n", rg.nome);
    printf("Endereço: %x\n", &rg.nome);
    printf("O nome da minha mãe é %s\n", rg.nomeMae);
    printf("Endereço: %x\n", &rg.nomeMae);
    return 0;
}
