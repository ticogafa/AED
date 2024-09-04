#include <stdio.h>
#include <stdlib.h>


typedef struct Node{

int data;
struct Node *next;

}Node;

void imprimir(Node **head);
void liberar(Node **head);
void empilhar(Node **head, int n);
void remover(Node **head);

int main(){

	int n;
	Node *head = NULL;

	for(int i = 0; i < 10; i++){


		scanf("%d", &n);
		empilhar(&head, n);
	
	}
	
	imprimir(&head);
    remover(&head);
    printf("Removendo o primeiro elemento\n");
    imprimir(&head);
	liberar(&head);

	return 0;

}

void remover(Node **head){

	if(*head!=NULL){
	Node *temp = *head;
	*head = (*head)->next;
	free(temp);
	}else{
		printf("Não há nada para remover\n");

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

	Node *aux = *head;

	while(aux!=NULL){

		printf("%d -> ", aux->data);
		aux = aux->next;

	}
	printf("NULL\n");
}

void empilhar(Node **head, int n){

	Node *newNode = (Node*)malloc(sizeof(Node));
	if(newNode){
		
		newNode->data = n;
		newNode->next = NULL;

	
		
	if(*head!=NULL){
		
		Node *aux = *head;
		*head = newNode;
		newNode->next = aux;

	}else{

		*head = newNode;
	}

	}
}




