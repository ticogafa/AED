#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char nome[30];
    struct Node *next;
} Node;

Node *head = NULL;
Node *tail = NULL;
int atendidos = 0;

void incluir(char nome[30]) {
    Node *novo = (Node*)malloc(sizeof(Node));
    if (!novo) {
        printf("Erro ao alocar memória.\n");
        return;
    }
    strcpy(novo->nome, nome);
    novo->next = NULL;
    if (tail == NULL) {
        head = tail = novo;
    } else {
        tail->next = novo;
        tail = novo;
    }
}

void atender() {
    if (head == NULL) {
        printf("Nenhum paciente para atender.\n");
        return;
    }
    Node *temp = head;
    head = head->next;
    if (head == NULL) {
        tail = NULL;
    }
    free(temp);
    atendidos++;
    printf("Paciente atendido.\n");
}

void buscar(char nome[30]) {
    Node *current = head;
    int pos = 1;
    while (current != NULL) {
        if (strcmp(current->nome, nome) == 0) {
            printf("Paciente %s está na posição %d.\n", nome, pos);
            return;
        }
        current = current->next;
        pos++;
    }
    printf("Paciente %s não encontrado.\n", nome);
}

void quantidadeAtendidos() {
    printf("Quantidade de pacientes já atendidos: %d\n", atendidos);
}

int main() {
    int escolha;
    char nome[30];

    while (1) {
        printf("\nClínica Médica\n");
        printf("=============\n");
        printf("(1) Incluir paciente\n");
        printf("(2) Realizar atendimento do paciente\n");
        printf("(3) Consultar a posição atual do paciente pelo nome\n");
        printf("(4) Exibir a quantidade de pacientes já atendidos\n");
        printf("(5) Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);
        getchar(); 

        switch (escolha) {
            case 1:
                printf("Nome do paciente: ");
                fgets(nome, 30, stdin);
                nome[strcspn(nome, "\n")] = '\0';
                incluir(nome);
                break;
            case 2:
                atender();
                break;
            case 3:
                printf("Nome do paciente: ");
                fgets(nome, 30, stdin);
                nome[strcspn(nome, "\n")] = '\0';
                buscar(nome);
                break;
            case 4:
                quantidadeAtendidos();
                break;
            case 5:
                printf("Saindo...\n");
                return 0;
            default:
                printf("Opção inválida.\n");
        }
    }
    return 0;
}