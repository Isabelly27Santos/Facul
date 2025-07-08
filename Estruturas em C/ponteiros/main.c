#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int ponteiro();

int incremento_decremento();

int aritimetica();

int acesso_memoria();

int comparacao_ponteiro();

int main(void) {

    setlocale(LC_ALL, "en_US.UTF-8");

    int opcao;

    do {
        // Exibindo o menu de op��es
        printf("\n\n------------------- Menu -------------------\n\n");
        printf("1. Fun��o de Ponteiro\n");
        printf("2. Fun��o de Incremento e decremento\n");
        printf("3. Fun��o de Aritim�tica\n");
        printf("4. Fun��o de Compara��o de ponteiro\n");
        printf("5. Fun��o de Acesso inv�lido de mem�ria\n");
        printf("0. Sair\n\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);

        // Verificando a op��o escolhida e chamando a fun��o correspondente
        switch (opcao) {
            case 1:
                ponteiro();
                system ("pause");
                system ("cls");
                break;
            case 2:
                incremento_decremento();
                system ("pause");
                system ("cls");
                break;
            case 3:
                aritimetica();
                system ("pause");
                system ("cls");
                break;
            case 4:
                comparacao_ponteiro();
                system ("pause");
                system ("cls");
                break;
            case 5:
                acesso_memoria();
                system ("pause");
                system ("cls");
                break;
            case 0:
                printf("Saindo do programa. Obrigado!\n\n\n");
                system ("pause");
                break;
            default:
                printf("Op��o inv�lida. Por favor, escolha uma op��o v�lida.\n\n\n");
                system ("pause");
                system ("cls");
        }
    } while (opcao != 0);

    return 0;
}
