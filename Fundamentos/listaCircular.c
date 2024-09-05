#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;

}Node;

void liberar(Node **head, Node **tail);
void inserir(Node **head, Node **tail, int n);
void imprimir(Node **head, Node **tail);
int tamanho(Node *head, Node *tail);

int main(){

	Node *head = NULL;
	Node *tail = NULL;

	int n;

	for(int i = 0; i<10; i++){
		printf("Digite um número: ");
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

		if(*head==NULL){
		*head = newNode;
		*tail = newNode;
		(*tail)->next = *head;
		}

		newNode->next = *head;
		*head = newNode; 
		(*tail)->next = *head;
	}

}

void imprimir(Node **head, Node **tail){

	if(*head!=NULL){
		Node *aux = *head;

		do{

			printf("%d", aux->data);
			aux = aux->next;

		}while(aux!=(*tail)->next);
	}
}

int tamanho(Node *head, Node *tail){
	int cont = 0;
	
	if(head!=NULL){
		do{
			printf("%d", head->data);
			head = head->next;
			cont++;
		}while(head!=tail->next);
	return cont;

}
}

void liberar(Node **head, Node **tail){

	do{
		Node *temp = *head;
		*head = (*head)->next;
		free(temp);
	}while(*head!=(*tail)->next);

	printf("\nMemória liberada com sucesso!\n");
}