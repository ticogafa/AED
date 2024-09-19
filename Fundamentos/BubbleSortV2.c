#include <stdio.h>

#define LEN 6

void trocar(int *a, int *b);

int main(){

    int array[LEN] = {5, 2, 4, 6, 1, 3};
    int n = 1, troca = 1;

    while(n<=LEN && troca ==1){
        troca = 0;
        for(int i = 0; i<LEN-1; i++){
            if(array[i] > array[i+1]){
                trocar(&array[i], &array[i+1]);
                troca = 1;
            }
        }
        n++;
    }

    printf("Array ordenado: ");
    for(int i = 0; i<LEN; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;

}

void trocar(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}