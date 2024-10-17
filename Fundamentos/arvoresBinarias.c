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
void remover(Node **pRaiz, int numero);
Node *MaiorDireita(Node **no);
void inordem(Node *raiz);
void posordem(Node *raiz);
int buscar(Node *raiz, int chave);

int main(){

    Node *root = NULL;
    inserir(&root, 5);
    inserir(&root, 2);
    inserir(&root, 4);
    inserir(&root, 1);
    inserir(&root, 3);
    inserir(&root, 6);

    printf("\nBuscar número 4: %d\n", buscar(root, 4));
    preordem(root);
    printf("\n");
    remover(&root, 4);
    printf("\nBuscar número 4: %d\n", buscar(root, 4));
    preordem(root);
    printf("\n");
    liberarArvore(root);

    return 0;

}

int buscar(Node *raiz, int chave){

    if(raiz == NULL) return 0;
    else if(raiz->chave == chave) return 1;
    else if(chave < raiz->chave) return buscar(raiz->esquerda, chave);
    else return buscar(raiz->direita, chave);
}
 
void inserir(Node **raiz, int chave){

    if(*raiz == NULL){
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->chave = chave;
        newNode->esquerda = NULL;
        newNode->direita = NULL;
        *raiz = newNode;
    }else{
        if((*raiz)->chave > chave){
            inserir(&(*raiz)->esquerda, chave);
        }else if((*raiz)->chave < chave){
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

void inordem(Node *raiz) {
  if (raiz != NULL) {
    inordem(raiz->esquerda);
    printf("%d ", raiz->chave);
    inordem(raiz->direita);
  }
}

void posordem(Node *raiz) {
  if (raiz != NULL) {
    posordem(raiz->esquerda);
    posordem(raiz->direita);
    printf("%d ", raiz->chave);
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

Node *MaiorDireita(Node **raiz) {
  if ((*raiz)->direita != NULL)
    return MaiorDireita(&(*raiz)->direita);
  else {
    Node *aux = *raiz;
    if ((*raiz)->esquerda != NULL) {
      *raiz = (*raiz)->esquerda;
    } else {
      *raiz = NULL;
    }
    return aux;
  }
}

void remover(Node **raiz, int numero) {
  if (*raiz == NULL) {
    printf("Numero nao existe na arvore!");
    return;
  }
  if (numero < (*raiz)->chave)
    remover(&(*raiz)->esquerda, numero);
  else if (numero > (*raiz)->chave)
    remover(&(*raiz)->direita, numero);
  else {
    Node *aux = *raiz;
    // 01 - no sem filhos
    if (((*raiz)->esquerda == NULL) && ((*raiz)->direita == NULL)) {
      free(aux);
      (*raiz) = NULL;
    } else {
      // 02 - no com filho direito
      if ((*raiz)->esquerda == NULL) {
        (*raiz) = (*raiz)->direita;
        aux->direita = NULL;
        free(aux);
      } else {
        // 02 - no com filho esquerdo
        if ((*raiz)->direita == NULL) {
          (*raiz) = (*raiz)->esquerda;
          aux->esquerda = NULL;
          free(aux);
        } else {
          // 03 - no com dois filhos
          aux = MaiorDireita(&(*raiz)->esquerda);
          aux->esquerda = (*raiz)->esquerda;
          aux->direita = (*raiz)->direita;
          free(*raiz);
          *raiz = aux;
        }
      }
    }
  }
}

