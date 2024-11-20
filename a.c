#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int chave;
    struct Node *esquerda, *direita;
} Node;

void inserir(Node **raiz, int chave);
void preordem(Node *raiz);
void inordem(Node *raiz);
void posordem(Node *raiz);
int buscar(Node *raiz, int chave);
void liberar(Node *raiz);
Node* encontrarMaior(Node *raiz);
Node* MaiorDireita(Node **raiz);
void remover(Node **raiz, int chave);

int main(){

    Node *raiz = NULL;

    inserir(&raiz, 50);
    inserir(&raiz, 30);
    inserir(&raiz, 70);
    inserir(&raiz, 20);
    inserir(&raiz, 40);
    inserir(&raiz, 60);
    inserir(&raiz, 80);

    printf("Pre-ordem: ");
    preordem(raiz);
    printf("\n");

    printf("In-ordem: ");
    inordem(raiz);
    printf("\n");

    printf("Pos-ordem: ");
    posordem(raiz);
    printf("\n");

    int chave = 40;
    if(buscar(raiz, chave))
        printf("Chave %d encontrada na árvore.\n", chave);
    else
        printf("Chave %d não encontrada na árvore.\n", chave);

    remover(&raiz, 50);
    printf("Árvore após remover a chave 50 (in-ordem): ");
    inordem(raiz);
    printf("\n");

    liberar(raiz);

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

int buscar(Node *raiz, int chave){
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

Node *MaiorDireita(Node **raiz) {
    if ((*raiz)->direita != NULL) return MaiorDireita(&(*raiz)->direita);
    else {
        Node *aux = *raiz;
        if ((*raiz)->esquerda != NULL) *raiz = (*raiz)->esquerda;
        else *raiz = NULL;
        return aux;
    }
}

void remover(Node **raiz, int numero) {
    if (*raiz == NULL) return;
    if (numero < (*raiz)->chave) remover(&(*raiz)->esquerda, numero);
    else if (numero > (*raiz)->chave) remover(&(*raiz)->direita, numero);
    else {
        Node *aux = *raiz;
        // 01 - no sem filhos
        if ((*raiz)->esquerda == NULL && (*raiz)->direita == NULL) {
            free(aux);
            *raiz = NULL;
        } else if ((*raiz)->esquerda == NULL) { // 02 - no com filho direito
            *raiz = (*raiz)->direita;
            free(aux);
        } else if ((*raiz)->direita == NULL) { // 02 - no com filho esquerdo
            *raiz = (*raiz)->esquerda;
            free(aux);
        } else { // 03 - no com dois filhos
            aux = MaiorDireita(&(*raiz)->esquerda);
            aux->esquerda = (*raiz)->esquerda;
            aux->direita = (*raiz)->direita;
            free(*raiz);
            *raiz = aux;
        }
    }
}