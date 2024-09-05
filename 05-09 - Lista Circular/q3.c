
//Desenvolva um função em C para que a Remoção de nós seja realizada no final da lista circular simplesmente encadeada.


#include <stdio.h>
#include <stdlib.h>

typedef struct Node{

    int data;
    struct Node *next;
}Node;

void removerFinal(Node **head, Node **tail){
	if(*head!=NULL){
		Node *aux = *head;
		Node *temp = *tail;
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
		printf("\nElemento removido com sucesso!\n");
	}
}