#include <stdio.h>
#include <stdlib.h>

typedef struct Node {

    int data;
    struct Node *next;
    struct Node *prev;
}Node;

void inserirInicio(Node **head, Node **tail, int n);
void inserirFinal(Node **head, Node **tail, int n);
void removerInicio(Node **head, Node **tail);
void removerFinal(Node **head, Node **tail);
void removerEscolha(Node **head, Node **tail, int n);
void imprimir(Node **head, Node **tail);
void liberar(Node **head, Node **tail);
int tamanhoDaLista(Node **head, Node **tail);

int main(){

    Node *head = NULL;
    Node *tail = NULL;

    inserirInicio(&head, &tail, 10);
    inserirInicio(&head, &tail, 20);
    inserirInicio(&head, &tail, 30);
    inserirInicio(&head, &tail, 40);
    inserirInicio(&head, &tail, 50);
    inserirInicio(&head, &tail, 60);
    inserirInicio(&head, &tail, 70);


    imprimir(&head, &tail);
    printf("Tamanho da lista: %d\n", tamanhoDaLista(&head, &tail));

    inserirFinal(&head, &tail, 80);
    inserirFinal(&head, &tail, 90);
    inserirFinal(&head, &tail, 100);

    imprimir(&head, &tail);
    printf("Tamanho da lista: %d\n", tamanhoDaLista(&head, &tail));

    removerFinal(&head, &tail);
    removerFinal(&head, &tail);

    imprimir(&head, &tail);
    printf("Tamanho da lista: %d\n", tamanhoDaLista(&head, &tail));


    removerInicio(&head, &tail);
    removerInicio(&head, &tail);
    removerInicio(&head, &tail);
    removerInicio(&head, &tail);
    removerInicio(&head, &tail);
    removerInicio(&head, &tail);
    removerInicio(&head, &tail);

    imprimir(&head, &tail);

    printf("Tamanho da lista: %d\n", tamanhoDaLista(&head, &tail));

    liberar(&head, &tail);//libera a lista


    return 0;

}

void inserirFinal(Node **head, Node **tail, int n){

    Node *newNode = (Node*)malloc(sizeof(Node));

    if(newNode!= NULL){
        newNode->data = n;

        if(*head == NULL){
            *head = newNode;
            *tail = newNode;
            (*tail)->next = *head;
            (*head)->prev = *tail;
        }else{
            (*tail)->next = newNode;
            newNode->prev = *tail;
            *tail = newNode;
            (*tail)->next = *head;
            (*head)->prev = *tail;
        }

    }

}

void removerFinal(Node **head, Node **tail){
    
    if(*head==NULL) return;

    Node *temp = *tail;
    Node *aux = *head;
    if(*head==*tail){

        *head = NULL;
        *tail = NULL;
    }else{

        while(aux->next!=*tail){
            aux = aux->next;
        }
        *tail = aux;
        (*tail)->next = *head;
        (*head)->prev = *tail;

    }
            
        free(temp);
        printf("\nÚltimo elemento deletado com sucesso!\n");
    

}

int tamanhoDaLista(Node **head, Node **tail){
    int cont = 0;
    if(*head!=NULL){
        Node *temp = *head;
        do{
            cont++;
            temp = temp->next;
        }while(temp!=(*tail)->next);
    }

return cont;
}

void removerInicio(Node **head, Node **tail){

    if(*head!=NULL){
        
        Node *temp = *head;
        if(*head==*tail){

            *head = NULL;
            *tail = NULL;
        }else{
            *head = (*head)->next;
            (*head)->prev = *tail;
            (*tail)->next = *head;
        }
        free(temp);
        printf("\nPrimeiro elemento removido com sucesso!\n");
    
    }

}

void inserirInicio(Node **head, Node **tail, int n){

    Node *newNode = (Node*)malloc(sizeof(Node));

    if(newNode!=NULL){
        newNode->data = n;

        if(*head == NULL){
            *head = newNode;
            *tail = newNode;
            (*tail)->next = *head;
            (*head)->prev = *tail;
        }else{
            newNode->next = *head;
            (*head)->prev = newNode;
            *head = newNode;
            (*tail)->next = *head;
            (*head)->prev = *tail;
        }
    }
}

void imprimir(Node **head, Node **tail){

    if(*head == NULL) return;    
    printf("\n");

    Node *aux = *head;
    do{
        printf("%d -> ", aux->data);
        aux = aux->next;
    }while(aux!=(*tail)->next);
    printf("\n");
}

void liberar(Node **head, Node **tail){
    
    if(*head == NULL) return;

    Node *aux = *head;
    do{
        Node *temp = aux;
        aux = aux->next;
        free(temp);
    }while(aux!=(*tail)->next);

    *head = NULL;
    *tail = NULL;
    printf("Lista liberada com sucesso!\n");
}

void removerEscolha(Node **head, Node **tail, int n){

    if(*head!=NULL){
        Node *aux = *head;
        do{
            if(aux->data == n){
                if(aux==*head){
                    *head = aux->next;
                    (*head)->prev = *tail;
                    (*tail)->next = *head;
                }else if(aux==*tail){
                    *tail = aux->prev;
                    (*tail)->next = *head;
                    (*head)->prev = *tail;
                }else{
                    aux->prev->next = aux->next;
                    aux->next->prev = aux->prev;
                }
                free(aux);
                printf("\nElemento removido com sucesso!\n");
                return;
            }
            aux = aux->next;
        }while(aux!=(*tail)->next);
    }else{
        printf("\nLista vazia!\n");
    }

}