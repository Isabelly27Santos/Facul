#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Definição do nó da árvore binária
typedef struct no {
    int dado;                // valor armazenado no nó
    struct no* esquerda;     // ponteiro para o filho da esquerda
    struct no* direita;      // ponteiro para o filho da direita
} NO;

// Função para criar um novo nó
NO* criarNo(int valor) {
    NO* novo = (NO*)malloc(sizeof(NO)); // aloca memória dinamicamente
    novo->dado = valor;                 // armazena o valor
    novo->esquerda = NULL;              // filho esquerdo começa vazio
    novo->direita = NULL;               // filho direito começa vazio
    return novo;
}

// Função para inserir um novo valor na árvore
NO* inserir(NO* raiz, int valor) {
    if (raiz == NULL) {
        // Se a árvore está vazia, cria o primeiro nó
        return criarNo(valor);
    }

    if (valor < raiz->dado) {
        // Insere na subárvore da esquerda se o valor for menor
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else {
        // Insere na subárvore da direita se o valor for maior ou igual
        raiz->direita = inserir(raiz->direita, valor);
    }

    return raiz; // retorna a raiz atualizada
}

// Função para imprimir a árvore em ordem (ordenação crescente)
void emOrdem(NO* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerda);              // visita os menores valores primeiro
        printf("%d ", raiz->dado);            // imprime o valor atual
        emOrdem(raiz->direita);               // depois os maiores valores
    }
}

// Função principal
int main() {
    setlocale(LC_ALL,"Portuguese");
    NO* raiz = NULL; // ponteiro da raiz começa vazio (árvore vazia)

    // Inserindo valores na árvore
    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 70);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 60);
    raiz = inserir(raiz, 80);

    // Exibindo os valores em ordem crescente
    printf("Valores da árvore em ordem:\n");
    emOrdem(raiz); // imprime: 20 30 40 50 60 70 80

    return 0;
}
