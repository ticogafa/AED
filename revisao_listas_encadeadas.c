#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void inserir(Node **head, int n){
    Node *new_node = (Node *)malloc(sizeof(Node));

    if(new_node != NULL){
        new_node->data = n;
        new_node->next = *head;
        *head = new_node;
    } else {
        printf("Erro ao alocar memória\n");
    }
}

int main(){

    Node *head = NULL;
    inserir(&head, 10);
    inserir(&head, 20);
    Node *current = head;
    while(current != NULL){
        printf("%d\n", current->data);
        current = current->next;
    }

    while(head != NULL){
        Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;

}