#include <stdio.h>
#include <stdlib.h>

#define LEN 10

typedef struct Node {

	int data;
	struct Node *next;

}Node;

void enfileirar(Node **head, int n);
void imprimir(Node **head);
void remover(Node **head);
void liberar(Node **head);

int main(){

	Node *head = NULL;
	
	for(int i = 0; i < LEN; i++){
		int n;
		scanf("%d", &n);
		enfileirar(&head, n);

	}

	printf("Fila antes da remoção: \n");
	imprimir(&head);
	remover(&head);

	printf("Fila pós-remoção: \n");
	imprimir(&head);
	liberar(&head);

	return 0;
}

void enfileirar(Node **head, int n){

	Node *newNode = (Node*)malloc(sizeof(Node));
	
	if(newNode ==NULL) return;

	newNode->data = n;

	if(*head == NULL){

		*head = newNode;

	}else{
	
		Node *aux = *head;

		while(aux->next != NULL){
			aux = aux->next;
		}
		aux->next = newNode;
	}
}

void imprimir(Node **head){
	
	Node *aux = *head;

	while(aux!=NULL){
		
		printf("%d -> ", aux->data);
		aux = aux->next;
	}

}

void remover (Node **head){
	
	Node *aux = *head;
	*head = (*head)->next;
	free(aux);


}

void liberar(Node **head){

	while(*head != NULL){
		Node *temp = *head;
		*head = (*head)->next;
		free(temp);
	}

}
