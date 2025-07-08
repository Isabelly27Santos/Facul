#include <stdio.h>
#include <stdlib.h>

int aritimetica() {
    system ("cls");
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr; // Inicializando o ponteiro ptr para apontar para o primeiro elemento do array
    printf("\n\nElementos do array {");
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        printf("%d ", *(ptr + i)); // Imprime o valor apontado por ptr + i
    }
    printf("}\n\n");
    printf("Valor inicial de ptr: %d\n", *ptr); // Imprime o valor apontado por ptr (10)
    getchar();
    getchar();

    // Opera��es aritm�ticas com ponteiros
    int offset = 2; // Deslocamento
    int indice = 1; // �ndice

    // Avan�ando o ponteiro ptr em offset posi��es
    ptr += offset;
    printf("Valor ap�s avan�ar %d posi��es: %d\n", offset, *ptr); // Imprime o valor apontado por ptr (30)
    getchar();

    // Retrocedendo o ponteiro ptr em offset posi��es
    ptr -= offset;
    printf("Valor ap�s retroceder %d posi��es: %d\n", offset, *ptr); // Imprime o valor apontado por ptr (10) novamente
    getchar();

    // Acessando um elemento espec�fico do array usando aritm�tica de ponteiro
    ptr = arr + indice;
    printf("Valor no �ndice %d: %d\n\n\n", indice, *ptr); // Imprime o valor apontado por ptr (20)
    getchar();

    return 0;
}
