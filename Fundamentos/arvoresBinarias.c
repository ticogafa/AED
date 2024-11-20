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
int altura(Node *raiz);
void filhosEsquerdos(Node *raiz);

int main(){

    Node *raiz = NULL;

    inserir(&raiz, 4);
    inserir(&raiz, 2);
    inserir(&raiz, 7);
    inserir(&raiz, 1);
    inserir(&raiz, 3);
    inserir(&raiz, 5);
    inserir(&raiz, 8);

    printf("\nFilhos esquerdos da árvore: \n");
    filhosEsquerdos(raiz);

    printf("Pre-ordem: ");
    preordem(raiz);
    printf("\n");

    printf("In-ordem: ");
    inordem(raiz);
    printf("\n");

    printf("Pos-ordem: ");
    posordem(raiz);
    printf("\n");

    printf("Altura da árvore: %d\n", altura(raiz));

    int chave = 2;
    if(buscar(raiz, chave))
        printf("Chave %d encontrada na árvore.\n", chave);
    else
        printf("Chave %d não encontrada na árvore.\n", chave);

    remover(&raiz, 7);
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
        if ((*raiz)->esquerda == NULL && (*raiz)->direita == NULL) {
            free(aux);
            *raiz = NULL;
        } else if ((*raiz)->esquerda == NULL) { 
            *raiz = (*raiz)->direita;
            free(aux);
        } else if ((*raiz)->direita == NULL) {
            *raiz = (*raiz)->esquerda;
            free(aux);
        } else { 
            aux = MaiorDireita(&(*raiz)->esquerda);
            aux->esquerda = (*raiz)->esquerda;
            aux->direita = (*raiz)->direita;
            free(*raiz);
            *raiz = aux;
        }
    }
}

int altura(Node *raiz){

    if(raiz == NULL) return -1;
    else{
        int alturaEsquerda = altura(raiz->esquerda);
        int alturaDireita = altura(raiz->direita);
        
        if(alturaEsquerda > alturaDireita) return alturaEsquerda + 1;
        else return alturaDireita + 1;
    }
}

void filhosEsquerdos(Node *raiz){
    if(raiz == NULL || raiz->esquerda == NULL) return;
    if(raiz->esquerda != NULL){
        filhosEsquerdos(raiz->esquerda);
        printf("%d ", raiz->esquerda->chave);
    }

    filhosEsquerdos(raiz->direita);
    
}

int arvBalanceada(Node *raiz) {
    if (raiz == NULL) return 1;

    int alturaEsquerda = altura(raiz->esquerda);
    int alturaDireita = altura(raiz->direita);

    int fatorBalanceamento = alturaDireita - alturaEsquerda;

    if (abs(fatorBalanceamento) <= 1 &&
        arvBalanceada(raiz->esquerda) &&
        arvBalanceada(raiz->direita))
        return 1;

    return 0;
}