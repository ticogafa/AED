#include <stdio.h>
#include <stdlib.h>



typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

void inserirOrdenado(Node **head, int n);
void liberar(Node **head);
void imprimir(Node **head);

int main(){
	
	Node *head = NULL;
	int n;

	for(int i = 0; i<10; i++){
		scanf("%d", &n);
		inserirOrdenado(&head, n);
		
	}

	imprimir(&head);
	liberar(&head);

	return 0;

}

void liberar(Node **head){

	while(*head!=NULL){
		Node *aux = *head;
		*head = (*head)->next;
		free(aux);
	}

}

void imprimir(Node **head){

	Node *aux = *head;

	printf("NULL <- ");

	while(aux!=NULL){

		printf("%d -> ", aux->data);
		aux = aux->next;
	}
	printf("NULL\n");

}


void inserirOrdenado(Node **head, int n){

	Node *newNode = (Node*)malloc(sizeof(Node));

	newNode->next = NULL;
	newNode->prev = NULL;
	newNode->data = n;

	if(*head == NULL){
		*head = newNode;
	}else{

		Node *aux = *head;
		Node *prev = NULL;
		
		while(aux!=NULL && aux->data < n){

			prev = aux;
			aux = aux->next;
		}
		if(prev == NULL){

			newNode->next = *head;
			(*head)->prev = newNode;
			*head = newNode;
		}else if(aux == NULL){

			prev->next = newNode;
			newNode->prev = prev;

		}else{

			newNode->next = aux;
			newNode->prev = prev;
			prev->next = newNode;
			aux->prev = newNode;

		}
	}
}
