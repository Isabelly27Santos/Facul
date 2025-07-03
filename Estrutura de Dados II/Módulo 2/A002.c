#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Defini��o do n� AVL
typedef struct no {
    int dado;
    int altura;
    struct no* esquerda;
    struct no* direita;
} NO;

// Fun��o para retornar a altura de um n�
int altura(NO* n) {
    return (n == NULL) ? 0 : n->altura;
}

// Fun��o para obter o maior valor entre dois
int max(int a, int b) {
    return (a > b) ? a : b; //se verdadeiro retorna a, se falso retorna b
}

// Cria um novo n�
NO* criarNo(int valor) {
    NO* novo = (NO*)malloc(sizeof(NO));
    novo->dado = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    novo->altura = 1;
    return novo;
}

// Rota��o � direita
NO* rotacaoDireita(NO* y) {
    NO* x = y->esquerda;
    NO* T2 = x->direita;

    x->direita = y;
    y->esquerda = T2;

    y->altura = max(altura(y->esquerda), altura(y->direita)) + 1;
    x->altura = max(altura(x->esquerda), altura(x->direita)) + 1;

    return x;
}

// Rota��o � esquerda
NO* rotacaoEsquerda(NO* x) {
    NO* y = x->direita;
    NO* T2 = y->esquerda;

    y->esquerda = x;
    x->direita = T2;

    x->altura = max(altura(x->esquerda), altura(x->direita)) + 1;
    y->altura = max(altura(y->esquerda), altura(y->direita)) + 1;

    return y;
}

// Fator de balanceamento
int getBalance(NO* n) {
    return (n == NULL) ? 0 : altura(n->esquerda) - altura(n->direita);
}

// Inser��o AVL
NO* inserir(NO* no, int valor) {
    if (no == NULL)
        return criarNo(valor);

    if (valor < no->dado)
        no->esquerda = inserir(no->esquerda, valor);
    else if (valor > no->dado)
        no->direita = inserir(no->direita, valor);
    else
        return no; // valor duplicado n�o � inserido

    no->altura = 1 + max(altura(no->esquerda), altura(no->direita));
    int balance = getBalance(no);

    // Casos de rota��o
    if (balance > 1 && valor < no->esquerda->dado)
        return rotacaoDireita(no);

    if (balance < -1 && valor > no->direita->dado)
        return rotacaoEsquerda(no);

    if (balance > 1 && valor > no->esquerda->dado) {
        no->esquerda = rotacaoEsquerda(no->esquerda);
        return rotacaoDireita(no);
    }

    if (balance < -1 && valor < no->direita->dado) {
        no->direita = rotacaoDireita(no->direita);
        return rotacaoEsquerda(no);
    }

    return no;
}

// Fun��o de busca com contagem de passos
void buscar(NO* raiz, int valor) {
    int passos = 0;
    while (raiz != NULL) {
        passos++;
        if (valor == raiz->dado) {
            printf("\nValor %d encontrado ap�s %d passo(s).\n", valor, passos);
            system("pause");
            system("cls");
            return;
        } else if (valor < raiz->dado) {
            raiz = raiz->esquerda;
        } else {
            raiz = raiz->direita;
        }
    }
    printf("\nValor %d N�O encontrado ap�s %d passo(s).\n", valor, passos);
    system("pause");
    system("cls");
}

// Fun��o principal
int main() {
    setlocale(LC_ALL,"Portuguese");
    NO* raiz = NULL;
    int valores[] = {13, 70, 60, 39, 66, 55, 50, 42};
    int tamanho = sizeof(valores) / sizeof(valores[0]);

    // Inserindo os valores na AVL
    for (int i = 0; i < tamanho; i++) {
        raiz = inserir(raiz, valores[i]);
    }

    int busca;
    printf("Digite um valor para buscar na �rvore AVL (0 para sair): ");
    while (scanf("%d", &busca) && busca != 0) {
        buscar(raiz, busca);
        printf("\nDigite outro valor para buscar (ou 0 para sair): ");
    }

    return 0;
}
