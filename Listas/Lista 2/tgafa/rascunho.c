#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char nome[30];
    int valor;
    struct Node *prev;
    struct Node *next;
}Node;

void remover(Node **head, Node **tail, Node *node);
void inserir(Node **head, Node **tail, char *nome, int valor);

int main() {
    while (1) {
        int N, i, j;
        Node *head = NULL;
        Node *tail = NULL;

        scanf("%d", &N);
        if (!N)
            break;

        for (i = 0; i < N; ++i) {
            char nome[30];
            int valor;
            scanf("%s%d", nome, &valor);
            inserir(&head, &tail, nome, valor);
        }

        Node *aux = head;
        while (N > 1) {
            int valor = aux->valor;

            if (valor % 2) {
                for (j = 0; j < valor; ++j)
                    aux = aux->next;
            } else {
                for (j = 0; j < valor; ++j)
                    aux = aux->prev;
            }

            Node *temp = aux;
            if (valor % 2) {
                aux = aux->next;
            } else {
                aux = aux->prev;
            }
            remover(&head, &tail, temp);

            --N;
        }

        printf("Vencedor(a): %s\n", head->nome);
        free(head);
    }

    return 0;
}

void remover(Node **head, Node **tail, Node *node) {
    if (node->next == node) {
        *head = NULL;
        *tail = NULL;
    } else {
        Node *NodeAnterior = node->prev;
        Node *NodeProximo = node->next;
        NodeAnterior->next = NodeProximo;
        NodeProximo->prev = NodeAnterior;
        if (*head == node) {
            *head = NodeProximo;
        }
        if (*tail == node) {
            *tail = NodeAnterior;
        }
    }
    free(node);
}

void inserir(Node **head, Node **tail, char *nome, int valor) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->nome, nome);
    newNode->valor = valor;

    if (*head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        *head = newNode;
        *tail = newNode;
    } else {
        newNode->next = *head;
        newNode->prev = *tail;
        (*tail)->next = newNode;
        (*head)->prev = newNode;
        *tail = newNode;
    }
}