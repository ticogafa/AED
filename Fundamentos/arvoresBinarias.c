#include <stdio.h>
#include <stdlib.h>

typedef struct Node {

    int chave;
    struct Node *esquerda, *direita;
}Node;

void inserir(Node **raiz, int chave);
void preordem(Node *raiz);
void liberarArvore(Node *raiz);
Node* encontrarMaior(Node *raiz);

int main(){

    Node *root = NULL;
    inserir(&root, 5);
    inserir(&root, 2);
    inserir(&root, 4);
    inserir(&root, 1);
    inserir(&root, 3);
    inserir(&root, 6);

    preordem(root);
    liberarArvore(root);


    return 0;

}
 
void inserir(Node **raiz, int chave){

    if(*raiz == NULL){
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->chave  = chave;
        newNode->esquerda = NULL;
        newNode->direita = NULL;
        *raiz = newNode;
    }else{
        if(chave < (*raiz)->chave){
            inserir(&(*raiz)->esquerda, chave);
        }else if(chave > (*raiz)->chave){
            inserir(&(*raiz)->direita, chave);
        }
    }

}

void preordem(Node *raiz){

    if(raiz != NULL){
        printf("%d ", raiz->chave);
        preordem(raiz->esquerda);
        preordem(raiz->direita);
    }

}

void liberarArvore(Node *raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esquerda);
        liberarArvore(raiz->direita);
        free(raiz);
    }
}

Node *encontrarMaior(Node *raiz) {
    if (raiz == NULL) {
        return NULL;
    }
    if (raiz->direita == NULL) {
        return raiz;
    }
    return encontrarMaior(raiz->direita);
}