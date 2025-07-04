#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

// Estrutura do nó da fila
typedef struct No {
    int valor;
    struct No* proximo;
} No;

typedef No* Fila;

Fila inicio = NULL;  // Início da fila (frente)
int opcao;

// Protótipos
void mostrar_menu();
void executar_opcao(int opcao);
void enfileirar();  // inserir no final
void desenfileirar(); // remover do início
void mostrar_fila(Fila fila);

// Função principal
int main() {
    setlocale (LC_ALL,"Portuguese");
    srand(time(NULL));  // Inicializa aleatórios
    opcao = 1;

    while (opcao != 0) {
        system("cls");
        mostrar_menu();
        scanf("%d", &opcao);
        executar_opcao(opcao);
    }

    system("pause");
    return 0;
}

// Exibe menu e mostra a fila atual
void mostrar_menu() {
    mostrar_fila(inicio);
    printf("\n\nEscolha uma das opcoes:\n");
    printf("1 - Inserir no final da fila (Enfileirar)\n");
    printf("2 - Remover do início da fila (Desenfileirar)\n");
    printf("0 - Sair\n\n");
}

// Executa a opção escolhida
void executar_opcao(int opcao) {
    switch (opcao) {
        case 1:
            enfileirar();
            break;
        case 2:
            desenfileirar();
            break;
        default:
            break;
    }
}

// Insere um novo nó no final da fila
void enfileirar() {
    Fila novo = (Fila) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de alocação!\n");
        return;
    }

    novo->valor = rand() % 100;
    novo->proximo = NULL;

    if (inicio == NULL) {
        // Se a fila está vazia, o novo elemento vira o início
        inicio = novo;
    } else {
        Fila aux = inicio;
        while (aux->proximo != NULL) { //aux aponta para o ultimo nó
            aux = aux->proximo; 
        }
        aux->proximo = novo; //adiciona o novo nó no fim da fila
    }
}

// Remove o nó do início da fila
void desenfileirar() {
    if (inicio == NULL) {
        printf("Fila vazia! Nada para remover.\n");
        system("pause");
        return;
    }

    Fila temp = inicio;
    inicio = inicio->proximo;
    free(temp);  // Libera o nó removido
}

// Mostra os valores da fila
void mostrar_fila(Fila fila) {
    printf("Fila (do início ao final):\n");

    if (fila == NULL) {
        printf("A fila está vazia.\n");
        return;
    }

    while (fila != NULL) {
        printf("%d ", fila->valor);
        fila = fila->proximo;
    }
}