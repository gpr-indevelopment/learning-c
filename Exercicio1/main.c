#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
Uma empresa comercial possui um programa para controle das receitas e despesas em seus 10 projetos.
Os projetos são numerados de 0 até 9. Faça um programa C que controle a entrada e saída de recursos dos projetos.
O programa deverá ler um conjunto de informações contendo:
Número do projeto, valor, tipo despesa ("R" - Receita e "D" - Despesa).
O programa termina quando o valor do código do projeto for igual a -1.
Sabe-se que Receita deve ser somada ao saldo do projeto e despesa subtraída do saldo do projeto.
Ao final do programa, imprirmir o saldo final de cada projeto.

Dica: Usar uma estrutura do tipo vetor para controlar os saldos dos projetos.
Usar o conceito de struct para agrupar as informações lidas.
**/

struct input
{
    int numeroProjeto;
    float valor;
    char tipoDespesa[1];
};

struct input lerInputs()
{
    printf("Iniciando coleta de inputs \n\n");
    int numeroProjeto;
    float valor;
    char tipoDespesa[1];
    printf("Qual o número do projeto?\n");
    printf("Projetos de 0 a 9\n");
    scanf("%d", &numeroProjeto);
    if (numeroProjeto >= 0) {
        printf("Qual o valor?\n");
        scanf("%f", &valor);
        printf("Qual o tipo de despesa?\n");
        printf("Valores possíveis: 'R' - Receita e 'D' - Despesa\n");
        printf("Apenas um caractere permitido\n");
        scanf("%s", &tipoDespesa);
    }
    struct input result = {numeroProjeto, valor, {tipoDespesa[0]}};
    return result;
}

int validarInputs(struct input lido) {
    if(lido.numeroProjeto == -1)
    {
        return -1;
    }
    return 0;
}

void printarSaldos(int saldos[], int saldosLen) {
    int i;
    for (i = 0; i < saldosLen; i++) {
        printf("O saldo da empresa %d foi %d\n", i, saldos[i]);
    }
}

int main()
{
    int saldos[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int validacao = 0;
    while (validacao == 0) {
        struct input lido = lerInputs();
        validacao = validarInputs(lido);
        if(validacao == 0) {
            printf("Processando com numero do projeto = %d\n", lido.numeroProjeto);
            printf("Processando com valor = %f\n", lido.valor);
            printf("Processando com tipo de despesa = %s\n\n", lido.tipoDespesa);
            if(lido.tipoDespesa[0] == 'R') {
                saldos[lido.numeroProjeto] += lido.valor;
            } else if (lido.tipoDespesa[0] == 'D') {
                saldos[lido.numeroProjeto] -= lido.valor;
            } else {
                printf("Não encontrado tipo de despesa elegível\n");
            }
        }
    }
    printarSaldos(saldos, 10);
    printf("Terminando o programa com numero do projeto -1.");
    return 0;
}
