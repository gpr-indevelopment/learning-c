#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**

Faça um programa C para calular o número de lâmpadas 60 watts necessárias para um determinado cômodo.
O programa deverá ler um conjunto de informações, tais como: tipo, largura e comprimento do cômodo.
O programa termina quando o tipo de cômodo for igual -1.
A tabela abaixo mostra, para cada tipo de cômodo, a quantidade de watts por metro quadrado.

Dica: Use uma estrutura struct para agrupar logicamente as informações de um comodo
(int tipo de comodo, float largura e float altura).
Usar uma função (float CalulaArea) para calcular a área do cômodo.
Os atributos de entrada serão a largura e comprimento do cômodo.
Usar uma função (float Lampada) para calcular a quantidade de lâmpadas necesárias para o cômodo.
Os atributos de entrada serão o tipo de cômodo e a metragem (em m2) do cômodo.

Obs: Utilize a função ceil(numero) em #include math.h para realizar o arrendondamento para cima.

**/

struct input {
    int tipoComodo;
    float largura;
    float altura;
};

float calculaArea(float largura, float altura) {
    return largura * altura;
}

int calculaPotencia(int tipoComodo) {
    int result;
    switch (tipoComodo) {
        case 0:
            result = 12;
            break;
        case 1:
            result = 15;
            break;
        case 2:
            result = 18;
            break;
        case 3:
            result = 20;
            break;
        case 4:
            result = 22;
            break;
        default:
            printf("Não foi possível calcular potência para o tipo de cômodo %d\n", tipoComodo);
            result = -1;
            break;
    }
    return result;
}

int lampada(int tipoComodo, float areaComodo) {
    int potenciaPorArea = calculaPotencia(tipoComodo);
    float potencia = potenciaPorArea * areaComodo;
    return ceil(potencia/60);
}

struct input coletaInput() {
    int tipoComodo;
    float largura;
    float altura;
    printf("Digite o tipo do comodo\n");
    scanf("%d", &tipoComodo);
    printf("Digite a largura\n");
    scanf("%f", &largura);
    printf("Digite a altura\n");
    scanf("%f", &altura);
    return (struct input) {tipoComodo, largura, altura};
}

int main()
{
    struct input lido = coletaInput();
    float areaComodo = calculaArea(lido.largura, lido.altura);
    printf("Serão necessárias %d lampadas\n", lampada(lido.tipoComodo, areaComodo));
    return 0;
}
