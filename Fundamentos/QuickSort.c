#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quickSort(int *vetor, int inicio, int fim) {
    int i, j, pivo, aux;
    i = inicio;
    j = fim;
    pivo = vetor[(inicio + fim) / 2];
    while(i <= j) {
        while(vetor[i] < pivo) {
            i++;
        }
        while(vetor[j] > pivo) {
            j--;
        }
        if(i <= j) {
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i++;
            j--;
        }
    }
    if(j > inicio) {
        quickSort(vetor, inicio, j);
    }
    if(i < fim) {
        quickSort(vetor, i, fim);
    }
}

int main() {
    int i, n = 10;
    int vetor[n];
    srand(time(NULL));
    for(i = 0; i < n; i++) {
        vetor[i] = rand() % 100;
    }
    printf("Vetor desordenado:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    quickSort(vetor, 0, n - 1);
    printf("\nVetor ordenado:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    return 0;
}
