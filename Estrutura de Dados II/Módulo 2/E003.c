#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Estrutura do nó da árvore
typedef struct no {
    int dado;
    struct no* esquerda;
    struct no* direita;
} NO;

// Função para criar um novo nó
NO* criarNo(int valor) {
    NO* novo = (NO*)malloc(sizeof(NO));
    novo->dado = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

// Função para inserir um valor na árvore
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

// Função para percorrer a árvore em pós-ordem: esquerda ? direita ? atual
void posOrdem(NO* raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esquerda);     // visita os filhos da esquerda
        posOrdem(raiz->direita);      // depois os da direita
        printf("%d ", raiz->dado);    // por último imprime o nó atual
    }
}

// Função principal
int main() {
    NO* raiz = NULL;
    setlocale(LC_ALL,"Portuguese");

    // Inserindo os valores na árvore
    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 70);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 60);
    raiz = inserir(raiz, 80);

    // Imprimindo os valores em pós-ordem
    printf("Valores da árvore em pós-ordem:\n");
    posOrdem(raiz);  // Saída esperada: 20 40 30 60 80 70 50

    return 0;
}
