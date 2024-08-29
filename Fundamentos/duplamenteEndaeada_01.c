#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

void inserirInicio(Node **head, int n);
void liberar(Node **head);
void imprimir(Node **head);
void imprimiInvertido(Node **head);


int main(){

    Node *head = NULL;
    int n;

    for(int i = 0; i <2; i++){
        scanf("%d", &n);
        inserirInicio(&head, n);
    }

    imprimir(&head);
    imprimiInvertido(&head);
    liberar(&head);

    return 0;

}

void inserirInicio(Node **head, int n){

    Node *newNode = (Node*)malloc(sizeof(Node));

    if(newNode){
        newNode->data = n;
        newNode->prev = NULL;
        newNode->next = *head;

        if(*head!=NULL){
            (*head)->prev = newNode;

        }
        *head = newNode;
    }
    
}

void liberar(Node **head){

    while(*head!=NULL){

        Node *temp = *head;
        *head = (*head)->next;
        free(temp);

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

void imprimiInvertido(Node **head) {
    Node *current = *head;

    while(current->next!=NULL){
        current = current->next;
    }

    while (current != NULL) {
        printf("%d ", current->data); 
        current = current->prev; 
    }
    printf("\n"); 
}