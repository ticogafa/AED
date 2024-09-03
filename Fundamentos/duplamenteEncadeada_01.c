#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

void inserirInicio(Node **head, int n);
void liberar(Node **head);
void imprimir(Node **head);
void imprimiInvertido(Node **head);
void remover(Node **head);
void removerFinal(Node **head);
void inserirFinal(Node **head, int n);
void inserirFinalTail(Node **head, Node **tail, int n);
void removerFinalTail(Node **head, Node **tail);
void inserirOrdenado(Node **head, int n);
Node* intercarlarListas(Node *head1, Node *head2);

int main(){

    Node *head = NULL;
    int n;

    for(int i = 0; i <5; i++){
        scanf("%d", &n);
        inserirInicio(&head, n);

        scanf("%d", &n);
        inserirFinal(&head, n);
    }

    imprimir(&head);
    imprimiInvertido(&head);
    remover(&head);
    removerFinal(&head);
    imprimir(&head);
    imprimiInvertido(&head);
    liberar(&head);

    return 0;

}

Node* intercalarListas(Node *head1, Node *head2) {
    Node *headResult = NULL;
    Node *tailResult = NULL;
    Node *aux1 = head1;
    Node *aux2 = head2;

    while (aux1 != NULL || aux2 != NULL) {
        if (aux1 != NULL) {
            Node *newNode = (Node*)malloc(sizeof(Node));
            newNode->data = aux1->data;
            newNode->next = NULL;
            newNode->prev = tailResult;

            if (tailResult == NULL) {
                headResult = newNode;
            } else {
                tailResult->next = newNode;
            }
            tailResult = newNode;
            aux1 = aux1->next;
        }

        if (aux2 != NULL) {
            Node *newNode = (Node*)malloc(sizeof(Node));
            newNode->data = aux2->data;
            newNode->next = NULL;
            newNode->prev = tailResult;

            if (tailResult == NULL) {
                headResult = newNode;
            } else {
                tailResult->next = newNode;
            }
            tailResult = newNode;
            aux2 = aux2->next;
        }
    }

    return headResult;
}

void inserirInicio(Node **head, int n){

    Node *newNode = (Node*)malloc(sizeof(Node));

    if(newNode){
        newNode->data = n;
        newNode->prev = NULL;
        newNode->next = *head;

        if(*head!=NULL){
            (*head)->prev = newNode;

        }
        *head = newNode;
    }
    
}

void inserirOrdenado(Node **head, int n) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = n;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *aux = *head;
        Node *prev = NULL;

        while (aux != NULL && aux->data < n) {
            prev = aux;
            aux = aux->next;
        }

        if (prev == NULL) {
            newNode->next = *head;
            (*head)->prev = newNode;
            *head = newNode;
        } else if (aux == NULL) {
            prev->next = newNode;
            newNode->prev = prev;
        } else {
            newNode->next = aux;
            newNode->prev = prev;
            prev->next = newNode;
            aux->prev = newNode;
        }
    }
}

void liberar(Node **head){

    while(*head!=NULL){

        Node *temp = *head;
        *head = (*head)->next;
        free(temp);

    }
}

void imprimir(Node **head) {
    Node *current = *head;
    while (current != NULL) {
        printf("%d ", current->data); 
        current = current->next; 
    }
    printf("\n"); 
}

void imprimiInvertido(Node **head) {
    Node *current = *head;

    while(current->next!=NULL){
        current = current->next;
    }

    while (current != NULL) {
        printf("%d ", current->data); 
        current = current->prev; 
    }
    printf("\n"); 
}

void remover(Node **head){

    if(*head!=NULL){

        Node *aux = *head;

        *head = (*head)->next;
        free(aux);
        if(*head!=NULL){
            (*head)->prev = NULL;
        }

    }else{
        printf("\nNão há nada para remover\n");
    }

}

void removerFinal(Node **head) {
    if (*head != NULL) {
        Node *aux = *head;

        while (aux->next != NULL) {
            aux = aux->next;
        }

        if (aux->prev == NULL) {
            *head = NULL;
        } else {
            aux->prev->next = NULL;
        }

        free(aux);
    } else {
        printf("\nNão há nada para remover\n");
    }
}

void inserirFinal(Node **head, int n) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode) {
        newNode->data = n;
        newNode->next = NULL;

        if (*head == NULL) {
            newNode->prev = NULL;
            *head = newNode;
        } else {
            Node *aux = *head;
            while (aux->next != NULL) {
                aux = aux->next;
            }
            aux->next = newNode;
            newNode->prev = aux;
        }
    } else {
        printf("Erro ao alocar memória\n");
    }
}

void inserirFinalTail(Node **head, Node **tail, int n) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode) {
        newNode->data = n;
        newNode->next = NULL;
        newNode->prev = *tail;

        if (*tail) {
            (*tail)->next = newNode;
        } else {
            *head = newNode;
        }

        *tail = newNode;
    } else {
        printf("Erro ao alocar memória\n");
    }
}

void removerFinalTail(Node **head, Node **tail) {
    if (*tail != NULL) {
        Node *aux = *tail;

        if (aux->prev == NULL) {
            *head = NULL;
            *tail = NULL;
        } else {
            aux->prev->next = NULL;
            *tail = aux->prev;
        }

        free(aux);
    } else {
        printf("\nNão há nada para remover\n");
    }
}
