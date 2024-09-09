#include <stdio.h>
#include <stdlib.h>

typedef struct Node {

	int data;
	struct Node *next;
}Node;

void inserir(Node **head, Node **tail, int n);
void imprimir(Node **head, Node **tail);
void liberar(Node **head, Node **tail);

int main(){

	Node *head = NULL;
	Node *tail = NULL;
	int n;


	for(int i = 0; i < 10; i ++){

		scanf("%d", &n);
		inserir(&head, &tail, n);
	}
	
	imprimir(&head, &tail);
	liberar(&head, &tail);
	return 0;

}

void inserir(Node **head, Node **tail, int n){


	Node *newNode = (Node*)malloc(sizeof(Node));

	if(newNode!=NULL){
		
		newNode->data = n;
		
		if(*head == NULL){
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

void imprimir(Node **head, Node **tail){

	if(*head == NULL) return;

	Node *aux = *head;
	do{
		printf("%d -> ", aux->data);
		aux = aux->next;
	}while(aux!=(*tail)->next);

}

void liberar(Node **head, Node **tail){
	
	if(*head == NULL) return;

	Node *aux = *head;
	Node *aux2 = NULL;

	do{
		aux2 = aux->next;
		free(aux);
		aux = aux2;
	}while(aux!=(*tail)->next);

	*head = NULL;
	*tail = NULL;
}