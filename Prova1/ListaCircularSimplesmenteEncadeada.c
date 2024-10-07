//4. Lista Circular Simplesmente Encadeada
//Em um programa que manipula uma lista circular simplesmente encadeada de números inteiros, 
//adicione uma função que verifique se os números armazenados estão em ordem crescente. Se todos 
//os elementos estiverem em ordem, exiba: “Lista em ordem crescente :)”, caso contrário, exiba “A lista não está em ordem :(".

//Protótipo da função: void verificar_ordenacao(Node *head, Node *tail);
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {

    int data;
    struct Node *next;

}Node;

void inserir(Node **head, Node **tail, int n);
void liberar(Node **head);
void verificar_ordenacao(Node *head, Node *tail);

int main(){

    Node *head = NULL, *tail = NULL;
    int n;

    for(int i = 0; i < 10; i++){
        scanf("%d", &n);
        inserir(&head, &tail, n);
    }

    verificar_ordenacao(head, tail);
    liberar(&head);
    return 0;
}

void verificar_ordenacao(Node *head, Node *tail){

    if (head == NULL || head == tail) {
        printf("\nLista em ordem crescente :)\n");
        return;
    }

    Node *aux = head;

    do{

        if(aux->data > aux->next->data){
            printf("\nA lista não está em ordem :(\n");
            return;
        }
        aux = aux->next;

    }while(aux->next != tail->next);

    printf("\nLista em ordem crescente :)\n");
    
}

void inserir(Node **head, Node **tail, int n){

    Node *newNode = (Node*)malloc(sizeof(Node));

    if(newNode == NULL) return;

    newNode->data = n;

    if(*head == NULL){
        *head = newNode;
    }else{
        (*tail)->next = newNode;
    }
    *tail = newNode;
    newNode->next = *head;
}

void liberar(Node **head){

   if(*head == NULL) return;

   Node *aux = *head;
   Node *nextNode;

   do{

    nextNode = aux->next;
    free(aux);
    aux = nextNode;

   }while(aux!=*head);

    *head = NULL;
}