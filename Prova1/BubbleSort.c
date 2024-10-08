//7. Bubble Sort

//Um programa C utiliza o algoritmo de ordenação Bubble Sort para ordenar um vetor de números inteiros. 
//Adicione uma função que retorne o número de trocas realizadas durante a ordenação. Se o vetor já 
//estiver ordenado, exiba a mensagem "Nenhuma troca necessária :)".

//Protótipo da função: int bubble_sort_trocas(int arr[], int n);

#include <stdio.h>

int bubble_sort_trocas(int arr[], int LEN);
void trocar(int *a, int *b);
void printArray(int arr[], int LEN);

int main(){

    int arr[] = {10,7,6,875,345,23,23425,2,235434,43,234,236,324367,56,34};
    int LEN = sizeof(arr)/sizeof(arr[0]);

    printArray(arr, LEN);
    bubble_sort_trocas(arr, LEN);
    printArray(arr, LEN);


    return 0;
}

void printArray(int arr[], int LEN){


    for(int i = 0; i<LEN; i++){
        printf("%d -> ", arr[i]);
    }

    printf("\n");
}

int bubble_sort_trocas(int arr[], int LEN){

    int n = 1, troca = 1;
    int trocaRealizadas = 0;

    while(troca == 1 && n<=LEN){
        troca = 0;
        for(int i = 0; i<LEN-1; i++){
            if(arr[i]>arr[i+1]){
                trocar(&arr[i], &arr[i+1]);
                troca = 1;
                trocaRealizadas++;
            }
        }
        ++n;
    }

    printf("\nNenhuma troca necessária :)\n");
    printf("\nQuantidade de trocas realizadas: %d\n", trocaRealizadas);

    return trocaRealizadas;
}

void trocar(int *a, int *b){

    int temp = *a;
    *a = *b;
    *b = temp;
}