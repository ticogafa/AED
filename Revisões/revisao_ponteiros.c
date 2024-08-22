#include <stdio.h>

void calcular_media(int *a, int *b) {
    int media = (*a + *b) / 2;
    int resto = (*a + *b) % 2;

    if (*a < *b) {
        *a = media;
        *b = resto;
    } else {
        *b = media;
        *a = resto;
    }
}

int main() {
    int A, B;
    printf("Digite dois números inteiros A e B:\n");
    scanf("%d %d", &A, &B);

    calcular_media(&A, &B);

    printf("Os novos valores de A e B:\n");
    printf("A = %d\n", A);
    printf("B = %d\n", B);

    return 0;
}