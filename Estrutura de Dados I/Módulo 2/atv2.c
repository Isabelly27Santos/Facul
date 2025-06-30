#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define TAMANHO 5

struct str_fila {
    char nome[TAMANHO][30];
    int hora[TAMANHO];
    int min[TAMANHO];
    int horas[TAMANHO];
};

struct str_fila fila;
int op = 1, inicio = 0, fim = 0;

// Protótipos
void fila_entrar();
void fila_sair();
void fila_mostrar();
void exibir_menu();
void fila_ordenar(); // Corrigido o nome

int main() {
    setlocale(LC_ALL, "Portuguese");
    system ("color B0");
    system("title Controle de Fila");
    system("chcp 1252 > nul");

    while (op != 0) {
        system("cls");
        printf("[ ");
        for (int i = 0; i < fim; i++) {
            printf("%s, ", fila.nome[i]);
        }
        printf(" ]\n");

        exibir_menu();
        scanf(" %d", &op);
        getchar(); // limpa \n do buffer

        switch (op) {
            case 1:
                fila_entrar();
                break;
            case 2:
                fila_sair();
                break;
            case 3:
                fila_mostrar();
                break;
            case 0:
                break; // Corrigido
        }
    }
    return 0;
}

// Adicionar um elemento no final da Fila
void fila_entrar() {
    if (fim == TAMANHO) {
        printf("\nA fila está cheia, volte outro dia!\n\n");
        system("pause");
    } else {
        printf("\nDigite o nome do cliente: ");
        fgets(fila.nome[fim], sizeof(fila.nome[fim]), stdin);
        fila.nome[fim][strcspn(fila.nome[fim], "\n")] = '\0';

        printf("Digite a hora de chegada no formato 0000 (exemplo: 1240): ");
        scanf(" %d", &fila.hora[fim]);

        fila.horas[fim] = fila.hora[fim] / 100;
        fila.min[fim] = fila.hora[fim] % 100;
        fim++;

        printf("\nCliente adicionado à fila!\n");
        fila_ordenar();
        system("pause");
    }
}

// Ordena a fila do menor horário para o maior
void fila_ordenar() {
    for (int i = 0; i < fim - 1; i++) {
        for (int j = 0; j < fim - 1 - i; j++) {
            if (fila.hora[j] > fila.hora[j + 1]) {
                int tempHora = fila.hora[j];
                fila.hora[j] = fila.hora[j + 1];
                fila.hora[j + 1] = tempHora;

                int tempHoras = fila.horas[j];
                fila.horas[j] = fila.horas[j + 1];
                fila.horas[j + 1] = tempHoras;

                int tempMin = fila.min[j];
                fila.min[j] = fila.min[j + 1];
                fila.min[j + 1] = tempMin;

                char tempNome[30];
                strcpy(tempNome, fila.nome[j]);
                strcpy(fila.nome[j], fila.nome[j + 1]);
                strcpy(fila.nome[j + 1], tempNome);
            }
        }
    }
}

// Retirar o primeiro elemento da Fila
void fila_sair() {
    if (inicio == fim) {
        printf("\nFila vazia, mas logo aparece alguém!\n\n");
        system("pause");
    } else {
        printf("\nCliente %s removido da fila!\n", fila.nome[0]);

        for (int i = 0; i < fim - 1; i++) {
            strcpy(fila.nome[i], fila.nome[i + 1]);
            fila.horas[i] = fila.horas[i + 1];
            fila.hora[i] = fila.hora[i + 1];
            fila.min[i] = fila.min[i + 1];
        }

        fila.nome[fim - 1][0] = '\0';
        fila.hora[fim - 1] = -1;
        fila.horas[fim - 1] = -1;
        fila.min[fim - 1] = -1;
        fim--;

        system("pause");
    }
}

// Mostrar o conteúdo da Fila
void fila_mostrar() {
    printf("\n\t\tLISTA DE ESPERA\n\n");
    for (int i = 0; i < fim; i++) {
        printf("Posição %d\nNome: %s\nHora de chegada: %02d:%02dh\n", 
            i + 1, fila.nome[i], fila.horas[i], fila.min[i]);
        printf("__________________\n\n");
    }
    system("pause");
}

// Mostrar o menu de opções
void exibir_menu() {
    printf("\nEscolha uma opção:\n");
    printf("1 - Incluir na Fila\n");
    printf("2 - Excluir da Fila\n");
    printf("3 - Exibir fila completa\n");
    printf("0 - Sair\n\n");
}
