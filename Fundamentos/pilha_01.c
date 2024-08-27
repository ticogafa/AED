#include <stdio.h>
#include <stdlib.h>

typedef struct Node{

    int data;
    struct Node *next;

}Node;

void inserir(Node **head, int data){

    Node *novo = (Node*)malloc(sizeof(Node));

    if(novo!=NULL){
        novo->data = data;
        novo->next = *head;
        *head = novo;
    }

    

}

void remover(Node **head){

    if(*head!=NULL){

        Node *aux = *head;
        *head = (*head)->next;
        free(aux);

    }

}

int main(){

    Node *head =NULL;

    return 0;

}