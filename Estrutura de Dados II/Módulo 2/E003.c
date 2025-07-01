#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Estrutura do n� da �rvore
typedef struct no {
    int dado;
    struct no* esquerda;
    struct no* direita;
} NO;

// Fun��o para criar um novo n�
NO* criarNo(int valor) {
    NO* novo = (NO*)malloc(sizeof(NO));
    novo->dado = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

// Fun��o para inserir um valor na �rvore
NO* inserir(NO* raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }

    if (valor < raiz->dado) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else {
        raiz->direita = inserir(raiz->direita, valor);
    }

    return raiz;
}

// Fun��o para percorrer a �rvore em p�s-ordem: esquerda ? direita ? atual
void posOrdem(NO* raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esquerda);     // visita os filhos da esquerda
        posOrdem(raiz->direita);      // depois os da direita
        printf("%d ", raiz->dado);    // por �ltimo imprime o n� atual
    }
}

// Fun��o principal
int main() {
    NO* raiz = NULL;
    setlocale(LC_ALL,"Portuguese");

    // Inserindo os valores na �rvore
    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 70);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 60);
    raiz = inserir(raiz, 80);

    // Imprimindo os valores em p�s-ordem
    printf("Valores da �rvore em p�s-ordem:\n");
    posOrdem(raiz);  // Sa�da esperada: 20 40 30 60 80 70 50

    return 0;
}
