#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Defini��o do n� da �rvore bin�ria
typedef struct no {
    int dado;                // valor armazenado no n�
    struct no* esquerda;     // ponteiro para o filho da esquerda
    struct no* direita;      // ponteiro para o filho da direita
} NO;

// Fun��o para criar um novo n�
NO* criarNo(int valor) {
    NO* novo = (NO*)malloc(sizeof(NO)); // aloca mem�ria dinamicamente
    novo->dado = valor;                 // armazena o valor
    novo->esquerda = NULL;              // filho esquerdo come�a vazio
    novo->direita = NULL;               // filho direito come�a vazio
    return novo;
}

// Fun��o para inserir um novo valor na �rvore
NO* inserir(NO* raiz, int valor) {
    if (raiz == NULL) {
        // Se a �rvore est� vazia, cria o primeiro n�
        return criarNo(valor);
    }

    if (valor < raiz->dado) {
        // Insere na sub�rvore da esquerda se o valor for menor
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else {
        // Insere na sub�rvore da direita se o valor for maior ou igual
        raiz->direita = inserir(raiz->direita, valor);
    }

    return raiz; // retorna a raiz atualizada
}

// Fun��o para imprimir a �rvore em ordem (ordena��o crescente)
void emOrdem(NO* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerda);              // visita os menores valores primeiro
        printf("%d ", raiz->dado);            // imprime o valor atual
        emOrdem(raiz->direita);               // depois os maiores valores
    }
}

// Fun��o principal
int main() {
    setlocale(LC_ALL,"Portuguese");
    NO* raiz = NULL; // ponteiro da raiz come�a vazio (�rvore vazia)

    // Inserindo valores na �rvore
    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 70);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 60);
    raiz = inserir(raiz, 80);

    // Exibindo os valores em ordem crescente
    printf("Valores da �rvore em ordem:\n");
    emOrdem(raiz); // imprime: 20 30 40 50 60 70 80

    return 0;
}
