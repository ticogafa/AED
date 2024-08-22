#include <stdio.h>
#include <stdlib.h>

/*
Crie um programa em C para uma clínica médica que precisa  automatizar o controle da ordem de atendimento 
de seus pacientes que deve possuir um menu com as seguintes funcionalidades:

Clínica Médica

=============

(1) Incluir paciente

(2) Realizar atendimento do paciente (remoção do paciente)

(3) Consultar a posição atual do paciente pelo nome

(4) Exibir a quantidade de pacientes já atendidos

(5) Sair

O critério de atendimento é a ordem de chegada. O paciente deve fornecer seu nome. Após isso, o paciente 
é adicionado ao sistema e deve aguardar sua vez. 
*/

typedef struct Node{

    char nome[30];
    struct Node *next;

}Node;

void inserir(Node **head, Node **tail, char nome[30]){

    Node *novo = (Node*)malloc(sizeof(Node));

    strcpy(novo->nome, nome);
    novo ->next = NULL;

    if (*head == NULL){

        *head = *tail = novo;
        return;


    }else{
        (*tail)->next = novo;
    }
    
    *tail = novo;

    
}

void liberar(Node **head){

    while(*head!=NULL){

        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
    }

}

int main(){

    Node *head = NULL;
    Node *tail = NULL;


    return 0;

}