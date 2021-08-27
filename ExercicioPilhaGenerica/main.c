#include <stdio.h>
#include <stdlib.h>
#include "pilha_publico.h"

int main()
{
    pPilha pointerPilha = init(2, sizeof(char));
    int input = 12;
    //fillPilha(pointerPilha, &input);
    push(pointerPilha, &input);
    push(pointerPilha, &input);
    printf("Is full: %d\n", isFull(pointerPilha));
    printf("Is empty: %d\n", isEmpty(pointerPilha));
    printContent(pointerPilha);
    destroy(pointerPilha);
    return 0;
}
