//5. Lista Circular Duplamente Encadeada
//Considere um programa que utiliza uma lista circular duplamente encadeada 
//para armazenar números inteiros. Crie uma nova funcionalidade que identifique 
//o segundo maior valor da lista. Se houver menos que 2 elementos, exiba: "Tamanho da lista é insuficiente :(".
//Protótipo da função: int segundo_maior(Node *head, Node *tail);

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{

    int data;
    struct Node *next, *prev;

}Node;

void inserir(Node **head, Node **tail, int n);
void liberar(Node **head);
int segundo_maior(Node *head, Node *tail);

int main(){

    Node *head = NULL, *tail = NULL;
    int n;

    for(int i = 0; i < 10; i++){

        scanf("%d", &n);
        inserir(&head, &tail, n);
    }

    printf("Segundo maior número da lista: %d\n", segundo_maior(head, tail));

    liberar(&head);
    return 0;
}

int segundo_maior(Node *head, Node *tail) {
    if (head == NULL || head == tail) {
        printf("\nTamanho da lista é insuficiente :(\n");
        return -1;
    }

    Node *aux = head;
    int maior = aux->data;
    int segundoMaior = aux->data;

    do {
        if (aux->data > maior) {
            maior = aux->data;
        }
        aux = aux->next;
    } while (aux != head);

    aux = head;
    int cont = 0;
    do {
        if (aux->data > segundoMaior && aux->data < maior) {
            segundoMaior = aux->data;
        }
        aux = aux->next;
        cont++;
    } while (aux != head);

    if (cont<2) {
        printf("\nTamanho da lista é insuficiente :(\n");
        return -1;
    }

    return segundoMaior;
}

void inserir(Node **head, Node **tail, int n){

    Node *newNode = (Node*)malloc(sizeof(Node));

    if(newNode == NULL) return;

    newNode->data = n;

    if(*head == NULL){
        *head = newNode;
        *tail = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;

    }else{
        newNode->prev = *tail;
        newNode->next = *head;
        (*tail)->next = newNode;
        (*head)->prev = newNode;
        *tail = newNode;
        
    }

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