#include <stdio.h>

void insertionSort(int arr[], int LEN){

    for(int i = 0; i<LEN; i++){
        int j = i;
        while(j > 0 && arr[j] < arr[j-1]){
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
    }

}

void bubbleSort(int arr[], int LEN){

    int n = 1, troca = 1;
    while(troca == 1 && n<=LEN){
        troca = 0;
        for(int i = 0; i<LEN-1; i++){
            if(arr[i] > arr[i+1]){
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                troca = 1;
            }
        }
        ++n;
    }
}