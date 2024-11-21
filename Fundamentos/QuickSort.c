#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quickSort(int inicio, int fim, int v[]);
int particao(int inicio, int fim, int v[]);
void troca(int v[], int i, int j);

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
    quickSort(0, n - 1, vetor);
    printf("\nVetor ordenado:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\n");

    printf("Tempo de execucao: %f segundos\n", (double)clock() / CLOCKS_PER_SEC);

    return 0;
}

void quickSort(int inicio, int fim, int v[]){
    
    if(inicio<fim){

        int indice = particao(inicio, fim, v);

        quickSort(inicio, indice-1, v);
        quickSort(indice+1, fim, v);

    }
}

int particao(int inicio, int fim, int v[]){ 

    int pivo = v[inicio];
    int i;
    int indice = fim;

    for(i = fim; i > inicio; i--){

        if(v[i] >= pivo){

            troca(v, i, indice);
            indice--;
        
        }
    }

    troca(v, inicio, indice);

    return indice;
}

void troca(int v[], int i, int j){
    
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;

}
