#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura da árvore binária
typedef struct No {
    int chave;
    struct No* esq;
    struct No* dir;
} Arv;

Arv *buscaPai(Arv *raiz, int chave) {
    Arv *pai = NULL;
    Arv *atual = raiz;

    if (raiz == NULL) {
        printf("Árvore vazia!\n");
        return NULL;
    }

    while (atual != NULL) {
        if (atual->chave == chave) {
            return pai;
        }
        pai = atual;
        if (chave < atual->chave) {
            atual = atual->esq;
        } else {
            atual = atual->dir;
        }
    }

    printf("Nó não encontrado na árvore!\n");
    return NULL;
}

int main() {
    // Cria uma árvore binária de exemplo
    Arv* raiz = (Arv*)malloc(sizeof(Arv));
    raiz->chave = 10;
    raiz->esq = (Arv*)malloc(sizeof(Arv));
    raiz->esq->chave = 5;
    raiz->esq->esq = NULL;
    raiz->esq->dir = NULL;
    raiz->dir = (Arv*)malloc(sizeof(Arv));
    raiz->dir->chave = 15;
    raiz->dir->esq = NULL;
    raiz->dir->dir = NULL;

    // Busca o nó pai do nó com chave 5
    Arv* pai = buscaPai(raiz, 5);
    if (pai != NULL) {
        printf("Nó pai encontrado:\n");
        printf("Chave: %d\n", pai->chave);
        printf("Endereço do nó esquerdo: %p\n", pai->esq);
        printf("Endereço do nó direito: %p\n", pai->dir);
    }

    // Busca o nó pai do nó com chave 15
    pai = buscaPai(raiz, 15);
    if (pai != NULL) {
        printf("Nó pai encontrado:\n");
        printf("Chave: %d\n", pai->chave);
        printf("Endereço do nó esquerdo: %p\n", pai->esq);
        printf("Endereço do nó direito: %p\n", pai->dir);
    }

    // Busca o nó pai de um nó que não existe na árvore
    pai = buscaPai(raiz, 20);

    return 0;
}