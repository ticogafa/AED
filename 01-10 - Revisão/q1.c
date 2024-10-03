//01 - Um determinado programa será implementado em C e deve permitir manipular números em uma lista circular 
//simplesmente encadeada, mas, possui apenas a função que insere nós. 
//      Inclua no programa uma nova funcionalidade que imprima a multiplicação dos valores de duplas de nós 
//que estão nesta lista. Se tiver uma quantidade ímpar de nós (sobrando um nó), para o nó restante, multiplique 
//o valor dele por ele próprio. E se a lista tiver menos que 2 nós, exiba a seguinte mensagem: “Tamanho da lista é insuficiente :(”.  
//     Protótipo da função: void multiplicacao(Node *head, Node *tail);

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {

    int data;
    struct Node *next;
} Node;

void multiplicacao(Node *head, Node *tail){

 if (head == NULL || tail == NULL) {
        printf("Tamanho da lista é insuficiente :(\n");
        return;
    }
    Node *aux = head;
    int cont = 0;

    do{
        cont++; 
        aux = aux->next;
        
    }while(aux!=head);

    if(cont<2){
        printf("Tamanho da lista é insuficiente :(");

    }else if(cont%2 == 0){
        aux = head;
        do{
            int multiplicacao = aux->data * aux->next->data;
            printf("%d", multiplicacao);
            aux = aux->next->next;
        }while(aux!=head);
    }else{
        aux = head;
        while(aux!=tail){
            int multiplicacao = aux->data * aux->next->data;
            printf("%d", multiplicacao);
            aux = aux->next->next;
        }
        int multiplicacao = aux->data * aux->data;
        printf("%d", multiplicacao);
    }

}