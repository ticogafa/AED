//3. Lista Duplamente Encadeada
//Um programa em C manipula uma lista duplamente encadeada e permite a inserção de números. 
//Implemente uma função que inverta a lista, ou seja, a última posição passa a ser a primeira 
//e assim sucessivamente. Ao final da função, a lista deve estar invertida.

//Protótipo da função: void inverter_lista(Node **head, Node **tail);

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {

    int data;
    struct Node *next;
    struct Node *prev;

}Node;

void inserirInicio(Node **head, Node **tail, int n);
void liberar(Node **head);
void inverter_lista(Node **head, Node **tail);
void imprimir(Node **head);

int main(){

    Node *head = NULL, *tail = NULL;
    int n;

    for(int i = 0; i < 10; i++){
        scanf("%d", &n);
        inserirInicio(&head, &tail, n);
    }
    printf("\n");
    imprimir(&head);
    printf("\n");
    inverter_lista(&head, &tail);
    printf("\nLista invertida: ");
    imprimir(&head);
    printf("\n");
    liberar(&head);
    return 0;
}

void imprimir(Node **head){
    Node *aux = *head;
    while(aux!=NULL){
        printf("%d -> ", aux->data);
        aux = aux->next;
    }
}

void inverter_lista(Node **head, Node **tail){

    Node *auxTail = *tail;
    Node *auxHead = *head;

    while(auxTail->next!=auxHead || auxTail == auxHead){
        int temp;
        temp = auxHead->data;
        auxHead->data = auxTail->data;
        auxTail->data = temp;

        auxHead = auxHead->next;
        auxTail = auxTail->prev;
    }

}

void inserirInicio(Node **head, Node **tail, int n){

    Node *newNode = (Node*)malloc(sizeof(Node));

    if(newNode == NULL) return;

    newNode->data = n;

    if(*head == NULL){
        *head = newNode;
        *tail = newNode;

    }else{

        newNode->next = *head;
        (*head)->prev = newNode;
        *head = (*head)->prev;

    }

}

void liberar(Node **head){

    while(*head!=NULL){

        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}