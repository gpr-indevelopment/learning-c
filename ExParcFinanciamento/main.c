#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float calcularTaxa(int parcelas) {
    float taxa;
    switch (parcelas) {
        case 6:
            taxa = 7;
            break;
        case 12:
            taxa = 10;
            break;
        case 18:
            taxa = 12;
            break;
        case 24:
            taxa = 15;
            break;
        case 36:
            taxa = 18;
            break;
        default:
            printf("Não foi possível achar nenhuma taxa para esse montante de parcelas.");
    }
    return taxa/1200;
}

float financiamento(float valorFinanciamento, int parcelas) {
    printf("Calculando com base em %.2f de financiamento em %d parcelas.\n", valorFinanciamento, parcelas);
    float taxa = calcularTaxa(parcelas);
    printf("Calculando com uma taxa de %f\n", taxa);
    float prestacao;
    prestacao = valorFinanciamento * (pow((1+taxa), parcelas)*taxa)/(pow((1+taxa),parcelas)-1);
    return prestacao;
}

int main()
{
    int parcelas;
    float valorFinanciamento;
    scanf("%f", &valorFinanciamento);
    scanf("%d", &parcelas);
    printf("A prestação foi calculada no valor de %f\n", financiamento(valorFinanciamento, parcelas));
    return 0;
}
