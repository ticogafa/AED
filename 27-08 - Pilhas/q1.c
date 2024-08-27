#include <stdio.h>
#include <stdlib.h>

typedef struct Aluno {  
    char nome[30]; 

    struct Aluno *next; 
    
    }  Aluno ;

void inserir(Aluno **head, char nome[30]){

    Aluno *novo = (Aluno*)malloc(sizeof(Aluno));

    if(novo!=NULL){
        novo->nome[30] = nome[30];
        novo->next = *head;
        *head = novo;
    }

}

void remover(Aluno **head){

    if(*head!=NULL){

        Aluno *aux = *head;
        *head = (*head)->next;
        free(aux);

    }

}

void liberar(Aluno **head){

    while(*head!=NULL){
        Aluno *temp = *head;
        *head = (*head)->next;
        free(temp);
    }

}

void imprimirBase(Aluno **head){

    Aluno *current = *head;
    while(current!=NULL){
        if(current->next == NULL){
            printf("%d\n", current->nome);
        }
        current = (current)->next;

    }
    printf("\n");

}

int main(){

    Aluno *head = NULL;

    char nome[30];
    int escolha = 0;

    while(escolha!=-1){
        printf("Digite uma opção:\n1 - Inserir número\n2 - Imprimir base\n3 - Imprimir todos os nós pares\n");
        scanf("%d", &escolha);
 
        switch (escolha){
        case 1:
            break;

        case 2:
            break;

        case 3:
            break;
        
        default:
            break;
        }


    }

    




    

    

    

    

    liberar(&head);
    return 0;

}