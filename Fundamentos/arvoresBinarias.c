#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int chave;
    struct Node *esquerda, *direita;
} Node;

void inserir(Node **raiz, int chave);
int altura(Node *raiz);
void preordem(Node *raiz);
void liberarArvore(Node *raiz);
Node* encontrarMaior(Node *raiz);
void remover(Node **pRaiz, int numero);
Node *MaiorDireita(Node **no);
void inordem(Node *raiz);
void posordem(Node *raiz);
int buscar(Node *raiz, int chave);

int main() {
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
    printf("\nAltura da árvore: %d\n", altura(root));
    remover(&root, 4);
    printf("\nBuscar número 4: %d\n", buscar(root, 4));
    preordem(root);
    printf("\n");
    printf("\nAltura da árvore: %d\n", altura(root));
    liberarArvore(root);


    return 0;
}

int buscar(Node *raiz, int chave) {
    if (raiz == NULL) return 0;
    else if (raiz->chave == chave) return 1;
    else if (chave < raiz->chave) return buscar(raiz->esquerda, chave);
    else return buscar(raiz->direita, chave);
}

void inserir(Node **raiz, int chave) {
    if (*raiz == NULL) {
        Node *newNode = (Node*)malloc(sizeof(Node));
        if (newNode == NULL) {
            fprintf(stderr, "Erro ao alocar memória\n");
            exit(EXIT_FAILURE);
        }
        newNode->chave = chave;
        newNode->esquerda = NULL;
        newNode->direita = NULL;
        *raiz = newNode;
    } else {
        if ((*raiz)->chave > chave) {
            inserir(&(*raiz)->esquerda, chave);
        } else if ((*raiz)->chave < chave) {
            inserir(&(*raiz)->direita, chave);
        }
    }
}

void preordem(Node *raiz) {
    if (raiz != NULL) {
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
        printf("Numero nao existe na arvore!\n");
        return;
    }
    if (numero < (*raiz)->chave) {
        remover(&(*raiz)->esquerda, numero);
    } else if (numero > (*raiz)->chave) {
        remover(&(*raiz)->direita, numero);
    } else {
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

int altura(Node *raiz) {
    if (raiz == NULL) {
        return -1;
    } else {
        int alturaEsquerda = altura(raiz->esquerda);
        int alturaDireita = altura(raiz->direita);
        if (alturaEsquerda > alturaDireita) {
            return alturaEsquerda + 1;
        } else {
            return alturaDireita + 1;
        }
    }
}