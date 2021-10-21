typedef struct ABB* pABB;
typedef struct ABB** ppABB;

#define SUCESSO 1
#define FRACASSO 0

int criaABB(ppABB pp, int tamInfo);
int destroiABB(ppABB pp);
int reiniciaABB(pABB p);
int insereABB(pABB p, void *novo, int (* cmp)(void *p1, void *p2));
int buscaABB(pABB p, void *item, int (* cmp)(void *p1, void *p2));
int testaVaziaABB(pABB p);
int percursoEmOrdem(pABB pa, void (* processa)(void *p));
int percursoPreOrdem(pABB pa, void (* processa)(void *p));
int percursoPosOrdem(pABB pa, void (* processa)(void *p));
int removeABB(pABB p, void *item, int (* cmp)(void *p1, void *p2));
