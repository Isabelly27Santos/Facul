#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Defini��o do n� da �rvore
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
    return novo;
}

// Insere um valor na �rvore bin�ria de busca
NO* inserir(NO* raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }

    if (valor < raiz->dado) {
        raiz->esquerda = inserir(raiz->esquerda, valor); 
    } else {
        raiz->direita = inserir(raiz->direita, valor);
    }

    return raiz; //retorna o primeiro n� inserido
}

// Percurso em PR�-ORDEM: atual ? esquerda ? direita
void preOrdem(NO* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->dado);      // visita o n� atual
        preOrdem(raiz->esquerda);       // visita sub�rvore da esquerda
        preOrdem(raiz->direita);        // visita sub�rvore da direita
    }
}

// Fun��o principal
int main() {
    setlocale(LC_ALL,"Portuguese_Brazil");
    system("chcp 1252>nul");
    NO* raiz = NULL;

    // Inser��o dos valores
    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 70);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 60);
    raiz = inserir(raiz, 80);

    // Impress�o em pr�-ordem
    printf("Valores da �rvore em pr�-ordem:\n");
    preOrdem(raiz);  // Sa�da esperada: 50 30 20 40 70 60 80

    return 0;
}
