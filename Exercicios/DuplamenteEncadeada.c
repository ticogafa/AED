#include <stdio.h>
#include <stdlib.h>

#define LEN 10

typedef struct Node {

	int data;
	struct Node *next, *prev;

}Node;

void inserirInicio(Node **head, Node **tail, int n);
void liberar(Node **head);
void imprimir(Node **head);
void inserirFinal(Node **head, Node **tail, int n);


int main(){

	Node *head = NULL;
	Node *tail = NULL;

	for(int i = 0; i < LEN; i++){
		int n;
		scanf("%d", &n);
		inserirInicio(&head, &tail, n);
		inserirFinal(&head, &tail, n);
	}

	imprimir(&head);
	printf("\n");
	liberar(&head);

	return 0;
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

}

void inserirInicio(Node **head, Node **tail, int n){
	
	Node *newNode = (Node*)malloc(sizeof(Node));

	if(newNode == NULL) return;

	newNode->data = n;
	newNode->next = NULL;
	newNode->prev = NULL;

	if(*head == NULL){
		*head = newNode;
		*tail = newNode;
	}else{
		
		newNode->next = *head;
		*head = newNode;

	}

}

void inserirFinal(Node **head, Node **tail, int n){
	
	Node *newNode = (Node*)malloc(sizeof(Node));

	if(newNode == NULL) return;

	newNode->data = n;
	newNode->prev = NULL;
	newNode->next = NULL;

	if(*head == NULL){
		
		*head = newNode;
		*tail = newNode;

	}else{
	
		newNode->prev = *tail;
		(*tail)->next = newNode;
		*tail = newNode;

	}

}
