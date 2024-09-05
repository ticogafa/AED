
//Desenvolva o código para a Inserção no final da lista duplamente encadeada.
//considere que EXISTE a tail

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{

    int data;
    struct Node *next;
    struct Node *prev;
}Node;

void inserirFinal(Node **head, Node **tail, int n) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode) {
        newNode->data = n;
        newNode->next = NULL;
        newNode->prev = *tail;

        if (*tail) {
            (*tail)->next = newNode;
        } else {
            *head = newNode;
        }

        *tail = newNode;
    } else {
        printf("Erro ao alocar memória\n");
    }
}