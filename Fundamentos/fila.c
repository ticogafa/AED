#include <stdio.h>

typedef struct {

    int data;
    struct Node *next;

}Node;

void enfileirar(Node **head, Node **tail, int data){

    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if(*head == NULL){
        *head = newNode;
        *tail = newNode;
    }else{
        (*tail)->next = newNode;
    }

    *tail = newNode;    


}

void remover(Node **head, Node **tail){ /*Não tenho certeza se está certo*/

    if(head!=NULL){

        Node *aux = *head;
        *head = (*head)->next;
        free(aux);

        if(*head==NULL){

            *tail=NULL;

        }
    }

}

int main(){

    Node *head = NULL;
    Node *tail = NULL;

    return 0;

}