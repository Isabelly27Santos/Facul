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

// Protótipos
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
        wprintf("\nA fila está cheia!\n\n");
        system("pause");
    } else {
        wprintf("\nDigite o valor a ser inserido: ");
        scanf(" %d", &fila.nome[fila.fim]);
        fila.fim = (fila.fim + 1) % TAMANHO; // Avança o índice 'fim' para a próxima posição circularmente
        fila.quantidade++; //o %TAMANHO faz com que o vetor retorne a 0 quando atinge o limite.
    }
}

// Remover elemento da fila circular
void fila_sair() {
    if (fila.quantidade == 0) {
        wprintf("\nA fila está vazia!\n\n");
        system("pause");
    } else {
        wprintf("\nValor removido: %d\n", fila.nome[fila.inicio]);
        fila.inicio = (fila.inicio + 1) % TAMANHO; // Apenas avança o índice 'inicio'
        fila.quantidade--;
        system("pause");
    }
}

// Mostrar a fila
void fila_mostrar() {
    wprintf("Fila: [ ");
    int i, pos;
    for (i = 0, pos = fila.inicio; i < fila.quantidade; i++) { //i e pos são contaoores
        wprintf("%d ", fila.nome[pos]);
        pos = (pos + 1) % TAMANHO;
    }
    wprintf("]\n\n");
}

// Mostrar menu
void exibir_menu() {
    wprintf("Escolha uma opção:\n");
    wprintf("1 - Inserir na fila\n");
    wprintf("2 - Remover da fila\n");
    wprintf("0 - Sair\n\n");
}
