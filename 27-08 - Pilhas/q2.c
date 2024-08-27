#include <stdio.h>
#include <stdlib.h>

typedef struct Node{

    int n;
    struct Node *next;
}Node;

void enfileirar(Node **head, Node **tail, int n){

    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->n = n;
    newNode->next = NULL;

    if(*head==NULL){
        *head = newNode;
        *tail = newNode;

    }else{
        (*tail)->next = newNode;
        *tail = newNode;
    }

}

void concatenar(Node *head1, Node *head2, Node **headP) {
    Node *current;
    current = head1;

    while (current != NULL) {
        empilhar(headP, current->n);
        current = current->next;
    }

    current = head2;

    while (current != NULL) {
        empilhar(headP, current->n);
        current = current->next;
    }
}

void empilhar(Node **headP, int n) {
    Node *novo = (Node*)malloc(sizeof(Node));
    if (novo != NULL) {
        novo->n = n;
        novo->next = *headP;
        *headP = novo;
    }
}

void imprimir(Node **head){

    Node *current = *head;
    while(current!=NULL){

        printf("%d\n", current->n);
        current = (current)->next;

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

    Node *head1 = NULL, *tail1 = NULL, *head2 = NULL, *tail2 = NULL, *headP = NULL;

    printf("Insira os números da Fila 1: \n");

    int n;

    for (int i = 0; i < 10; i ++){

        scanf("%d", &n);
        enfileirar(&head1, &tail1, n);
    }

    printf("Insira os números da Fila 2: \n");

    for(int i = 0; i < 10; i++){

        scanf("%d", &n);
        enfileirar(&head2, &tail2, n);
    }

    concatenar(head1, head2, &headP);

    printf("\nFila 1:\n");
    imprimir(&head1);
    printf("\nFila 2: \n");
    imprimir(&head2);
    printf("\nPilha: \n");
    imprimir(&headP);
    liberar(&head1);
    liberar(&head2);
    liberar(&headP);
    return 0;

}