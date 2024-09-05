#include <stdio.h>
#include <stdlib.h>

//Desenvolva um função em C para que a Inserção de nós seja realizada no final da lista circular simplesmente encadeada.

typedef struct Node{

	int data;
	struct Node *next;
}Node;

void inserirFinal(Node **head, Node **tail, int n){

	Node *newNode = (Node*)malloc(sizeof(Node));
	if(newNode!=NULL){
		newNode->data = n;

		if(*head==NULL){
			*head = newNode;
			*tail = newNode;
			(*tail)->next = *head;
		}else{
			(*tail)->next = newNode;
			*tail = newNode;
			(*tail)->next = *head;

		}
		
	}

}