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

Node *MaiorDireita(Node **no) {
  if ((*no)->direita != NULL)
    return MaiorDireita(&(*no)->direita);
  else {
    Node *aux = *no;
    if ((*no)->esquerda != NULL) {
      *no = (*no)->esquerda;
    } else {
      *no = NULL;
    }
    return aux;
  }
}

void remover(Node **pRaiz, int numero) {
  if (*pRaiz == NULL) {
    printf("Numero nao existe na arvore!");
    return;
  }
  if (numero < (*pRaiz)->chave)
    remover(&(*pRaiz)->esquerda, numero);
  else if (numero > (*pRaiz)->chave)
    remover(&(*pRaiz)->direita, numero);
  else {
    Node *pAux = *pRaiz;
    // 01 - no sem filhos
    if (((*pRaiz)->esquerda == NULL) && ((*pRaiz)->direita == NULL)) {
      free(pAux);
      (*pRaiz) = NULL;
    } else {
      // 02 - no com filho direito
      if ((*pRaiz)->esquerda == NULL) {
        (*pRaiz) = (*pRaiz)->direita;
        pAux->direita = NULL;
        free(pAux);
      } else {
        // 02 - no com filho esquerdo
        if ((*pRaiz)->direita == NULL) {
          (*pRaiz) = (*pRaiz)->esquerda;
          pAux->esquerda = NULL;
          free(pAux);
        } else {
          // 03 - no com dois filhos
          pAux = MaiorDireita(&(*pRaiz)->esquerda);
          pAux->esquerda = (*pRaiz)->esquerda;
          pAux->direita = (*pRaiz)->direita;
          free(*pRaiz);
          *pRaiz = pAux;
        }
      }
    }
  }
}

