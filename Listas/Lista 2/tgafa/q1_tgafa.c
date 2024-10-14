#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* criarNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void inserirFinal(Node** head, int data) {
    Node* newNode = criarNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

int insertionSort(Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return 0;
    }

    int trocas = 0;
    Node* current = (*head)->next;
    
    while (current != NULL) {
        Node* chave = current;
        Node* j = current->prev;

        while (j != NULL && j->data > chave->data) {
            Node* temp = j->prev;
            if (temp != NULL) temp->next = chave;
            if (chave->next != NULL) chave->next->prev = j;

            j->next = chave->next;
            chave->prev = j->prev;
            j->prev = chave;
            chave->next = j;

            if (j == *head) *head = chave;

            j = chave->prev;
            trocas++;
        }

        current = chave->next;
    }

    return trocas;
}

void imprimir(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void liberar(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int L;
        scanf("%d", &L);

        Node* head = NULL;
        for (int j = 0; j < L; j++) {
            int vagao;
            scanf("%d", &vagao);
            inserirFinal(&head, vagao);
        }

        int trocas = insertionSort(&head);
        printf("Optimal train swapping takes %d swaps.\n", trocas);

        liberar(head);
    }

    return 0;
}