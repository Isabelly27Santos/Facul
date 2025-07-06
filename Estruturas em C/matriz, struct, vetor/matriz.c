#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

#define NUM_ALUNOS 3 // N�mero de alunos
#define NUM_DISCIPLINAS 4 // N�mero de disciplinas

int matriz() {
    system ("cls");
    printf("C�lculo de m�dia utilizando matriz\n");
    float notas[NUM_ALUNOS][NUM_DISCIPLINAS]; // Declara��o da matriz de notas
    int i, j;
    float media;

    // Preenchendo a matriz com valores fornecidos pelo usu�rio
    printf("\n----Digite as notas dos alunos----\n");
    for (i = 0; i < NUM_ALUNOS; i++) {
        printf("\n\t     Aluno %d\n", i+1);
        for (j = 0; j < NUM_DISCIPLINAS; j++) {
            printf("Nota %d - ", j+1);
            scanf("%f", &notas[i][j]);
        }
    }
    printf("\n\n\nAperte qualquer tecla para imprimir a m�dia das notas...");
    getch();

    // Calculando e imprimindo a m�dia de cada aluno]
    system ("cls");
    printf("\n-----------M�dia de cada aluno-----------\n\n");
    for (i = 0; i < NUM_ALUNOS; i++) {
        media = 0;
        for (j = 0; j < NUM_DISCIPLINAS; j++) {
            media += notas[i][j]; // O mesmo que media = media + notas [i][j], soma todas as notas
        }
        media /= NUM_DISCIPLINAS; // Calculando a m�dia
        printf("Aluno %d\t M�dia: %.2f\n", i+1, media);
    }
    printf("\n\n\n");
    system ("pause");
    return 0;
}
