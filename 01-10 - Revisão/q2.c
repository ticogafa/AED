//02 - Um determinado programa implementado em C deve permitir manipular números em uma lista circular
// duplamente encadeada, mas, possui apenas a função que insere nós. 
//       Inclua no programa uma nova funcionalidade para imprimir todos os elementos que são precedidos
// por uma sequência de dois números ímpares. Se o elemento não tiver dois nós antecedentes, verifique 
//se os dois nós que o sucedem são ímpares para só então imprimir o elemento. E se a lista tiver menos 
//que 3 nós, exiba a seguinte mensagem: “Tamanho da lista é insuficiente :(”.
//   Protótipo da função: void sequencia(Node *head, Node *tail);

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{

    int data;
    struct Node *next, *prev;

}Node;

void sequencia(Node *head, Node *tail){

    

}