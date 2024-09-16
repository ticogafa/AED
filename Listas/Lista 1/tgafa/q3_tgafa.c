#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int pontoCardeal;
    char id[5];
    struct Node* next;
} Node;

Node* enqueue(Node* head, int pontoCardeal, const char* id);
void printQueue(Node* head);
void freeQueue(Node* head);
Node* mergeQueues(Node* oeste, Node* norte, Node* sul, Node* leste);

int main() {
    Node* oeste = NULL;
    Node* norte = NULL;
    Node* sul = NULL;
    Node* leste = NULL;
    int pontoCardeal;
    char id[5];

    while (1) {
        scanf("%d", &pontoCardeal);
        if (pontoCardeal == 0) break;

        scanf("%s", id);
        if (pontoCardeal == -1) {
            oeste = enqueue(oeste, pontoCardeal, id);
        } else if (pontoCardeal == -2) {
            norte = enqueue(norte, pontoCardeal, id);
        } else if (pontoCardeal == -3) {
            sul = enqueue(sul, pontoCardeal, id);
        } else if (pontoCardeal == -4) {
            leste = enqueue(leste, pontoCardeal, id);
        }
    }

    Node* head = mergeQueues(oeste, norte, sul, leste);
    printQueue(head);
    freeQueue(head);
    return 0;
}

Node* enqueue(Node* head, int pontoCardeal, const char* id) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erro: Falha na alocação de memória\n");
        return head;
    }
    newNode->pontoCardeal = pontoCardeal;
    strcpy(newNode->id, id);
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

void printQueue(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%s", temp->id);
        if (temp->next != NULL) {
            printf(" ");
        }
        temp = temp->next;
    }
    printf("\n");
}

void freeQueue(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

Node* mergeQueues(Node* oeste, Node* norte, Node* sul, Node* leste) {
    Node* head = NULL;
    Node** tail = &head;

    // Adiciona todos os aviões do Oeste primeiro
    while (oeste != NULL) {
        *tail = oeste;
        tail = &oeste->next;
        oeste = oeste->next;
    }

    // Alterna entre Norte e Sul, e depois adiciona Leste
    while (norte != NULL || sul != NULL || leste != NULL) {
        if (norte != NULL) {
            *tail = norte;
            tail = &norte->next;
            norte = norte->next;
        }
        if (sul != NULL) {
            *tail = sul;
            tail = &sul->next;
            sul = sul->next;
        }
        if (leste != NULL) {
            *tail = leste;
            tail = &leste->next;
            leste = leste->next;
        }
    }

    return head;
}