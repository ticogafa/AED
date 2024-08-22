#include <stdio.h>
#include <stdlib.h>

typedef struct Node{

    char nome[30];
    struct Node *next;

}Node;

void inserir(Node **head, Node **tail, char nome[30]){

    Node *novo = (Node*)malloc(sizeof(Node));

    strcpy(novo->nome, nome);
    novo ->next = NULL;

    if (*head == NULL){

        *head = *tail = novo;
        return;


    }else{
        (*tail)->next = novo;
    }
    
    *tail = novo;

    
}

int main(){

    Node *head = NULL;
    Node *tail = NULL;


    return 0;

}