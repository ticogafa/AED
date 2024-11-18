#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int chave;
    struct Node *esquerda, *direita;
} Node;

int main(){



    return 0;
}


void inserir (Node **raiz, int chave){

    if(*raiz==NULL){
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->chave = chave;
        newNode->esquerda = NULL;
        newNode->direita = NULL;
        *raiz=newNode;
    }else{
        if((*raiz)->chave < chave){
            inserir(&(*raiz)->direita, chave);
        }else if((*raiz)->chave > chave){
            inserir(&(*raiz)->esquerda, chave);
        }
    }

}

void preordem(Node *raiz){

    if(raiz!=NULL){
        printf("%d ", raiz->chave);
        preordem(raiz->esquerda);
        preordem(raiz->direita);
    }
}

void inordem(Node *raiz){
    if(raiz!=NULL){
        inordem(raiz->esquerda);
        printf("%d ", raiz->chave);
        inordem(raiz->direita);
    }
}

void posordem(Node *raiz){
    if(raiz!=NULL){
        posordem(raiz->esquerda);
        posordem(raiz->direita);
        printf("%d ", raiz->chave);
    }
}

void buscar(Node *raiz, int chave){
    if(raiz == NULL) return 0;
    else if(raiz->chave == chave) return 1;
    else if(raiz->chave > chave) return buscar(raiz->esquerda, chave);
    else return buscar(raiz->direita, chave);
}

void liberar(Node *raiz){
    if(raiz!=NULL){
        liberar(raiz->esquerda);
        liberar(raiz->direita);
        free(raiz);
    }
}

Node* encontrarMaior(Node *raiz){
    if(raiz == NULL) return NULL;
    if(raiz->direita == NULL) return raiz;
    return encontrarMaior(raiz->direita);
}

Node* MaiorDireita(Node **raiz){
    if((*raiz)->direita != NULL) return MaiorDireita(&(*raiz)->direita);
    else{
        Node *aux = *raiz;
        
        if((*raiz)->esquerda!=NULL) *raiz = (*raiz)->esquerda;
        else *raiz == NULL;

        return aux;
    }
}

void remover(Node **raiz, int chave){
    if(*raiz == NULL) return;
    if(chave > (*raiz)->chave) remover(&(*raiz)->direita, chave);
    else if(chave < (*raiz)->chave) remover(&(*raiz)->esquerda, chave);
    else{
        Node *aux = *raiz;

        if((*raiz)->esquerda == NULL && (*raiz)->direita == NULL){
            free(aux);
            *raiz == NULL;
        }else if((*raiz)->esquerda == NULL){
            *raiz = (*raiz)->direita;
            free(aux);
        }else if((*raiz)->direita == NULL){
            *raiz = (*raiz)->esquerda;
            free(aux);
        }else{
            aux = MaiorDireita(&(*raiz)->esquerda);
            aux->esquerda = (*raiz)->esquerda;
            aux->direita = (*raiz)->direita;
            free(*raiz);
            *raiz = aux;
        }
    }
}