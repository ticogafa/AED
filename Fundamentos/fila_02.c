#include <stdio.h>
#include <stdlib.h>

typedef struct Node {

	int data;
	struct Node *next;
	struct Node *prev;

}Node;

void imprimir(Node **head);
void inserir(Node **head, int n);
void liberar(Node **head);
void remover(Node **head);


int main(){


	Node *head = NULL;
	int n;

	for(int i = 0; i < 10; i++){

		scanf("%d", &n);
		inserir(&head, n);

	}
	remover(&head);
	imprimir(&head);
	liberar(&head);
	return 0;
}

void remover(Node **head){

	if(*head!=NULL){

		Node *temp = *head;
		*head = (*head)->next;
		free(temp);


	}

    
}

void imprimir(Node **head){

	if(*head!=NULL){

		Node *aux = *head;
		
		while(aux!=NULL){

			printf("%d -> ", aux->data);
			aux = aux->next;
		}

        printf("NULL\n");
	
	}

}

void inserir(Node **head, int n) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    newNode->data = n;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*head != NULL) {
        Node *aux = *head;
        while (aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = newNode;
        newNode->prev = aux;
    } else {
        *head = newNode;
    }
}

void liberar(Node **head){

	while(*head!=NULL){

		Node *temp = *head;
		*head = (*head)->next;
		free(temp);
	}

	printf("\nMemória liberada com sucesso!\n");
}
