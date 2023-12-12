#include <stdio.h>
#include <stdlib.h>

int main() {
    int tamanho1, tamanho2;

    printf("Digite o tamanho do primeiro array: ");
    scanf("%d", &tamanho1);

    printf("Digite o tamanho do segundo array: ");
    scanf("%d", &tamanho2);

    int *arr1 = malloc(tamanho1 * sizeof(int));
    int *arr2 = malloc(tamanho2 * sizeof(int));

    if (arr1 == NULL || arr2 == NULL) {
        fprintf(stderr, "Erro na alocação de memória.\n");
        return 1;
    }

    for (int i = 0; i < tamanho1; i++) {
        printf("Digite o elemento %d do primeiro array: ", i + 1);
        scanf("%d", &arr1[i]);
    }

    for (int i = 0; i < tamanho2; i++) {
        printf("Digite o elemento %d do segundo array: ", i + 1);
        scanf("%d", &arr2[i]);
    }

    int tamanhoSoma = (tamanho1 > tamanho2) ? tamanho1 : tamanho2;
    int *arrSoma = malloc(tamanhoSoma * sizeof(int));

    if (arrSoma == NULL) {
        fprintf(stderr, "Erro na alocação de memória para o array de soma.\n");
        free(arr1);
        free(arr2);
        return 1;
    }

    for (int i = 0; i < tamanhoSoma; i++) {
        arrSoma[i] = (i < tamanho1 ? arr1[i] : 0) + (i < tamanho2 ? arr2[i] : 0);
    }

    printf("Resultado da soma:\n");
    for (int i = 0; i < tamanhoSoma; i++) {
        printf("%d ", arrSoma[i]);
    }
    printf("\n");

    free(arr1);
    free(arr2);
    free(arrSoma);

    return 0;
}
