#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int chave;
    struct No* esq;
    struct No* dir;
} Arv;

int qtdFolhas(Arv *raiz) {
    if (raiz == NULL) {
        return 0;
    }

    if (raiz->esq == NULL && raiz->dir == NULL) {
        return 1;
    }

    return qtdFolhas(raiz->esq) + qtdFolhas(raiz->dir);
}

int main() {
    Arv* raiz = (Arv*)malloc(sizeof(Arv));
    raiz->chave = 10;
    raiz->esq = (Arv*)malloc(sizeof(Arv));
    raiz->esq->chave = 5;
    raiz->esq->esq = (Arv*)malloc(sizeof(Arv));
    raiz->esq->esq->chave = 3;
    raiz->esq->esq->esq = NULL;
    raiz->esq->esq->dir = NULL;
    raiz->esq->dir = (Arv*)malloc(sizeof(Arv));
    raiz->esq->dir->chave = 7;
    raiz->esq->dir->esq = NULL;
    raiz->esq->dir->dir = NULL;
    raiz->dir = (Arv*)malloc(sizeof(Arv));
    raiz->dir->chave = 15;
    raiz->dir->esq = NULL;
    raiz->dir->dir = (Arv*)malloc(sizeof(Arv));
    raiz->dir->dir->chave = 20;
    raiz->dir->dir->esq = NULL;
    raiz->dir->dir->dir = NULL;

    int numFolhas = qtdFolhas(raiz);
    printf("Quantidade de folhas na árvore: %d\n", numFolhas);

    // Liberar memória alocada
    free(raiz->dir->dir);
    free(raiz->dir);
    free(raiz->esq->dir);
    free(raiz->esq->esq);
    free(raiz->esq);
    free(raiz);

    return 0;
}
