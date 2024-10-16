#include <stdio.h>
#include <stdlib.h>

typedef struct Node {

	int chave;
	struct Node *esquerda, *direita;
}Node;

void preordem(Node *raiz);
void inserir(Node **raiz, int chave);

int main(){
	
	Node *raiz = NULL;

	inserir(&raiz, 6);
	inserir(&raiz, 5);
	inserir(&raiz, 3);
	inserir(&raiz, 7);

	preordem(raiz);

	inserir(&raiz, 8);
	inserir(&raiz, 4);
	inserir(&raiz, 2);

	printf("\n");
	preordem(raiz);

	return 0;
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
