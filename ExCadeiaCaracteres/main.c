#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char palavra[10] = {'O', 'l', 'a', ' ', 'M', 'u', 'n', 'd', 'o', '\0'};
    printf("Char array1: %s\n", palavra);
    char palavra2[] = "Ola Mundoa";
    printf("Char array2: %s\n", palavra2);
    int compare = strcmp(palavra, palavra2);
    printf("Resultado de strcmp para duas palavras: %d\n", compare);
    printf("O tamanho da palavra2 é: %d\n", strlen(palavra2));
    // A instanciação do array não precisa ter tamanho, ele calcula automaticamente.
    char concat1[] = "Ola";
    char concat2[] = " Mundo";
    printf("Resultado da concatenação: %s\n", strcat(concat1, concat2));
    return 0;
}
