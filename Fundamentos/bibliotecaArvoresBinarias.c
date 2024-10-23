#include <stdio.h>
#include <stdlib.h>

typedef struct Node {

	int chave;
	struct Node *esq, *dir;

}Node;

void inserir(Node **raiz, int chave);
void inordem(Node *raiz);

int main(){

	Node *raiz = NULL;

	inserir(&raiz, 5);
	inserir(&raiz, 6);
	inserir(&raiz, 3);
	inserir(&raiz, 8);
	inserir(&raiz, 4);
	inserir(&raiz, 2);
	inserir(&raiz, 1);

	inordem(raiz);


	return 0;
}

void inordem(Node *raiz){

	if(raiz!=NULL){
		
		inordem(raiz->esq);
		printf("%d ", raiz->chave);
		inordem(raiz->dir);
	}
	

}

void inserir(Node **raiz, int chave){

	if(*raiz == NULL){
	
		Node *newNode = (Node*)malloc(sizeof(Node));
		if (newNode == NULL) return;
		newNode->chave = chave;
		newNode->esq = NULL;
		newNode->dir = NULL;
		*raiz = newNode;
	}else{

		if(chave < (*raiz)->chave) inserir(&(*raiz)->esq, chave);
		else if(chave > (*raiz)->chave) inserir(&(*raiz)->dir, chave);

	}
	

}
