#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX_VERTICES 10

// Vari�veis globais
int num_vertices = 0;
int vertices[MAX_VERTICES];
int matriz_adj[MAX_VERTICES][MAX_VERTICES];  // Matriz de adjac�ncia
int opcao = 1;

// Prototipa��o
int definir_tamanho_grafo();
void desenhar_vertices();
void desenhar_matriz();
void inserir_aresta();
void remover_aresta();
void mostrar_menu();

int main() {
    setlocale(LC_ALL, "Portuguese");

    // Definindo o n�mero de v�rtices
    while (num_vertices <= 0 || num_vertices > MAX_VERTICES) {
        num_vertices = definir_tamanho_grafo();

        if (num_vertices <= 0 || num_vertices > MAX_VERTICES) {
            system("cls");
            printf("Escolha um valor entre 1 e %d!\n\n", MAX_VERTICES);
        } else {
            for (int i = 0; i < num_vertices; i++) {
                vertices[i] = i;
            }
        }
    }

    // Loop principal do programa
    while (opcao != 0) {
        system("cls");
        desenhar_vertices();
        desenhar_matriz();
        mostrar_menu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserir_aresta();
                break;
            case 2:
                remover_aresta();
                break;
        }
    }

    system("pause");
    return 0;
}

// Solicita ao usu�rio o n�mero de v�rtices
int definir_tamanho_grafo() {
    int tamanho;
    printf("Digite a quantidade de v�rtices do grafo: ");
    scanf("%d", &tamanho);
    return tamanho;
}

// Mostra os v�rtices na tela
void desenhar_vertices() {
    printf("Lista de v�rtices:\n[ ");
    for (int i = 0; i < num_vertices; i++) {
        printf("%d ", vertices[i]);
    }
    printf("]\n\n");
}

// Mostra a matriz de adjac�ncia (conex�es entre v�rtices)
void desenhar_matriz() {
    int i;
    printf("Matriz de adjac�ncia:\n\n\    ");
    for (i = 0; i < num_vertices; i++){
        printf("%d ", i);
    }
    printf("\n");
    for (i = 0; i < num_vertices; i++){
        printf("---");
    }
    printf("\n");
    for (i= 0; i < num_vertices; i++) {
        printf("%d |",i);
        for (int j = 0; j < num_vertices; j++) {
            printf(" %d", matriz_adj[i][j]);
        }
        printf("\n");
    }
}

// Adiciona uma aresta entre dois v�rtices
void inserir_aresta() {
    int origem, destino;
    system("cls");

    printf("Digite o v�rtice de origem (0 a %d): ", num_vertices - 1);
    scanf("%d", &origem);

    printf("Digite o v�rtice de destino (0 a %d): ", num_vertices - 1);
    scanf("%d", &destino);

    if (origem < 0 || origem >= num_vertices || destino < 0 || destino >= num_vertices) {
        printf("\nValores inv�lidos! Use n�meros entre 0 e %d.\n\n", num_vertices - 1);
        system("pause");
    } else {
        matriz_adj[origem][destino] = 1;
        matriz_adj[destino][origem] = 1; // Grafo n�o direcionado
    }
}

// Remove uma aresta entre dois v�rtices
void remover_aresta() {
    int origem, destino;
    system("cls");

    printf("Digite o v�rtice de origem (0 a %d): ", num_vertices - 1);
    scanf("%d", &origem);

    printf("Digite o v�rtice de destino (0 a %d): ", num_vertices - 1);
    scanf("%d", &destino);

    if (origem < 0 || origem >= num_vertices || destino < 0 || destino >= num_vertices) {
        printf("\nValores inv�lidos! Use n�meros entre 0 e %d.\n\n", num_vertices - 1);
        system("pause");
    } else {
        matriz_adj[origem][destino] = 0;
        matriz_adj[destino][origem] = 0; // Grafo n�o direcionado
    }
}

// Exibe as op��es do menu
void mostrar_menu() {
    printf("\nEscolha uma op��o:\n");
    printf("1 - Inserir aresta\n");
    printf("2 - Remover aresta\n");
    printf("0 - Sair\n\n");
}
