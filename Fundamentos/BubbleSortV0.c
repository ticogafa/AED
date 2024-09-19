#include <stdio.h>
#define LEN 6

void trocar(int *a, int *b);

int main(){

    int array[LEN] = {5, 2, 4, 6, 1, 3};

    for(int i = 1; i<LEN; i++){
        for(int j = 0; j<LEN-1; j++){
            if(array[j] > array[j+1]){
                trocar(&array[j], &array[j+1]);
            }
        }
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