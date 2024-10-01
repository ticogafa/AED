//03 - Considere que um programa em C manipula duas 
//Filas (Fila01 e Fila02) e agora é necessário que seja 
//implementada uma nova função que realiza a troca do primeiro 
//elemento entre as filas (o primeiro nó que está na Fila01 vai para a Fila02 E o primeiro nó que estava na Fila02 vai para a Fila01).
//   Protótipo da função: void troca(Node **head1, Node **tail1, 
//Node **head2, Node **tail2);

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {

    int data;
    struct Node *next;

}Node;

void troca(Node **head1, Node **tail1, Node **head2, Node **tail2) {
    if (*head1 == NULL || *head2 == NULL) return;
    
    Node *aux1 = *head1;
    Node *aux2 = *head2;

    *head1 = (*head1)->next;
    *head2 = (*head2)->next;

    aux1->next = *head2;
    aux2->next = *head1;

    *head1 = aux2;
    *head2 = aux1;

    if (*tail1 == aux1) {
        *tail1 = aux2;
    }
    if (*tail2 == aux2) {
        *tail2 = aux1;
    }
}