#include <stdio.h>
#include <stdlib.h>

typedef struct arv {
  int num;
  struct arv *esq;
  struct arv *dir;
} Arv;

int filhosAlt(Arv *r);
void roda_dir(Arv **p);
void roda_esq(Arv **p);
void balanco(Arv **p);
void inserir(Arv **t, int num);
void preordem(Arv *t);
void remover(Arv **pRaiz, int numero);
Arv *MaiorDireita(Arv **no);

int main() {
  Arv *t = NULL;

  inserir(&t, 6);
  inserir(&t, 10);
  inserir(&t, 15);
  printf("\n>>Rotação devido a inserção do 15\n");

  inserir(&t, 3);
  inserir(&t, 1);
  printf("\n>>Rotação devido a inserção do 1\n");

  printf("\nPRE-ordem:");
  preordem(t);
  printf("\n");

  return 0;
} 

int filhosAlt(Arv *raiz) {
  if (raiz == NULL)
    return 0;
  else {
    int ae = filhosAlt(raiz->esq);
    int ad = filhosAlt(raiz->dir);
    return 1 + (ae > ad ? ae : ad);
  }
}

void roda_dir(Arv **raiz) {
  Arv *aux = (*raiz)->esq;
  (*raiz)->esq = aux->dir;
  aux->dir = (*raiz);
  *raiz = aux;
}

void roda_esq(Arv **raiz) {
  Arv *aux = (*raiz)->dir;
  (*raiz)->dir = aux->esq;
  aux->esq = (*raiz);
  *raiz = aux;
}

void balanco(Arv **raiz) {
  if(*raiz != NULL){
    Arv *aux;
    int fatorBalanceamento = filhosAlt((*raiz)->dir) - filhosAlt((*raiz)->esq);

    if (fatorBalanceamento <= -2) {
      aux = (*raiz)->esq;
      fatorBalanceamento = filhosAlt(aux->dir) - filhosAlt(aux->esq);

      if (fatorBalanceamento > 0) {
        roda_esq(&((*raiz)->esq));  
        roda_dir(raiz);
        printf("\nRotação: Dupla Direita");
      } else {
        roda_dir(raiz);
        printf("\nRotação: Direita Simples");
      }
    } else if (fatorBalanceamento >= 2) {
      aux = (*raiz)->dir;
      fatorBalanceamento = filhosAlt(aux->dir) - filhosAlt(aux->esq);

      if (fatorBalanceamento < 0) {
        roda_dir(&((*raiz)->dir));
        roda_esq(raiz);
        printf("\nRotação: Dupla Esquerda");
      } else {
        roda_esq(raiz);
        printf("\nRotação: Esquerda Simples");
      }
    }
  }
}

void preordem(Arv *t) {
  if (t != NULL) {
    printf("%d ", t->num);
    preordem(t->esq);
    preordem(t->dir);
  }
}

void inserir(Arv **raiz, int n) {
  if (*raiz == NULL) {

    *raiz = (Arv *)malloc(sizeof(Arv));
    (*raiz)->esq = NULL;
    (*raiz)->dir = NULL;
    (*raiz)->num = n;

  } else if (n < (*raiz)->num) inserir(&(*raiz)->esq, n);
    else if (n > (*raiz)->num) inserir(&(*raiz)->dir, n);

    balanco(raiz);
}

Arv *MaiorDireita(Arv **raiz) {
  if ((*raiz)->dir != NULL)
    return MaiorDireita(&(*raiz)->dir);
  else {
    Arv *aux = *raiz;
    if ((*raiz)->esq != NULL) {
      *raiz = (*raiz)->esq;
    } else {
      *raiz = NULL;
    }
    return aux;
  }
}

void remover(Arv **pRaiz, int numero) {
  if (*pRaiz == NULL) {
    printf("\nRemoção: Numero nao existe na arvore!");
    return;
  }
  else if (numero < (*pRaiz)->num)
    remover(&(*pRaiz)->esq, numero);
  else if (numero > (*pRaiz)->num)
    remover(&(*pRaiz)->dir, numero);
  else {
    Arv *pAux = *pRaiz;
    // 01 - no sem filhos
    if (((*pRaiz)->esq == NULL) && ((*pRaiz)->dir == NULL)) {
      free(pAux);
      (*pRaiz) = NULL;
    } 
    else {
      // 02 - no com filho direito
      if ((*pRaiz)->esq == NULL) {
        (*pRaiz) = (*pRaiz)->dir;
        pAux->dir = NULL;
        free(pAux);
        pAux = NULL;
      } 
      else {
        // 02 - no com filho esquerdo
        if ((*pRaiz)->dir == NULL) {
          (*pRaiz) = (*pRaiz)->esq;
          pAux->esq = NULL;
          free(pAux);
          pAux = NULL;
        } else {
          // 03 - no com dois filhos
          pAux = MaiorDireita(&(*pRaiz)->esq);
          pAux->esq = (*pRaiz)->esq;
          pAux->dir = (*pRaiz)->dir;
          (*pRaiz)->esq = (*pRaiz)->dir = NULL;
          free((*pRaiz));
          *pRaiz = pAux;
          pAux = NULL;
        }
      }
    }
  }
  balanco(pRaiz);
}