#include <stdio.h>
#include <stdlib.h>

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