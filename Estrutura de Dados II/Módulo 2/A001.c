#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Definição do nó da árvore binária
typedef struct no {
    int dado;
    struct no* esquerda;
    struct no* direita;
} NO;

// Cria um novo nó
NO* criarNo(int valor) {
    NO* novo = (NO*)malloc(sizeof(NO));
    novo->dado = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    printf("%d ",novo->dado);
    return novo;
}

// Insere um valor na árvore binária de busca
NO* inserir(NO* raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor); // se a raiz for nula, cria um novo nó
    }

    if (valor < raiz->dado) {
        raiz->esquerda = inserir(raiz->esquerda, valor); // insere à esquerda
    } else {
        raiz->direita = inserir(raiz->direita, valor); // insere à direita
    }

    return raiz; // retorna a raiz da árvore (inalterada)
}

// Função para buscar um valor na árvore binária de busca
void buscarNaArvore(NO* raiz, int valor) {
    int passos = 0;

    while (raiz != NULL) {
        passos++; // conta os passos dados

        if (valor == raiz->dado) {
            printf("\n\nValor %d encontrado em %d passo(s).\n\n", valor, passos);
            return;
        } else if (valor < raiz->dado) {
            raiz = raiz->esquerda; // vai para a esquerda
        } else {
            raiz = raiz->direita; // vai para a direita
        }
    }

    printf("\n\nValor %d não encontrado após %d passo(s).\n\n", valor, passos);
}

// Função principal
int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");
    system("chcp 1252 > nul");

    NO* raiz = NULL;
    int arvore[] = {13, 70, 60, 39, 66, 55, 50, 42};
    int num = 1;
    printf("Nós da árvore: [ ");

    // Inserção dos valores na árvore binária de busca
    for (int i = 0; i < 8; i++) {
        raiz = inserir(raiz, arvore[i]);
    }
    printf("]");

    // Loop para busca de valores digitados pelo usuário
    while (num != 0) {
        printf("\nDigite o valor que deseja buscar (ou 0 para sair): ");
        scanf("%d", &num);

        if (num != 0) {
            buscarNaArvore(raiz, num);
        }
        system("pause");
        system("cls");
    }

    return 0;
}
