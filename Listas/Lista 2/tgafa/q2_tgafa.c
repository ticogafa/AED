#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char nome[31];
    int valor;
    struct Node* prox;
    struct Node* ant;
} Node;

Node* criarNode(const char* nome, int valor) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    strncpy(newNode->nome, nome, 30);
    newNode->nome[30] = '\0';
    newNode->valor = valor;
    newNode->prox = newNode->ant = NULL;
    return newNode;
}

void insertNode(Node** head, Node* newNode) {
    if (*head == NULL) {
        *head = newNode;
        newNode->prox = newNode->ant = newNode;
    } else {
        newNode->prox = *head;
        newNode->ant = (*head)->ant;
        (*head)->ant->prox = newNode;
        (*head)->ant = newNode;
    }
}

char* jogar(Node* head) {
    Node* atual = head;
    while (atual->prox != atual) {
        int passos = atual->valor;
        int direcao = (passos % 2 == 0) ? 1 : -1;

        for (int i = 0; i < passos; i++) {
            atual = (direcao == 1) ? atual->prox : atual->ant;
        }

        Node* remover = atual;
        atual = (direcao == 1) ? atual->prox : atual->ant;

        remover->ant->prox = remover->prox;
        remover->prox->ant = remover->ant;
        free(remover);
    }

    char* nomeDoVencedor = (char*)malloc(31 * sizeof(char));
    strncpy(nomeDoVencedor, atual->nome, 30);
    nomeDoVencedor[30] = '\0';

    free(atual);
    return nomeDoVencedor;
}

int main() {
    int N;
    while (scanf("%d", &N) == 1 && N != 0) {
        Node* head = NULL;
        for (int i = 0; i < N; i++) {
            char nome[31];
            int valor;
            scanf("%s %d", nome, &valor);
            insertNode(&head, criarNode(nome, valor));
        }

        char* vencedor = jogar(head);
        printf("Vencedor(a): %s\n", vencedor);
        free(vencedor);
    }

    return 0;
}