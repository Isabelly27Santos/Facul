#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

// Estrutura do n� da pilha
typedef struct No {
    int valor;
    struct No* proximo;
} No;

typedef No* Pilha;

Pilha topo = NULL;  // Ponteiro para o topo da pilha
int opcao;

// Prot�tipos
void mostrar_menu();
void executar_opcao(int opcao);
void empilhar(Pilha* topo);   // push
void desempilhar(Pilha* topo); // pop
void mostrar_pilha(Pilha topo);

// Fun��o principal
int main() {
    setlocale (LC_ALL,"Portuguese");
    srand(time(NULL));  // Inicializa gerador de n�meros aleat�rios
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
    printf("\n\nEscolha uma das op��es:\n");
    printf("1 - Empilhar (inserir no topo da pilha)\n");
    printf("2 - Desempilhar (remover do topo da pilha)\n");
    printf("0 - Sair\n\n");
}

// Executa a a��o de acordo com a op��o escolhida
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
        printf("Erro de aloca��o de mem�ria!\n");
        return;
    }

    novo_no->valor = rand() % 100; // valor aleat�rio entre 0 e 99
    novo_no->proximo = *topo;      // novo n� aponta para o antigo topo
    *topo = novo_no;               // atualiza o topo para o novo n�
}

// Remove o valor do topo da pilha (pop)
void desempilhar(Pilha* topo) {
    if (*topo == NULL) {
        printf("Pilha vazia! Nada para remover.\n");
        system("pause");
        return;
    }

    Pilha temp = *topo;
    *topo = (*topo)->proximo;  // Move o topo para o pr�ximo n�
    free(temp);                // Libera o n� removido
}

// Mostra os elementos da pilha do topo at� a base
void mostrar_pilha(Pilha topo) {
    printf("Pilha (do topo para a base):\n");

    if (topo == NULL) {
        printf("A pilha est� vazia.\n");
        return;
    }

    while (topo != NULL) {
        printf("%d\n", topo->valor);
        topo = topo->proximo;
    }
}