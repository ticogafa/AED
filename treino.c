#include <stdio.h>
#include <stdlib.h>

typedef struct Node {

    int chave;
    struct Node *esquerda, *direita;

}Node;

int main(){



    return 0;
}

int altura(Node *raiz){
    if(raiz  == NULL) return -1;
    
    int alturaEsquerda = altura(raiz->esquerda);
    int alturaDireita = altura(raiz->direita);

    if(alturaEsquerda>alturaDireita) return alturaEsquerda + 1;
    else return alturaDireita + 1;

}

void rodarDireita(Node **raiz){

    Node *aux = (*raiz)->esquerda;
    (*raiz)->esquerda = aux->direita;
    aux->direita = *raiz;
    *raiz = aux;
}

void rodarEsquerda(Node **raiz){

    Node *aux = (*raiz)->direita;
    (*raiz)->direita = aux->esquerda;
    aux->esquerda = *raiz;
    *raiz = aux;
}

