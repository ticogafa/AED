#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int chave;
    struct No* esq;
    struct No* dir;
} Arv;

int qtdFolhas(Arv *raiz, int chave) {
    if (raiz == NULL) {
        printf("Árvore vazia!\n");
        return 0;
    }

    if (raiz->chave == chave) {
        if (raiz->esq == NULL && raiz->dir == NULL) {
            return 1;
        }
        else {
            return qtdFolhas(raiz->esq, chave) + qtdFolhas(raiz->dir, chave);
        }
    }
    else if (chave < raiz->chave) {
        return qtdFolhas(raiz->esq, chave);
    }
    else {
        return qtdFolhas(raiz->dir, chave);
    }
}

int main() {
    // Cria uma árvore binária de exemplo
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

    // Exibe a quantidade de folhas na subárvore com raiz no nó 5
    int numFolhas = qtdFolhas(raiz, 5);
    printf("Quantidade de folhas na subárvore com raiz no nó 5: %d\n", numFolhas);

    // Exibe a quantidade de folhas na subárvore com raiz no nó 15
    numFolhas = qtdFolhas(raiz, 15);
    printf("Quantidade de folhas na subárvore com raiz no nó 15: %d\n", numFolhas);

    // Tenta acessar um nó que não existe na árvore
    numFolhas = qtdFolhas(raiz, 25);

    return 0;
}