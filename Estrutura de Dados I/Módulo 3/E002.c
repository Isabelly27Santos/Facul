#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

// Estrutura do nó da pilha
typedef struct No {
    int valor;
    struct No* proximo;
} No;

typedef No* Pilha;

Pilha topo = NULL;  // Ponteiro para o topo da pilha
int opcao;

// Protótipos
void mostrar_menu();
void executar_opcao(int opcao);
void empilhar(Pilha* topo);   // push
void desempilhar(Pilha* topo); // pop
void mostrar_pilha(Pilha topo);

// Função principal
int main() {
    setlocale (LC_ALL,"Portuguese");
    srand(time(NULL));  // Inicializa gerador de números aleatórios
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

// Exibe o menu e a pilha atual
void mostrar_menu() {
    mostrar_pilha(topo);
    printf("\n\nEscolha uma das opções:\n");
    printf("1 - Empilhar (inserir no topo da pilha)\n");
    printf("2 - Desempilhar (remover do topo da pilha)\n");
    printf("0 - Sair\n\n");
}

// Executa a ação de acordo com a opção escolhida
void executar_opcao(int opcao) {
    switch (opcao) {
        case 1:
            empilhar(&topo);
            break;
        case 2:
            desempilhar(&topo);
            break;
        default:
            break;
    }
}

// Insere um novo valor no topo da pilha (push)
void empilhar(Pilha* topo) {
    Pilha novo_no = (Pilha) malloc(sizeof(No));

    if (novo_no == NULL) {
        printf("Erro de alocação de memória!\n");
        return;
    }

    novo_no->valor = rand() % 100; // valor aleatório entre 0 e 99
    novo_no->proximo = *topo;      // novo nó aponta para o antigo topo
    *topo = novo_no;               // atualiza o topo para o novo nó
}

// Remove o valor do topo da pilha (pop)
void desempilhar(Pilha* topo) {
    if (*topo == NULL) {
        printf("Pilha vazia! Nada para remover.\n");
        system("pause");
        return;
    }

    Pilha temp = *topo;
    *topo = (*topo)->proximo;  // Move o topo para o próximo nó
    free(temp);                // Libera o nó removido
}

// Mostra os elementos da pilha do topo até a base
void mostrar_pilha(Pilha topo) {
    printf("Pilha (do topo para a base):\n");

    if (topo == NULL) {
        printf("A pilha está vazia.\n");
        return;
    }

    while (topo != NULL) {
        printf("%d\n", topo->valor);
        topo = topo->proximo;
    }
}