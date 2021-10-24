#include "ABB_privado.h"
#include "stdlib.h"
#include "string.h"
#include "stdio.h"

pNode findRecursive(pNode origin, void *item, int (* cmp)(void *p1, void *p2)) {
    pNode result = NULL;
    if (cmp(item, origin->element) == 0) {
        result = origin;
    } else {
        if (origin->leftChildNode != NULL){
            result = findRecursive(origin->leftChildNode, item, cmp);
        }
        if (result == NULL && origin->rightChildNode != NULL){
            result = findRecursive(origin->rightChildNode, item, cmp);
        }
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

int findAndInsertRecursive(pNode origin, void* element, int elementSize, int (* cmp)(void *p1, void *p2)) {
    int compResult = cmp(element, origin->element);
    if (compResult == 0) {
        return FRACASSO;
    }
    else if (compResult > 0) {
        if (origin->rightChildNode == NULL) {
            origin->rightChildNode = createNode(element, elementSize);
            return SUCESSO;
        } else {
            return findAndInsertRecursive(origin->rightChildNode, element, elementSize, cmp);
        }
    } else {
        if (origin->leftChildNode == NULL) {
            origin->leftChildNode = createNode(element, elementSize);
            return SUCESSO;
        } else {
            return findAndInsertRecursive(origin->leftChildNode, element, elementSize, cmp);
        }
    }
}

int criaABB(ppABB pp, int tamInfo) {
    *pp = (pABB) malloc(sizeof(struct ABB));
    if (*pp == NULL) {
        return FRACASSO;
    }
    (*pp)->currentSize = 0;
    (*pp)->rootNode = NULL;
    (*pp)->elementSize = tamInfo;
    return SUCESSO;
}

int destroiABB(ppABB pp) {
    if ((*pp)->currentSize != 0) {
        destroySubTreeRecursive((*pp)->rootNode);
    }
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
    } else if (findRecursive(p->rootNode, item, cmp) != NULL){
        return SUCESSO;
    } else {
        return FRACASSO;
    }
}

int insereABB(pABB p, void *novo, int (* cmp)(void *p1, void *p2)) {
    if (p->rootNode == NULL) {
        p->rootNode = createNode(novo, p->elementSize);
    } else {
        return findAndInsertRecursive(p->rootNode, novo, p->elementSize, cmp);
    }
    p->currentSize++;
    return SUCESSO;
}

pNode createNode(void* element, int elementSize) {
    pNode p = malloc(sizeof(struct Node));
    p->element = malloc(elementSize);
    p->leftChildNode = NULL;
    p->rightChildNode = NULL;
    memcpy(p->element, element, elementSize);
    return p;
}

void visitNodesRecursivePosOrdem(pNode origin, void (* processa)(void *p)) {
    if (origin->leftChildNode != NULL) {
        visitNodesRecursivePosOrdem(origin->leftChildNode, processa);
    }
    if (origin->rightChildNode != NULL) {
        visitNodesRecursivePosOrdem(origin->rightChildNode, processa);
    }
    processa(origin->element);
}

void visitNodesRecursivePreOrdem(pNode origin, void (* processa)(void *p)) {
    processa(origin->element);
    if (origin->leftChildNode != NULL) {
        visitNodesRecursivePreOrdem(origin->leftChildNode, processa);
    }
    if (origin->rightChildNode != NULL) {
        visitNodesRecursivePreOrdem(origin->rightChildNode, processa);
    }
}

void visitNodesRecursiveOrdem(pNode origin, void (* processa)(void *p)) {
    if (origin->leftChildNode != NULL) {
        visitNodesRecursiveOrdem(origin->leftChildNode, processa);
    }
    processa(origin->element);
    if (origin->rightChildNode != NULL) {
        visitNodesRecursiveOrdem(origin->rightChildNode, processa);
    }
}

int percursoPreOrdem(pABB pa, void (* processa)(void *p)) {
    if (pa->rootNode != NULL) {
        processa(pa->rootNode->element);
        if (pa->rootNode->leftChildNode != NULL) {
            visitNodesRecursivePreOrdem(pa->rootNode->leftChildNode, processa);
        }
        if (pa->rootNode->rightChildNode != NULL) {
            visitNodesRecursivePreOrdem(pa->rootNode->rightChildNode, processa);
        }
    }
    return SUCESSO;
}

int percursoEmOrdem(pABB pa, void (* processa)(void *p)) {
    if (pa->rootNode != NULL) {
        if (pa->rootNode->leftChildNode != NULL) {
            visitNodesRecursiveOrdem(pa->rootNode->leftChildNode, processa);
        }
        processa(pa->rootNode->element);
        if (pa->rootNode->rightChildNode != NULL) {
            visitNodesRecursiveOrdem(pa->rootNode->rightChildNode, processa);
        }
    }
    return SUCESSO;
}

int percursoPosOrdem(pABB pa, void (* processa)(void *p)) {
    if (pa->rootNode != NULL) {
        if (pa->rootNode->leftChildNode != NULL) {
            visitNodesRecursivePosOrdem(pa->rootNode->leftChildNode, processa);
        }
        if (pa->rootNode->rightChildNode != NULL) {
            visitNodesRecursivePosOrdem(pa->rootNode->rightChildNode, processa);
        }
        processa(pa->rootNode->element);
    }
    return SUCESSO;
}

int removeNodeUsingSuccessor(pNode nodeToRemove, pNode parent, int side) {
    if (nodeToRemove->rightChildNode->leftChildNode == NULL) {
        if (side == 1) {
            parent->leftChildNode = nodeToRemove->rightChildNode;
            parent->leftChildNode->leftChildNode = nodeToRemove->leftChildNode;
        } else {
            parent->rightChildNode = nodeToRemove->rightChildNode;
            parent->rightChildNode->leftChildNode = nodeToRemove->leftChildNode;
        }
    } else {
        pNode successor = nodeToRemove->rightChildNode->leftChildNode;
        nodeToRemove->rightChildNode->leftChildNode = successor->rightChildNode;
        successor->rightChildNode = nodeToRemove->rightChildNode;
        successor->leftChildNode = nodeToRemove->leftChildNode;
        if (parent != NULL) {
            if (side == 1) {
                parent->leftChildNode = successor;
            } else {
                parent->rightChildNode = successor;
            }
        }
    }
    return SUCESSO;
}

int removeNode(pABB p, pNode nodeToRemove, pNode parent, int side) {
    int childCount = 0;
    int result = SUCESSO;
    if (nodeToRemove->leftChildNode != NULL) {
        childCount++;
    }
    if (nodeToRemove->rightChildNode != NULL) {
        childCount++;
    }
    if (childCount == 0 && parent != NULL) {
        if (side == 1) {
            parent->leftChildNode = NULL;
        } else if (side == 2) {
            parent->rightChildNode = NULL;
        }
    } else if (childCount == 1 && nodeToRemove->leftChildNode != NULL) {
        if (parent == NULL) {
            p->rootNode = nodeToRemove->leftChildNode;
        } else if (side == 1) {
            parent->leftChildNode = nodeToRemove->leftChildNode;
        } else {
            parent->rightChildNode = nodeToRemove->leftChildNode;
        }
    } else if (childCount == 1 && nodeToRemove->rightChildNode != NULL) {
        if (parent == NULL) {
            p->rootNode = nodeToRemove->rightChildNode;
        } else if (side == 1) {
            parent->leftChildNode = nodeToRemove->rightChildNode;
        } else {
            parent->rightChildNode = nodeToRemove->rightChildNode;
        }
    } else if (childCount == 2) {
        result = removeNodeUsingSuccessor(nodeToRemove, parent, side);
    }
    free(nodeToRemove->element);
    free(nodeToRemove);
    return result;
}

int findAndRemoveRecursive(pABB p, pNode origin, pNode parent, int side, void *item, int (* cmp)(void *p1, void *p2)) {
    int result = FRACASSO;
    if (cmp(item, origin->element) == 0) {
        result = removeNode(p, origin, parent, side);
    } else if (origin->leftChildNode != NULL) {
        result = findAndRemoveRecursive(p, origin->leftChildNode, origin, 1, item, cmp);
    }
    if (result == FRACASSO && origin->rightChildNode != NULL){
        result = findAndRemoveRecursive(p, origin->rightChildNode, origin, 2, item, cmp);
    }
    return result;
}

int removeABB(pABB p, void *item, int (* cmp)(void *p1, void *p2)) {
    if (p->rootNode == NULL) {
        return FRACASSO;
    }
    int result = findAndRemoveRecursive(p, p->rootNode, NULL, 0, item, cmp);
    if (result == SUCESSO) {
        p->currentSize--;
    }
    return result;
}