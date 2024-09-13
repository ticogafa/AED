#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    char items[1000];
    int top;
} Node;

void iniciarPilha(Node *head) {
    head->top = -1;
}

int ehVazio(Node *head) {
    return head->top == -1;
}

void push(Node *head, char c) {
    if (head->top < 1000 - 1) {
        head->items[++(head->top)] = c;
    }
}

char pop(Node *head) {
    if (!ehVazio(head)) {
        return head->items[(head->top)--];
    }
    return '\0';
}

int contarDiamantes(char *linha) {
    Node head;
    iniciarPilha(&head);
    int diamantes = 0;

    for (int i = 0; linha[i] != '\0'; i++) {
        if (linha[i] == '<') {
            push(&head, '<');
        } else if (linha[i] == '>' && !ehVazio(&head)) {
            pop(&head);
            diamantes++;
        }
    }

    return diamantes;
}

int main() {
    int N;
    char linha[1000 + 1];

    scanf("%d", &N);
    getchar();
    
    for (int i = 0; i < N; i++) {
        fgets(linha, sizeof(linha), stdin);
        linha[strcspn(linha, "\n")] = 0;
        printf("%d\n", contarDiamantes(linha));
    }

    return 0;
}