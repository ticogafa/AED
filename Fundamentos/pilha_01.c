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

void liberar(Node **head){

    while(*head!=NULL){
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
    }

}

void imprimir(Node **head){

    Node *current = *head;
    while(current!=NULL){

        printf("%d\n", current->data);
        current = (current)->next;

    }
    printf("\n");

}

int main(){

    Node *head =NULL;
    int n = 0, cont = 0;

    do{
        scanf("%d", &n);
        if(n>-1){
            inserir(&head, n);
            cont++;
        }
    }while (n>-1);
    

    imprimir(&head);

    printf("Deseja continuar? ");
    scanf("%d", &n);

    for(int i = 0; i<cont; i++){
        remover(&head);
        imprimir(&head);
        printf("\n_______________________\n");
    }

    liberar(&head);
    return 0;

}