#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

// Definindo a estrutura do n� da lista encadeada
typedef struct Node {
    int valor;
    struct Node* proximo;
} Node;

typedef Node* Lista; //ponteiro que aponta para o primeiro n�

// Prot�tipos das fun��es
void mostrar_menu();
void executar_opcao(int opcao);
void inserir_no_final(Lista lista);
void remover_item(Lista lista);
void mostrar_lista(Lista lista);

// Vari�veis globais
Lista listaPrincipal;
int opcao;

// Fun��o principal
int main() {
    srand(time(NULL));  // Inicializa gerador de n�meros aleat�rios
    opcao = 1;

    // Criando o n� inicial (cabe�a da lista)
    listaPrincipal = (Lista) malloc(sizeof(Node)); //alocando mem�ria
    listaPrincipal->valor = 0;
    listaPrincipal->proximo = NULL;

    // Loop do menu at� o usu�rio decidir sair
    while (opcao != 0) {
        system("cls");  // Limpa tela (funciona no Windows)
        mostrar_menu();
        scanf("%d", &opcao);
        executar_opcao(opcao);
    }

    system("pause");
    return 0;
}

// Exibe o menu e a lista atual
void mostrar_menu() {
    mostrar_lista(listaPrincipal);
    printf("\n\nEscolha uma das op��es:\n");
    printf("1 - Inserir no final da lista\n");
    printf("2 - Remover um item da lista\n");
    printf("0 - Sair\n\n");
}

// Chama a fun��o correspondente � op��o do menu
void executar_opcao(int opcao) {
    switch (opcao) {
        case 1:
            inserir_no_final(listaPrincipal);
            break;
        case 2:
            remover_item(listaPrincipal);
            break;
        default:
            break;
    }
}

// Insere um novo n� com valor aleat�rio no final da lista
void inserir_no_final(Lista lista) {
    while (lista->proximo != NULL) {
        lista = lista->proximo; //faz com que lista aponte para o �ltimo n�
    }

    lista->proximo = (Lista) malloc(sizeof(Node));
    lista = lista->proximo;
    lista->valor = rand() % 100;  // Valor aleat�rio entre 0 e 99
    lista->proximo = NULL;
}

// Remove o n� com valor igual ao digitado pelo usu�rio
void remover_item(Lista lista) {
    int valor_procurado;
    Node* anterior = lista;
    Node* atual = lista->proximo;

    printf("\n\nDigite o valor que deseja remover: ");
    scanf("%d", &valor_procurado);

    while (atual != NULL && atual->valor != valor_procurado) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual != NULL) {
        anterior->proximo = atual->proximo;
        free(atual);  // Libera a mem�ria do n� removido
        printf("\nValor %d removido da lista.\n", valor_procurado);
    } else {
        printf("\nValor %d n�o encontrado na lista.\n", valor_procurado);
    }

    system("pause");
}

// Mostra todos os elementos da lista
void mostrar_lista(Lista lista) {
    system("cls");
    printf("Conte�do da lista: [ ");

    while (lista != NULL) {
        printf("%d ", lista->valor);
        lista = lista->proximo;
    }

    printf("]");
}
