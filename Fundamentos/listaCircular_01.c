#include <stdio.h>
#include <stdlib.h>

typedef struct Node {

	int data;
	struct Node *next;
}Node;


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
		
		if(*head = NULL){
			*head = newNode;
			*tail = newNode;
			(*tail)->next = *head;

		}else{
			
		}

	}
}
