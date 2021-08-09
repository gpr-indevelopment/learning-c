#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size = 5;
    int matriz[size][size];
    int i, j;
    for(i=0;i<size;i++) {
        for(j=0;j<size;j++) {
            matriz[i][j] = rand();
            printf("Address %p\n", &matriz[i][j]);
        }
    }
    return 0;
}
