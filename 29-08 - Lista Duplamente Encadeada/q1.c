
//Desenvolva o código para a Inserção no final da lista duplamente encadeada.
//considere que NÃO EXISTE a tail

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{

    int data;
    struct Node *next;
    struct Node *prev;
}Node;

void inserirFinal(Node **head, int n) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode) {
        newNode->data = n;
        newNode->next = NULL;

        if (*head == NULL) {
            newNode->prev = NULL;
            *head = newNode;
        } else {
            Node *aux = *head;
            while (aux->next != NULL) {
                aux = aux->next;
            }
            aux->next = newNode;
            newNode->prev = aux;
        }
    } else {
        printf("Erro ao alocar memória\n");
    }
}