//2136 - Amigos do Habay
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    char *nome;
    char *escolha;
    struct Node *next;
    struct Node *prev;
} Node;

void enfileirar(Node **head, char *nome, char *escolha);
void liberar(Node **head);
void ordenar(Node **head);
void imprimir(Node *head, const char *escolha);
void removerDuplicatas(Node **head);


int main(){

    Node *head = NULL;
    char nome[1000], escolha[1000];
    long unsigned int tamanho = 0;
    char maior[1000];
    do {
        scanf("%s", nome);
        if (strcmp(nome, "FIM") == 0) {
            break;
        }
        scanf("%s", escolha);
        if (strcmp(escolha, "YES") == 0) {
            if (strlen(nome) > tamanho) {
                strcpy(maior, nome);
                tamanho = strlen(nome);
            }
        }
        enfileirar(&head, nome, escolha);
    } while (1);

    ordenar(&head);
    removerDuplicatas(&head);
    imprimir(head, "YES");
    imprimir(head, "NO");
    printf("\nAmigo do Habay:\n%s\n", maior);
    liberar(&head);
    return 0;


}

void enfileirar(Node **head, char *nome, char *escolha){
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo == NULL){
        printf("Erro: Falha na alocação de memória\n");
        return;
    }
    novo->nome = strdup(nome);
    novo->escolha = strdup(escolha);
    novo->next = NULL;
    novo->prev = NULL;

    if(*head == NULL){
        *head = novo;
    }else{
        Node *temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = novo;
        novo->prev = temp;
    }
}

void liberar(Node **head){
    Node *temp = *head;
    while(temp != NULL){
        Node *remover = temp;
        temp = temp->next;
        free(remover->nome);
        free(remover->escolha);
        free(remover);
    }
    *head = NULL;
}
void ordenar(Node **head) {
    if (*head == NULL) return;
    Node *i, *j;
    char *tempNome, *tempEscolha;
    for (i = *head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (strcmp(i->nome, j->nome) > 0) {
                tempNome = i->nome;
                tempEscolha = i->escolha;
                i->nome = j->nome;
                i->escolha = j->escolha;
                j->nome = tempNome;
                j->escolha = tempEscolha;
            }
        }
    }
}

void imprimir(Node *head, const char *escolha) {
    Node *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->escolha, escolha) == 0) {
            printf("%s\n", temp->nome);
        }
        temp = temp->next;
    }
}
void removerDuplicatas(Node **head) {
    if (*head == NULL) return;
    Node *current = *head;
    Node *next_next;
    while (current->next != NULL) {
        if (strcmp(current->nome, current->next->nome) == 0) {
            next_next = current->next->next;
            free(current->next->nome);
            free(current->next->escolha);
            free(current->next);
            current->next = next_next;
            if (next_next != NULL) {
                next_next->prev = current;
            }
        } else {
            current = current->next;
        }
    }
}