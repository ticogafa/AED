#include <stdio.h>

int somaMultiplicadosPor2(int n) {
    if (n == 0) {
        return 0;
    } else {
        return 2 * n + somaMultiplicadosPor2(n - 1);
    }
}

int somaArray(int arr[], int n) {
    if (n <= 0) {
        return 0;
    } else {
        return arr[n - 1] + somaArray(arr, n - 1);
    }
}

int main() {
    int n = 3;
    int arr[] = {1, 2, 3};
    printf("Resultado: %d\n", somaMultiplicadosPor2(n));
    printf("Resultado: %d\n", somaArray(arr, n));
    return 0;
}