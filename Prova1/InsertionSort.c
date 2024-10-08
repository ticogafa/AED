//6. Insertion Sort
//Um programa C armazena números em um vetor e usa o algoritmo de ordenação Insertion Sort. 
//Adapte o algoritmo para que ele também retorne o número total de comparações feitas 
//durante o processo de ordenação.

#include <stdio.h>

void insertionSort(int arr[], int LEN);
void printArray(int arr[], int LEN);
void troca(int *a, int *b);

int main(){

    int arr[] = {12,32452,12123,3212,23145,9,876,5,543,2345,523,5646,74,3,24,67,5,32,4,6477,56,75,4};
    int LEN = sizeof(arr)/sizeof(arr[0]);

    printArray(arr, LEN);
    insertionSort(arr, LEN);
    printArray(arr, LEN);


    return 0;
}

void insertionSort(int arr[], int LEN){

int comparacoes = 0;

    for(int i = 0; i < LEN; i++){
        int j = i;
        while(arr[j]<arr[j-1] && j>0){
            troca(&arr[j], &arr[j-1]);
            j--;
            comparacoes++;
        }
    }

    printf("\nComparações: %d\n", comparacoes);
    
}

void troca(int *a, int *b){
        int temp = *a;
        *a = *b;
        *b = temp;
}

void printArray(int arr[], int LEN){

    for(int i = 0; i < LEN; i++){
        printf("%d -> ", arr[i]);
    }
    printf("\n");

}