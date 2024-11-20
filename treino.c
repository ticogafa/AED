#include <stdio.h>
#include <stdlib.h>

typedef struct Node {

    int chave;
    struct Node *esquerda, *direita;

}Node;

int main(){



    return 0;
}

int filhosAlt(Node *raiz){
    if(raiz == NULL) return 0;
    else{

        int ae = filhosAlt(raiz->esquerda);
        int ad = filhosAlt(raiz->direita);
        int maior;

        if (ae > ad) maior = ae;
        else maior = ad;   
        return 1 + maior;
    }
}