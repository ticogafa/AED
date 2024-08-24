#include <stdio.h>
#include <stdlib.h>

typedef struct Node{

    int data;
    struct Node *next;

}Node;


void enqueue(Node **head, Node **tail, int data){

    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if(*head==NULL){
        *head = newNode;
        *tail = newNode;

    }else{
        (*tail)->next = newNode;
        *tail = newNode;
    }
    
}


void imprimir(Node **head) {
    Node *current = *head;
    while (current != NULL) {
        printf("%d ", current->data); 
        current = current->next; 
    }
    printf("\n"); 
}


void liberar(Node **head){

    while(*head!=NULL){

        Node *temp = *head;
        *head = (*head)->next;
        free(temp);

    }
}


int main(){

    Node *head = NULL;
    Node *tail = NULL;

    int n;

    for(int i = 0; i<5; i++){

        scanf("%d", &n);
        enqueue(&head, &tail, n);
    }

    liberar(&head);

    return 0;

}