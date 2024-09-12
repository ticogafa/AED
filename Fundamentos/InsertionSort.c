#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int LEN) {
    int i, aux, j; // i = index, aux = value, j = index
    for (i = 1; i < LEN; i++) {// i = 1 because the first element is already sorted
        aux = arr[i];// aux = value of the current element
        j = i - 1;      // j = index of the previous element

        while (j >= 0 && arr[j] > aux) {        // while the previous element is greater than the current element
            arr[j + 1] = arr[j];    // move the previous element to the right
            j = j - 1;            // move to the left
        }     // end of the while loop
        arr[j + 1] = aux;   // insert the current element in the right position
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
