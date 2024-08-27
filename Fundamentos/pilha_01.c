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


int main(){

    Node *head =NULL;

    return 0;

}