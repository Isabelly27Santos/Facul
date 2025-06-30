#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <locale.h>
#define TAMANHO 5

// Estrutura da fila circular
struct str_fila {
    int nome[TAMANHO];
    int inicio;
    int fim;
    int quantidade; // Conta quantos elementos tem na fila
};

struct str_fila fila;
int op = 1;

// Prot�tipos
void fila_entrar();
void fila_sair();
void fila_mostrar();
void exibir_menu();

int main() {
    setlocale(LC_ALL, "Portuguese");

    fila.inicio = 0;
    fila.fim = 0;
    fila.quantidade = 0;

    while (op != 0) {
        system("cls");
        fila_mostrar();
        exibir_menu();
        scanf(" %d", &op);
        switch (op) {
            case 1:
                fila_entrar();
                break;
            case 2:
                fila_sair();
                break;
        }
    }
    return 0;
}

// Inserir elemento na fila circular
void fila_entrar() {
    if (fila.quantidade == TAMANHO) {
        printf("\nA fila est� cheia!\n\n");
        system("pause");
    } else {
        printf("\nDigite o valor a ser inserido: ");
        scanf(" %d", &fila.nome[fila.fim]);
        fila.fim = (fila.fim + 1) % TAMANHO; // Avan�a o �ndice 'fim' para a pr�xima posi��o circularmente
        fila.quantidade++; //o %TAMANHO faz com que o vetor retorne a 0 quando atinge o limite.
    }
}

// Remover elemento da fila circular
void fila_sair() {
    if (fila.quantidade == 0) {
        printf("\nA fila est� vazia!\n\n");
        system("pause");
    } else {
        printf("\nValor removido: %d\n", fila.nome[fila.inicio]);
        fila.inicio = (fila.inicio + 1) % TAMANHO; // Apenas avan�a o �ndice 'inicio'
        fila.quantidade--;
        system("pause");
    }
}

// Mostrar a fila
void fila_mostrar() {
    printf("Fila: [ ");
    int i, pos;
    for (i = 0, pos = fila.inicio; i < fila.quantidade; i++) { //i e pos s�o contaoores
        printf("%d ", fila.nome[pos]);
        pos = (pos + 1) % TAMANHO;
    }
    printf("]\n\n");
}

// Mostrar menu
void exibir_menu() {
    printf("Escolha uma op��o:\n");
    printf("1 - Inserir na fila\n");
    printf("2 - Remover da fila\n");
    printf("0 - Sair\n\n");
}
