typedef struct sort{
    int *vEntrada;
    int *vOrdenado;
    int nro_elementos;
    int nro_trocas;
    int nro_comparacoes;
}vsort;

int bubblesort(vsort *st_bubble);
int selectsort(vsort *st_select);
int insertsort(vsort *st_insert);
// Poderia ser privado...
int copy(int* from, int* to, int numElements);
void swap(int* from, int* to, int* swapCounter);
