#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
Faça um programa para calcular a área e o perímetro de um hexágono.
O programa deve implementar uma função chamada calc_hexa que calcula a área e o perímetro de um hexágono regular de lado L.
O program deve solicitar ao usuário o lado do polígono, calcular e imprimir a área e o perímetro do polígono.
O programa termina quando for digitado um valor negativo qualquer para o lado.
A função deve obedecer o seguinte protótipo:

void calc_hexa(float l, floar *area, float *perimetro);
Lembrando que a área e o perímetro de um hexágono regular são dados por: [formula omitida]
Para os cálculos, obrigatoriamente você deve utilizar as funções sqrt e pow da biblioteca math.h.

**/

void calc_hexa(float l, float *area, float *perimetro) {
    *perimetro = 6*l;
    *area = (3*pow(l, 2)*sqrt(3))/2;
}

int main()
{
    float ladoHex;
    float area;
    float perimetro;
    printf("Digite a medida do lado do hexágono:\n");
    scanf("%f", &ladoHex);
    if(ladoHex >= 0) {
        calc_hexa(ladoHex, &area, &perimetro);
        printf("A área calculada foi %.2f\n", area);
        printf("O perimetro calculado foi %.2f\n", perimetro);
    } else {
        printf("Entrou lado negativo. Terminando o programa.\n");
    }
    return 0;
}
