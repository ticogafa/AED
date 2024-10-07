#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int LEN){
    for (int i = 1; i < LEN; i++){
        int j = i;
        while ((arr[j] < arr[j - 1]) && j > 0){
            int aux = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = aux;
            --j;
        }
    }
}

void printArray(int arr[], int LEN){
    int i;
    for (i = 0; i < LEN; i++)   
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    int arr[] = {37, 43, 123, 12, 32, 65, 86, 98, 90};
    int LEN = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, LEN);
    insertionSort(arr, LEN);
    printArray(arr, LEN);

    return 0;
}