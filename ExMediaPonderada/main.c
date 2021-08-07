#include <stdio.h>
#include <stdlib.h>

char calcConceito(float mediaPond) {
    char conceito;
    if(mediaPond <= 4.9) {
        conceito = 'D';
    } else if(mediaPond <= 6.9) {
        conceito = 'C';
    } else if(mediaPond <= 8.9) {
        conceito = 'B';
    } else {
        conceito = 'A';
    }
    return conceito;
}

float mediaPond(int nota1, int nota2) {
    float media;
    printf("A nota 1 foi: %d\n", nota1);
    printf("A nota 2 foi: %d\n", nota2);
    media = (nota1*4 + nota2*6)/10;
    printf("A média ponderada foi: %.2f\n", media);
    return media;
}

int main(){
    int nota1;
    int nota2;
    scanf ("%d", &nota1);
    scanf ("%d", &nota2);
    printf("O conceito foi: %c\n", calcConceito(mediaPond(nota1, nota2)));
    return 0;
}
