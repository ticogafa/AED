#include <stdio.h>
#include <stdlib.h>

typedef struct Node {

    int chave;
    struct Node *esquerda, *direita;
}Node;

void inserir(Node **raiz, int chave);
void preordem(Node *raiz);

int main(){

    Node *root = NULL;

    return 0;

}
 
void inserir(Node **raiz, int chave){

    if(*raiz == NULL){
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->chave  = chave;
        (*raiz)->esquerda = NULL;
        (*raiz)->direita = NULL;
    }else{
        if(chave < (*raiz)->chave){
            inserir(&(*raiz)->esquerda, chave);
        }else if(chave> (*raiz)->chave){
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