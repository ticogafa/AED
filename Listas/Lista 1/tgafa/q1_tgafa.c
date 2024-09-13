#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

void empilhar(Node** head, char c) {
    Node* novo = (Node*)malloc(sizeof(Node));
    if (novo == NULL) {
        printf("Erro: Falha na alocação de memória\n");
        return;
    }
    novo->data = c;
    novo->next = *head;
    *head = novo;
}

char remover(Node** head) {
    if (*head != NULL) {
        Node* temp = *head;
        char c = temp->data;
        *head = temp->next;
        free(temp);
        return c;
    }
    return '\0';
}

int contarDiamantes(char *linha, Node **head) {
    int diamantes = 0;

    for (int i = 0; linha[i] != '\0'; i++) {
        if (linha[i] == '<') {
            empilhar(head, '<');
        } else if (linha[i] == '>' && *head != NULL) {
            remover(head);
            diamantes++;
        }
    }
    while (*head != NULL) {
        remover(head);
    }

    return diamantes;
}

int main() {
    int n;
    char linha[1001];
    Node *head = NULL;

    scanf("%d", &n);
    getchar();
    
    for (int i = 0; i < n; i++) {
        fgets(linha, sizeof(linha), stdin);
        printf("%d\n", contarDiamantes(linha, &head));
    }

    return 0;
}