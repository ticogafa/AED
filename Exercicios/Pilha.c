#include <stdio.h>
#include <stdlib.h>

typedef struct Node {

	int data;
	struct Node *next;
}Node;

void inserir(Node **head, int n);
void imprimir(Node **head);
void liberar(Node **head);

int main(){

	Node *head = NULL;

	for(int i = 0; i< 10; i++){


		int n; 
		scanf("%d", &n);
		inserir(&head, n);
	}

	imprimir(&head);
	printf("\n");
	liberar(&head);

	return 0;
}

void inserir(Node **head, int n){
	Node *newNode = (Node*)malloc(sizeof(Node));

	if(newNode==NULL) return;

	newNode->data = n;

	if(*head == NULL){
		*head = newNode;
	}else{
		newNode->next = *head;
		*head = newNode;
	}

}

void imprimir(Node **head){
	Node *aux = *head;
	while(aux!=NULL){
		printf("%d -> ", aux->data);
		aux = aux->next;
	}


}

void liberar(Node **head){
	while(*head!=NULL){
		Node *temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}
