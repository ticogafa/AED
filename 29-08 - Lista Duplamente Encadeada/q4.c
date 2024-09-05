
//Desenvolva o código para a Remoção no final da lista duplamente encadeada.
    //considere NÃO EXISTE a tail


#include <stdio.h>
#include <stdlib.h>

typedef struct Node{

    int data;
    struct Node *next;
    struct Node *prev;
}Node;

void removerFinal(Node **head, Node **tail) {
    if (*tail != NULL) {
        Node *aux = *tail;

        if (aux->prev == NULL) {
            *head = NULL;
            *tail = NULL;
        } else {
            aux->prev->next = NULL;
            *tail = aux->prev;
        }

        free(aux);
    } else {
        printf("\nNão há nada para remover\n");
    }
}