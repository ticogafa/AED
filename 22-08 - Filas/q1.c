#include <stdio.h>
#include <stdlib.h>

/*

Descrição:

Fila de banco é sempre uma dor de cabeça. No Banco do Brasilo, existem apenas dois caixas para 
atender as pessoas. Porém, toda hora do almoço é um problema, pois existem duas filas de pessoas e 
um dos funcionários precisa ir comer. Então, as duas filas precisam ser integradas. Sempre dá confusão. 
Para minimizar o problema, o gerente do banco, muito sovina, ao invés de contratar mais um funcionário, 
propôs a seguinte solução. As pessoas da fila do funcionário que foi almoçar devem ser intercaladas com as 
pessoas da fila do funcionário que ficou trabalhando, a partir da segunda posição. E haja confusão!

Entrada: 

Consiste dos inteiros n, m e k (0<=n <=10000, 0<=m <=10000, 1<=k<=2) correspondendo, 
respectivamente, a quantidade de pessoas que existem em cada fila e qual foi à fila que o funcionário 
foi almoçar, sendo k=1 para a primeira fila e k=2 para a segunda fila. Seguidos de n inteiros representando
as pessoas da primeira file e m inteiros representando as pessoas da segunda fila. Os inteiros nunca se repetem.

Saída:

Consiste em uma sequência de inteiros, um em cada linha representando as pessoas da nova fila.

*/


typedef struct Node{

    int pessoa;
    struct Node *next;
} Node;

void inserir(Node **head, Node **tail, int pessoa) {
    Node *novo = (Node*)malloc(sizeof(Node));
    if (novo == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    novo->pessoa = pessoa;
    novo->next = NULL;

    if (*head == NULL) {
        *head = novo;
        *tail = novo;
    } else {
        (*tail)->next = novo;
        *tail = novo;
    }
}

void imprimir(Node *head){
    while(head != NULL){
        printf("%d\n", head->pessoa);
        head = head->next;
    }
}

void liberar(Node **head){
    while(*head != NULL){
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

void alternar(Node *head1, Node *head2, Node *tail1, Node *tail2, int ordem){

    switch(ordem){


        case 2:

            while(head1 != NULL && head2 != NULL){

                printf("%d\n", head1->pessoa);
                printf("%d\n", head2->pessoa);

                head1 = head1->next;
                head2 = head2->next;

            }

            while(head1 != NULL){

                printf("%d\n", head1->pessoa);
                head1 = head1->next;

            }

            while(head2 != NULL){

                printf("%d\n", head2->pessoa);
                head2 = head2->next;

            }

            break;

        case 1:

            while(head1 != NULL && head2 != NULL){

                printf("%d\n", head2->pessoa);
                printf("%d\n", head1->pessoa);

                head1 = head1->next;
                head2 = head2->next;

            }

            while(head1 != NULL){

                printf("%d\n", head1->pessoa);
                head1 = head1->next;

            }

            while(head2 != NULL){

                printf("%d\n", head2->pessoa);
                head2 = head2->next;

            }

            break;

        default: 

            printf("Fila inválida!\n");
    }

}

int main(){

    Node *head1 = NULL;
    Node *tail1 = NULL;
    Node *head2 = NULL;
    Node *tail2 = NULL;

    int n, m, k;
    int pessoa1, pessoa2;

    scanf("%d %d %d", &n, &m, &k);

    for(int i = 0; i<n; i++){

        scanf("%d", &pessoa1);
        inserir(&head1, &tail1, pessoa1);

    }

    for(int i = 0; i<m; i++){

        scanf("%d", &pessoa2);
        inserir(&head2, &tail2, pessoa2);

    }

    alternar(head1, head2, tail1, tail2, k);

    liberar(&head1);
    liberar(&head2);

    return 0;

}