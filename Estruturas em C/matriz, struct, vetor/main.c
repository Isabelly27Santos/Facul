#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int vetor();
int matriz();
int registro();

int main(void) {

    setlocale(LC_ALL, "Portuguese");
    system("chcp 1252 > nul");

    int opcao;

    do {
        // Exibindo o menu de op��es
        system ("cls");
        printf("\nMenu:\n");
        printf("1. Fun��o Vetor\n");
        printf("2. Fun��o Matriz\n");
        printf("3. Fun��o Registro\n");
        printf("0. Sair\n\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);

        // Verificando a op��o escolhida e chamando a fun��o correspondente
        switch (opcao) {
            case 1:
                vetor();
                break;
            case 2:
                matriz();
                break;
            case 3:
                registro();
                break;
            case 0:
                printf("Saindo do programa. Obrigado!\n\n");
                break;
            default:
                printf("Op��o inv�lida. Por favor, escolha uma op��o v�lida.\n");
        }
    } while (opcao != 0);

    return 0;
}
