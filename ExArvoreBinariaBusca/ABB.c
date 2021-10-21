#include <ABB_privado.h>
#include <stdlib.h>
#include <string.h>

int findRecursive(pNode origin, void *item, int (* cmp)(void *p1, void *p2)) {
    int result = FRACASSO;
    if (cmp(item, origin) == 0) {
        result = SUCESSO;
    } else if (origin->leftChildNode != NULL){
        result = findRecursive(origin->leftChildNode, item, cmp);
    }
    if (result == FRACASSO && origin->rightChildNode != NULL){
        result = findRecursive(origin->leftChildNode, item, cmp);
    }
    return result;
}

void destroySubTreeRecursive(pNode origin) {
    if (origin->leftChildNode != NULL) {
        destroySubTreeRecursive(origin->leftChildNode);
    }
    if (origin->rightChildNode !=NULL) {
        destroySubTreeRecursive(origin->rightChildNode);
    }
    free(origin->element);
    free(origin);
}

void findAndInsertRecursive(pNode origin, void* element, int elementSize, int (* cmp)(void *p1, void *p2)) {
    if (cmp(element, origin) >= 0) {
        if (origin->rightChildNode == NULL) {
            origin->rightChildNode = createNode(element, elementSize);
        } else {
            findAndInsertRecursive(origin->rightChildNode, element, elementSize, cmp);
        }
    } else {
        if (origin->leftChildNode == NULL) {
            origin->leftChildNode = createNode(element, elementSize);
        } else {
            findAndInsertRecursive(origin->leftChildNode, element, elementSize, cmp);
        }
    }
}

int criaABB(ppABB pp, int tamInfo) {
    pABB p = malloc(sizeof(struct ABB));
    if (p == NULL) {
        return FRACASSO;
    }
    p->currentSize = 0;
    p->rootNode = 0;
    p->elementSize = tamInfo;
    pp = &p;
    return SUCESSO;
}

int destroiABB(ppABB pp) {
    destroySubTreeRecursive((*pp)->rootNode);
    free(*pp);
    return SUCESSO;
}

int reiniciaABB(pABB p) {
    int elementSize = p->elementSize;
    destroiABB(&p);
    return criaABB(&p, elementSize);
}

int testaVaziaABB(pABB p) {
    if (p->currentSize == 0) {
        return SUCESSO;
    }
    return FRACASSO;
}

int buscaABB(pABB p, void *item, int (* cmp)(void *p1, void *p2)) {
    if (p->rootNode == NULL) {
        return FRACASSO;
    } else {
        return findRecursive(p->rootNode, item, cmp);
    }
}

int insereABB(pABB p, void *novo, int (* cmp)(void *p1, void *p2)) {
    if (p->rootNode == NULL) {
        p->rootNode = createNode(novo, p->elementSize);
    } else {
        findAndInsertRecursive(p->rootNode, novo, p->elementSize, cmp);
    }
    p->currentSize++;
    return SUCESSO;
}

pNode createNode(void* element, int elementSize) {
    pNode p = malloc(sizeof(struct Node));
    p->element = malloc(elementSize);
    memcpy(p->element, element, elementSize);
    return p;
}

void visitNodesRecursive(pNode origin, void (* processa)(void *p)) {
    if (origin->leftChildNode != NULL) {
        visitNodesRecursive(origin->leftChildNode, processa);
    }
    if (origin->rightChildNode != NULL) {
        visitNodesRecursive(origin->rightChildNode, processa);
    }
    processa(origin->element);
}

int percursoPreOrdem(pABB pa, void (* processa)(void *p)) {
    if (pa->rootNode != NULL) {
        processa(pa->rootNode->element);
        if (pa->rootNode->leftChildNode != NULL) {
            visitNodesRecursive(pa->rootNode->leftChildNode, processa);
        }
        if (pa->rootNode->rightChildNode != NULL) {
            visitNodesRecursive(pa->rootNode->rightChildNode, processa);
        }
    }
    return SUCESSO;
}

int percursoEmOrdem(pABB pa, void (* processa)(void *p)) {
    if (pa->rootNode != NULL) {
        if (pa->rootNode->leftChildNode != NULL) {
            visitNodesRecursive(pa->rootNode->leftChildNode, processa);
        }
        processa(pa->rootNode->element);
        if (pa->rootNode->rightChildNode != NULL) {
            visitNodesRecursive(pa->rootNode->rightChildNode, processa);
        }
    }
    return SUCESSO;
}

int percursoPosOrdem(pABB pa, void (* processa)(void *p)) {
    if (pa->rootNode != NULL) {
        if (pa->rootNode->leftChildNode != NULL) {
            visitNodesRecursive(pa->rootNode->leftChildNode, processa);
        }
        if (pa->rootNode->rightChildNode != NULL) {
            visitNodesRecursive(pa->rootNode->rightChildNode, processa);
        }
        processa(pa->rootNode->element);
    }
    return SUCESSO;
}