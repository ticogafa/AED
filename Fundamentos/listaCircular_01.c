#include <stdio.h>
#include <stdlib.h>

typedef struct Node {

	int data;
	struct Node *next;
}Node;

void inserirInicio(Node **head, Node **tail, int n);
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
		inserirInicio(&head, &tail, n);//adiciona 10 números no inicio da lista circular
	}
	
	imprimir(&head, &tail);//imprime a lista após a inserção dos 10 números
	printf("\nTamanho da lista circular: %d\n", tamanhoDaLista(&head, &tail));//imprime o tamanho da lista circular
	removerInicio(&head, &tail);//remove o primeiro elemento da lista
	imprimir(&head, &tail);//imprime a lista após a remoção do primeiro elemento
	printf("\nTamanho da lista circular: %d\n", tamanhoDaLista(&head, &tail)); //imprime o tamanho da lista circular
	removerFinal(&head, &tail);//remove o último elemento da lista
	imprimir(&head, &tail);//imprime a lista após a remoção do último elemento
	printf("\nTamanho da lista circular: %d\n", tamanhoDaLista(&head, &tail));//imprime o tamanho da lista circular
	printf("\nDigite um número para adicionar ao final da lista: \n");//adiciona um número ao final da lista
	scanf("%d", &n);//lê o número digitado
	inserirFinal(&head, &tail, n);//adiciona o número digitado ao final da lista
	imprimir(&head,&tail);//imprime a lista após a inserção do número digitado
	printf("\nTamanho da lista circular: %d\n", tamanhoDaLista(&head, &tail));//imprime o tamanho da lista circular
	liberar(&head, &tail);//libera a lista
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

void inserirInicio(Node **head, Node **tail, int n){

	Node *newNode = (Node*)malloc(sizeof(Node));

	if(newNode!=NULL){
		newNode->data = n;

		if(*head == NULL){
			*head = newNode;
			*tail = newNode;
			(*tail)->next = *head;
		}else{
			newNode->next = *head;
			*head = newNode;
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
