#include <stdio.h>
#include <stdlib.h>

typedef struct Node {

    int chave;
    struct Node *esquerda, *direita;

}Node;

int altura(Node *raiz);
void rodarDireita(Node **raiz);
void rodarEsquerda(Node **raiz);
void balanceamento(Node **raiz);
void inserir(Node **raiz, int chave);
void inordem(Node *raiz);

int main(){

    Node *raiz = NULL;

    inserir(&raiz, 10);
    inserir(&raiz, 20);
    inserir(&raiz, 30);
    inserir(&raiz, 40);
    inserir(&raiz, 50);
    inserir(&raiz, 25);

    printf("Altura da árvore: %d\n", altura(raiz));
    printf("Árvore In Ordem: \n");
    inordem(raiz);

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

void balanceamento(Node **raiz){

if(*raiz != NULL){


    Node *aux;
    int fatorBalanceamento = altura((*raiz)->direita) - altura((*raiz)->esquerda);

    if(fatorBalanceamento < -1){
        aux = (*raiz)->esquerda;
        fatorBalanceamento = altura(aux->direita) - altura(aux->esquerda);

        if(fatorBalanceamento > 0){
            rodarEsquerda(&(*raiz)->esquerda);
            rodarDireita(raiz);
            printf("Rotação dupla à direita\n");
        }else{
            rodarDireita(raiz);
            printf("Rotação direita simples\n");
        }
    }else if(fatorBalanceamento > 1){
        aux = (*raiz)->direita;
        fatorBalanceamento = altura(aux->direita) - altura(aux->esquerda);

        if(fatorBalanceamento < 0){
            rodarDireita(&(*raiz)->direita);
            rodarEsquerda(raiz);
            printf("Rotação dupla à esquerda\n");
        }else {
            rodarEsquerda(raiz);
            printf("Rotação simples à esquerda\n");
        }
    }

}
}

void inserir(Node **raiz, int chave){
    if(*raiz == NULL){

        *raiz = (Node *)malloc(sizeof(Node));
        (*raiz)->esquerda = NULL;
        (*raiz)->direita = NULL;
        (*raiz)->chave = chave;
    }else if((*raiz)->chave < chave) inserir(&(*raiz)->direita, chave);
    else if((*raiz)->chave > chave) inserir(&(*raiz)->esquerda, chave);

    balanceamento(raiz);
}

void inordem(Node *raiz){

    if(raiz!= NULL){
        inordem(raiz->esquerda);
        printf("%d ", raiz->chave);
        inordem(raiz->direita);
    }
}