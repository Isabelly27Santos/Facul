#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Defini��o do n� da �rvore bin�ria
typedef struct no {
    int dado;
    struct no* esquerda;
    struct no* direita;
} NO;

// Cria um novo n�
NO* criarNo(int valor) {
    NO* novo = (NO*)malloc(sizeof(NO));
    novo->dado = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    printf("%d ",novo->dado);
    return novo;
}

// Insere um valor na �rvore bin�ria de busca
NO* inserir(NO* raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor); // se a raiz for nula, cria um novo n�
    }

    if (valor < raiz->dado) {
        raiz->esquerda = inserir(raiz->esquerda, valor); // insere � esquerda
    } else {
        raiz->direita = inserir(raiz->direita, valor); // insere � direita
    }

    return raiz; // retorna a raiz da �rvore (inalterada)
}

// Fun��o para buscar um valor na �rvore bin�ria de busca
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

    printf("\n\nValor %d n�o encontrado ap�s %d passo(s).\n\n", valor, passos);
}

// Fun��o principal
int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");
    system("chcp 1252 > nul");

    NO* raiz = NULL;
    int arvore[] = {13, 70, 60, 39, 66, 55, 50, 42};
    int num = 1;
    printf("N�s da �rvore: [ ");

    // Inser��o dos valores na �rvore bin�ria de busca
    for (int i = 0; i < 8; i++) {
        raiz = inserir(raiz, arvore[i]);
    }
    printf("]");

    // Loop para busca de valores digitados pelo usu�rio
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
