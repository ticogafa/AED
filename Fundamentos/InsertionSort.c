#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int LEN) {
    int i, aux, j;
    for (i = 1; i < LEN; i++) {
        aux = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > aux) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = aux;
    }
}

void printArray(int arr[], int LEN) {
    int i;
    for (i = 0; i < LEN; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {10,9,8,7,6,5,4,3,2,1};
    int LEN = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, LEN);
    printArray(arr, LEN);

    return 0;
}
