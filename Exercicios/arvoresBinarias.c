#include <stdio.h>
#include <stdlib.h>

typedef struct Node {

	int chave;
	struct Node *esquerda, *direita;
}Node;

void preordem(Node *raiz);
void inordem(Node *raiz);
void posordem(Node *raiz);
void inserir(Node **raiz, int chave);

int main(){
	
	Node *raiz = NULL;

	inserir(&raiz, 6);
	inserir(&raiz, 5);
	inserir(&raiz, 3);
	inserir(&raiz, 7);
	
	printf("Preordem: ");
	preordem(raiz);
	printf("\nInordem: ");
	inordem(raiz);
	printf("\nPosordem: ");
	posordem(raiz);

	inserir(&raiz, 8);
	inserir(&raiz, 4);
	inserir(&raiz, 2);

	printf("\n");
	printf("Preordem: ");
	preordem(raiz);
	printf("\nInordem: ");
	inordem(raiz);
	printf("\nPosordem: ");
	posordem(raiz);
	printf("\n");

	return 0;
}

void posordem(Node *raiz){
	
	if(raiz!=NULL){
		posordem(raiz->esquerda);
		posordem(raiz->direita);
		printf("%d ", raiz->chave);
	}

}

void inordem(Node *raiz){
	
	if(raiz!=NULL){
		inordem(raiz->esquerda);
		printf("%d ", raiz->chave);
		inordem(raiz->direita);
	}

}

void preordem(Node *raiz){
	
	if(raiz!=NULL){
		printf("%d ", raiz->chave);
		preordem(raiz->esquerda);
		preordem(raiz->direita);

	}

}

void inserir(Node **raiz, int chave){

	if(*raiz == NULL){
	
		Node *newNode = (Node*)malloc(sizeof(Node));
		newNode->chave = chave;
		newNode->esquerda = NULL;
		newNode->direita = NULL;
		*raiz = newNode;

	}else{
		
		if(chave < (*raiz)->chave){
			inserir(&(*raiz)->esquerda, chave);
		}else if(chave > (*raiz)->chave){
			inserir(&(*raiz)->direita, chave);
		}

	}
	
}
