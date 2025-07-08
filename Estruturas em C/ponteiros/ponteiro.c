#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


int ponteiro() {
    system ("cls");
    int x = 10, *ptr; // Declara��o de uma vari�vel inteira x

    ptr = &x;   // Atribui��o do endere�o de x ao ponteiro ptr

    // Exibindo o valor de x e o valor apontado por ptr
    printf("\n\nint x = 10, *ptr;\t//vari�veis criadas.\nptr = &x;\t\t//ptr agora aponta pra x.\n\nResultado:\n\n");
    printf("\tprintf x: %d\n", x);
    printf("\tprintf *ptr: %d\n", *ptr);
    printf("\tprintf ptr: %d\n", ptr);
    printf("\tprintf &x: %d\n", &x);
    printf("\nPressione qualquer tecla pra continuar...\n\n");
    getch();

    // Alterando o valor de x atrav�s do ponteiro
    *ptr = 20;
    printf("\n*ptr = 20;\n\n");

    // Exibindo o novo valor de x e o valor apontado por ptr
    printf("Novo valor de x: %d\n", x);
    printf("Novo valor apontado por ptr: %d\n", *ptr);
    printf("\n\n--------------------------------------------------------------------\n\n");
    printf("Aprendido:\n\n- Ao criar o ponteiro, declare ele como tipo *ptr.");
    printf("\n- Para fazer ele apontar pra uma vari�vel escreva ptr = &var. ");
    printf("\n- Para acessar o endere�o da vari�vel escreva &var ou ptr. ");
    printf("\n- Para acessar o valor da vari�vel escreva var ou *ptr.");
    printf("\n- Para alterar o conte�do de ptr e var escreva *ptr = dado.\n\n\n");
    getchar();
    return 0;

}
