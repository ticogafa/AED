#include <stdio.h>

#define LEN 6

void trocar(int *a, int *b);  

int main(){

    int array[LEN] = {5, 2, 4, 6, 1, 3};
    for(int i = 1; i<LEN-1; i++){
        for(int j = LEN-1; j>=i; j--){
            if(array[j] < array[j-1]){
                trocar(&array[j], &array[j-1]);
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