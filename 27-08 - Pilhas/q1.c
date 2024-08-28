#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno {  
    char nome[30]; 

    struct Aluno *next; 
    
    }  Aluno ;

void inserir(Aluno **head, char nome[30]){

    Aluno *novo = (Aluno*)malloc(sizeof(Aluno));

    if(novo!=NULL){
        strcpy(novo->nome, nome);
        novo->next = *head;
        *head = novo;
    }

}

void imprimirPares(Aluno **head){

    if(*head == NULL){
        printf("A lista está vazia\n");
        return;
    }
    Aluno *current = *head;
    int cont = 0;

    while (current!=NULL){
        cont++;
        current = current->next;
    }
    
    Aluno *atual = *head;

    if (cont % 2 == 0){
        while(atual!=NULL){

        if(cont % 2 == 0){
            printf("%s\n", atual->nome);
        }
        atual = atual->next;
        cont++;
    }
    }else if (cont % 2 != 0){
        while(atual!=NULL){

        if(cont % 2 == 0){
            printf("%s\n", atual->nome);
        }
        atual = atual->next;
        cont++;
    }
    }
    

    while(current!=NULL){

        if(cont % 2 == 0){
            printf("%s", current->nome);
        }
        current = current->next;
    }

}

void imprimirBase(Aluno **head){

    if(*head == NULL){
        printf("Essa lista está vazia\n");
        return;
    }
    Aluno *current = *head;
    while(current->next != NULL){
        current = current->next;
    }
    printf("%s\n", current->nome);

}

void liberar(Aluno **head){

    while(*head!=NULL){
        Aluno *temp = *head;
        *head = (*head)->next;
        free(temp);
    }

}

int main(){

    Aluno *head = NULL;

    char nome[30];
    int escolha = 0;

    while(escolha!=-1){
        printf("Digite uma opção:\n1 - Inserir nome\n2 - Imprimir base\n3 - Imprimir todos os nós nas posições pares\nDigite -1 para finalizar\n");
        scanf("%d", &escolha);
 
        switch (escolha){
        case 1:
            scanf("%s", nome);
            inserir(&head, nome);
            break;

        case 2:

            imprimirBase(&head);
            break;

        case 3:

            imprimirPares(&head);
            break;
        
        default:
            break;
        }


    }

    liberar(&head);
    return 0;

}