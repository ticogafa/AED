//Desenvolva o código para a Remoção no final da lista duplamente encadeada.
//considere que NÃO EXISTE a tail

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{

    int data;
    struct Node *next;
    struct Node *prev;
}Node;

void removerFinal(Node **head) {
    if (*head != NULL) {
        Node *aux = *head;

        while (aux->next != NULL) {
            aux = aux->next;
        }

        if (aux->prev == NULL) {
            *head = NULL;
        } else {
            aux->prev->next = NULL;
        }

        free(aux);
    } else {
        printf("\nNão há nada para remover\n");
    }
}