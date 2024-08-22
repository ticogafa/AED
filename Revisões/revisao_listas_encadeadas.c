#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void inserir(Node **head, int n){
    Node *new_node = (Node *)malloc(sizeof(Node));

    if(new_node != NULL){
        new_node->data = n;
        new_node->next = *head;
        *head = new_node;
    } else {
        printf("Erro ao alocar memória\n");
    }
}

void imprimir(Node *head){
    while(head!=NULL){
        printf("%d\n", head->data);
        head = head->next;
    }

}

void liberar(Node **head){
    while(*head != NULL){
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int cont_listas(Node *head){
    int cont = 0;
    while(head!=NULL){
        cont++;
        head = head->next;
    }
return cont;
}

void remover(Node **head, int n){
    Node *current = *head;
    Node *previous = NULL;

    while(current != NULL && current->data != n){
        previous = current;
        current = current->next;
    }

    if(current != NULL){
        if(previous == NULL){
            *head = current->next;
        } else {
            previous->next = current->next;
        }
        free(current);
    }
}

void remover_ultimo(Node **head){
    Node *current = *head;
    Node *previous = NULL;

    while(current->next != NULL){
        previous = current;
        current = current->next;
    }

    if(current != NULL){
        if(previous == NULL){
            *head = current->next;
        } else {
            previous->next = current->next;
        }
        free(current);
    }
}

int main(){

    Node *head = NULL;
    inserir(&head, 10);
    inserir(&head, 20);
    inserir(&head, 30);
    inserir(&head, 40);
    inserir(&head, 40);
    remover(&head, 40);
    remover_ultimo(&head);
    Node *current = head;
    imprimir(current);
    printf("Quantidade de elementos na lista: %d\n", cont_listas(current));
    liberar(&head);

    return 0;

}