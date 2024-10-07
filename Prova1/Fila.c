//1. Fila
//Um programa em C manipula uma Fila que armazena números inteiros. Atualmente, ele permite 
//a inserção e remoção de elementos. Agora, você deve incluir uma função que verifique se todos
// os números armazenados na Fila são pares. Caso todos sejam pares, exiba a mensagem “Todos 
//os números são pares :)”, caso contrário, exiba “Existem números ímpares :(".

//Protótipo da função: void verificar_pares(Node *head, Node *tail);

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{

    int data;
    struct Node *next;

}Node;

void inserir(Node **head, Node **tail, int n);
void remover(Node **head);
void verificar_pares(Node *head, Node *tail);

int main(){

    Node *head = NULL;
    Node *tail = NULL;



    return 0;

}

void inserir(Node **head, Node **tail, int n){

    Node *newNode = (Node*)malloc(sizeof(Node));

    if(newNode == NULL) return;

    newNode->data = n;

    if(*head == NULL){
        *head = newNode;
        *tail = newNode;
    }else{
        (*tail)->next = newNode;
        *tail = (*tail)->next;
    }

}

void remover(Node **head){
    
    if(*head!=NULL){
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    
}

void verificar_pares(Node *head, Node *tail){

    Node *aux = head;

    

}