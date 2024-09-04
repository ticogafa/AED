#include <stdio.h>
#include <stdlib.h>

typedef struct Node {

	int data;
	struct Node *next;
	struct Node *prev;

}Node;


void inserir(Node **head, int n);
void liberar(Node **head);

int main(){


	Node *head = NULL;
	inserir(&head, 10);

	liberar(&head);
	return 0;
}

void inserir(Node **head, int n){

	Node *newNode = (Node*)malloc(sizeof(Node));
	Node *aux = *head;
	newNode->data = n;

	if(*head!=NULL){

		while(aux->next!=NULL){

			aux = aux->next;	
		}

		newNode = aux->next;
		aux = newNode->prev;

	}else{

		*head = newNode;
	}

}

void liberar(Node **head){

	while(*head!=NULL){

		Node *temp = *head;
		*head = (*head)->next;
		free(temp);
	}

	printf("Memória liberada com sucesso!");
}
