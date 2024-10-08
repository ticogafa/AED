#include <stdio.h>

void insertionSort(int arr[], int LEN);
void printArray(int arr[], int LEN);

int main(){

    int arr[] = {32,6,4,231,456,34,65};
    int LEN = sizeof(arr)/sizeof(arr[0]);

    printArray(arr, LEN);
    printf("\n");
    insertionSort(arr, LEN);
    printArray(arr, LEN);
    printf("\n");

    return 0;
}

void insertionSort(int arr[], int LEN){

    for(int i = 1; i<LEN; i++){
        int j = i;
        while(arr[j]<arr[j-1] && j>0){
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
    }

}

void printArray(int arr[], int LEN){

    for(int i = 0; i< LEN; i++){
        printf("%d -> ", arr[i]);
    }

}