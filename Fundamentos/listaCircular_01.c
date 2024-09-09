#include <stdio.h>
#include <stdlib.h>

typedef struct Node {

	int data;
	struct Node *next;
}Node;

void inserir(Node **head, Node **tail, int n);
void imprimir(Node **head, Node **tail);
void liberar(Node **head, Node **tail);
void removerInicio(Node **head, Node **tail);
int tamanhoDaLista(Node **head, Node **tail);
void removerFinal(Node **head, Node **tail);
void inserirFinal(Node **head, Node **tail, int n);

int main(){

	Node *head = NULL;
	Node *tail = NULL;
	int n;

	for(int i = 0; i < 10; i ++){

		scanf("%d", &n);
		inserir(&head, &tail, n);
	}
	
	imprimir(&head, &tail);
	printf("\nTamanho da lista circular: %d\n", tamanhoDaLista(&head, &tail));
	removerInicio(&head, &tail);
	imprimir(&head, &tail);
	printf("\nTamanho da lista circular: %d\n", tamanhoDaLista(&head, &tail)); 
	removerFinal(&head, &tail);
	imprimir(&head, &tail);
	printf("\nTamanho da lista circular: %d\n", tamanhoDaLista(&head, &tail));
	printf("\nDigite um número para adicionar ao final da lista: \n");
	scanf("%d", &n);
	inserirFinal(&head, &tail, n);
	imprimir(&head,&tail);
	printf("\nTamanho da lista circular: %d\n", tamanhoDaLista(&head, &tail));
	liberar(&head, &tail);
	return 0;

}

void inserirFinal(Node **head, Node **tail, int n){

	Node *newNode = (Node*)malloc(sizeof(Node));

	if(newNode!= NULL){
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

void removerFinal(Node **head, Node **tail){
	
	if(*head!=NULL){

			Node *temp = *tail;
			Node *aux = *head;
		if(*head==*tail){

			*head = NULL;
			*tail = NULL;
		}else{

			while(aux->next!=*tail){
				aux = aux->next;
			}
			*tail = aux;
			(*tail)->next = *head;

		}
			
		free(temp);
		printf("\nÚltimo elemento deletado com sucesso!\n");
	}

}

int tamanhoDaLista(Node **head, Node **tail){
	int cont = 0;
	if(*head!=NULL){
		Node *temp = *head;
		do{
			cont++;
			temp = temp->next;
		}while(temp!=(*tail)->next);
	}
return cont;
}

void removerInicio(Node **head, Node **tail){

	if(*head!=NULL){
		
		Node *temp = *head;
		if(*head==*tail){

			*head = NULL;
			*tail = NULL;
		}else{
			*head = (*head)->next;
			(*tail)->next = *head;
		}
		free(temp);
		printf("Primeiro elemento removido com sucesso!");
	
	}

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
	printf("\n");

	Node *aux = *head;
	do{
		printf("%d -> ", aux->data);
		aux = aux->next;
	}while(aux!=(*tail)->next);
	printf("\n");
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
