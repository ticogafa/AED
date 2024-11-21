#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 10

void mergesort(int inicio, int fim, int v[]);
void intercala(int inicio, int meio, int fim, int v[]);

int main(){

    int v[TAMANHO] = {38, 27, 43, 3, 9, 82, 10, 15, 6, 1};
    int i;

    printf("Array antes da ordenação:\n");
    for (i = 0; i < TAMANHO; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    mergesort(0, TAMANHO - 1, v);

    printf("Array após a ordenação:\n");
    for (i = 0; i < TAMANHO; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;

}

void mergesort (int inicio, int fim, int v[]) {
    if (inicio < fim) {
        int meio = (inicio + fim)/2;
        mergesort (inicio, meio, v);
        mergesort (meio+1, fim, v);
        intercala (inicio, meio, fim, v);
    }
 }

 void intercala (int inicio, int meio, int fim, int v[]) {
        int inicio_v01 = inicio;
        int inicio_v02 = meio+1;
        int poslivre = 0;
        int aux[TAMANHO];
        
        while (inicio_v01 <= meio && inicio_v02 <= fim) {
            if (v[inicio_v01] <= v[inicio_v02])
                aux[poslivre++] = v[inicio_v01++];
            else
                aux[poslivre++] = v[inicio_v02++];
        }
        //se existirem núm. em v[inicio_v01] que não foram intercalados
        while (inicio_v01 <= meio)
            aux[poslivre++] = v[inicio_v01++];
        //se existirem núm. em v[inicio_v02] que não foram intercalados
        while (inicio_v02 <= fim)
            aux[poslivre++] = v[inicio_v02++];
        //retorna os valores do vetor aux para o vetor v
        for (inicio_v01 = inicio; inicio_v01 <= fim; inicio_v01++)
            v[inicio_v01] = aux[inicio_v01-inicio];
}