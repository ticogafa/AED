//2. Pilha
//Em um programa que manipula uma pilha de números inteiros, implemente uma função 
//que encontre o menor valor da pilha sem remover os elementos. Se a pilha estiver 
//vazia, a função deve exibir: "Pilha vazia :(".

//Protótipo da função: int menor_valor(Node *top);

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {

    int data;
    struct Node *next;

}Node;

void inserir(Node **head, int n);
int menor_valor(Node *top);
void liberar(Node **head);

int main(){

    Node *head = NULL;
    int n;

    for(int i = 0; i < 10; i++){

        scanf("%d", &n);
        inserir(&head, n);

    }

    printf("Menor valor da pilha: %d\n", menor_valor(head));
    liberar(&head);
    return 0;
}

int menor_valor(Node *top){

    if (top == NULL) {
        printf("Pilha vazia :(\n");
        return -1; 
    }

    Node *aux = top;
    int menor = aux->data;

    while(aux != NULL){
        if(menor > aux->data){
            menor = aux->data;
        }
        aux = aux->next;
    }

    return menor;
}

void inserir(Node **head, int n){

    Node *newNode = (Node*)malloc(sizeof(Node));

    if(newNode==NULL) return;

    newNode->data = n;

    if(*head==NULL){
        *head = newNode;
    }else{
        newNode->next = *head;
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