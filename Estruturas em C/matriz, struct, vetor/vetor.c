
#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_VETOR 5 // Tamanho do vetor

int vetor() {
    system ("cls");
    printf("------ C�lculo de m�dia com vetores ------\n");
    int vetor[TAMANHO_VETOR]; // Declara��o do vetor
    int i;
    float soma = 0;

    // Preenchendo o vetor com valores fornecidos pelo usu�rio
    printf("\n\t    Digite %d numeros\n\n", TAMANHO_VETOR);
    for (i = 0; i < TAMANHO_VETOR; i++) {
        printf("Numero %d: ", i+1);
        scanf("%d", &vetor[i]);
    }

    // Imprimindo os valores do vetor
    printf("\n------ Valores do vetor ------\n\n[ ");
    for (i = 0; i < TAMANHO_VETOR; i++) {
        printf("%d ", vetor[i]);
        soma += vetor[i]; // Calculando a soma dos valores
    }

    // Calculando a m�dia dos valores
    float media = soma / TAMANHO_VETOR;

    // Imprimindo a m�dia
    printf("]\n\nM�dia dos valores: %.2f\n\n\n\n", media);
    system ("pause");

    return 0;
}

