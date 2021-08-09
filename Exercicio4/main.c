#include <stdio.h>
#include <stdlib.h>

/**
O programa deverá ler o número da linha e da coluna,
correspondente ao produto no armazém, e a quantidade a ser retirada do estoque.
Caso a quantidade solicitada for menor ou igual a quantidade em estoque,
o programa deverá emitir uma mensagem de atendimento e dar baixa no estoque.
Do contrário, emitir mensagem, "Estoque com quantidade insuficiente para atender ao pedido".
O programa termina quando o número da linha for igual a -1.
**/

int estoque[5][5]= {{150,0,100,150,200}, {200,300,230,100,90}, {250,300,0,200,150}, {300,100,90,450,0},{350,300,400,250,200}};

struct input {
    int produto;
    int armazem;
    int quantidade;
};

struct input coletaInput() {
    struct input result = {};
    printf("Informe o produto de 0 a 4\n");
    scanf("%d", &result.produto);
    switch (result.produto) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
            printf("Informe o armazém de 0 a 4\n");
            scanf("%d", &result.armazem);
            switch (result.armazem) {
                case 0:
                case 1:
                case 2:
                case 3:
                case 4:
                    printf("Informe o número desejado de retirada do estoque\n");
                    scanf("%d", &result.quantidade);
                    break;
                default:
                    result.produto = -1;
                    printf("Número de produto inválido, encerrando o programa.");
                    break;
            }
            break;
        default:
            result.produto = -1;
            printf("Número de produto inválido, encerrando o programa.");
            break;
    }
    return result;
}

void processaRetiradaEstoque(struct input lido) {
    int current = estoque[lido.produto][lido.armazem];
    if(current - lido.quantidade < 0) {
        printf("Estoque com quantidade insuficiente para atender ao pedido\n");
    } else {
        estoque[lido.produto][lido.armazem] -= lido.quantidade;
        printf("Estoque atualizado para %d do produto %d no armazém %d\n", estoque[lido.produto][lido.armazem], lido.produto, lido.armazem);
    }
}

int main()
{
    int programStatus = 0;
    while(programStatus == 0) {
        struct input lido = coletaInput();
        if(lido.produto >= 0) {
            processaRetiradaEstoque(lido);
        }
        programStatus = lido.produto;
    }
    return 0;
}
