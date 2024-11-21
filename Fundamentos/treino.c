#include <stdio.h>

#define TAMANHO 10

void mergeSort(int inicio, int final, int v[]);
void intercala(int inicio, int meio, int final, int v[]);

int main(){


    int v[TAMANHO] = {
        1,
        5,
        3,
        45,
        65,
        43,
        32,
        12,
        98,
        87
    };

    for(int i = 0; i<TAMANHO; i++){
        printf("%d ", v[i]);
    }
    printf("\n");

    mergeSort(0, TAMANHO-1, v);


    for(int i = 0; i<TAMANHO; i++){
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}


void mergeSort(int inicio, int final, int v[]){
    if(inicio < final){

        int meio = (inicio + final) / 2;

        mergeSort(inicio, meio, v);
        mergeSort(meio + 1, final, v);
        intercala(inicio, meio, final, v);
    }
}

void intercala(int inicio, int meio, int final, int v[]){

    int inicio1 = inicio;
    int inicio2 = meio + 1;
    int posLivre = 0;
    int aux[TAMANHO];

    while(inicio1<=meio && inicio2<=final){
        if(v[inicio1]<=v[inicio2]) aux[posLivre++] = v[inicio1++];
        else aux[posLivre++] = v[inicio2++];
    }

    while(inicio1<=meio) aux[posLivre++] = v[inicio1++];
    while(inicio2<=final) aux[posLivre++] = v[inicio2++];

    for(inicio1 = inicio; inicio1<=final; inicio1++) v[inicio1] = aux[inicio1 - inicio];
}