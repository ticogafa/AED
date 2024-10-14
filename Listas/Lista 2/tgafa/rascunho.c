#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[30];
    int value;
    struct Node *prev;
    struct Node *next;
};

void insertNode(struct Node **head, struct Node **tail, char *name, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    newNode->value = value;

    if (*head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        *head = newNode;
        *tail = newNode;
    } else {
        newNode->next = *head;
        newNode->prev = *tail;
        (*tail)->next = newNode;
        (*head)->prev = newNode;
        *tail = newNode;
    }
}

void removeNode(struct Node **head, struct Node **tail, struct Node *node) {
    if (node->next == node) {
        *head = NULL;
        *tail = NULL;
    } else {
        struct Node *prevNode = node->prev;
        struct Node *nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        if (*head == node) {
            *head = nextNode;
        }
        if (*tail == node) {
            *tail = prevNode;
        }
    }
    free(node);
}

int main() {
    while (1) {
        int N, i, j;
        struct Node *head = NULL;
        struct Node *tail = NULL;

        scanf("%d", &N);
        if (!N)
            break;

        for (i = 0; i < N; ++i) {
            char name[30];
            int value;
            scanf("%s%d", name, &value);
            insertNode(&head, &tail, name, value);
        }

        struct Node *current = head;
        while (N > 1) {
            int value = current->value;

            if (value % 2) {
                for (j = 0; j < value; ++j)
                    current = current->next;
            } else {
                for (j = 0; j < value; ++j)
                    current = current->prev;
            }

            struct Node *toRemove = current;
            current = (value % 2) ? current->next : current->prev;
            removeNode(&head, &tail, toRemove);

            --N;
        }

        printf("Vencedor(a): %s\n", head->name);
        free(head);
    }

    return 0;
}