#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

void inserir(Node **head, int n);


int main(){

    Node *head = NULL;

    

    return 0;

}

void inserir(Node **head, int n){

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
