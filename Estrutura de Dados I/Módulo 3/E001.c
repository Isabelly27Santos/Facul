#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

// Definindo a estrutura do nó da lista encadeada
typedef struct Node {
    int valor;
    struct Node* proximo;
} Node;

typedef Node* Lista; //ponteiro que aponta para o primeiro nó

// Protótipos das funções
void mostrar_menu();
void executar_opcao(int opcao);
void inserir_no_final(Lista lista);
void remover_item(Lista lista);
void mostrar_lista(Lista lista);

// Variáveis globais
Lista listaPrincipal;
int opcao;

// Função principal
int main() {
    srand(time(NULL));  // Inicializa gerador de números aleatórios
    opcao = 1;

    // Criando o nó inicial (cabeça da lista)
    listaPrincipal = (Lista) malloc(sizeof(Node)); //alocando memória
    listaPrincipal->valor = 0;
    listaPrincipal->proximo = NULL;

    // Loop do menu até o usuário decidir sair
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
    printf("\n\nEscolha uma das opções:\n");
    printf("1 - Inserir no final da lista\n");
    printf("2 - Remover um item da lista\n");
    printf("0 - Sair\n\n");
}

// Chama a função correspondente à opção do menu
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

// Insere um novo nó com valor aleatório no final da lista
void inserir_no_final(Lista lista) {
    while (lista->proximo != NULL) {
        lista = lista->proximo; //faz com que lista aponte para o último nó
    }

    lista->proximo = (Lista) malloc(sizeof(Node));
    lista = lista->proximo;
    lista->valor = rand() % 100;  // Valor aleatório entre 0 e 99
    lista->proximo = NULL;
}

// Remove o nó com valor igual ao digitado pelo usuário
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
        free(atual);  // Libera a memória do nó removido
        printf("\nValor %d removido da lista.\n", valor_procurado);
    } else {
        printf("\nValor %d não encontrado na lista.\n", valor_procurado);
    }

    system("pause");
}

// Mostra todos os elementos da lista
void mostrar_lista(Lista lista) {
    system("cls");
    printf("Conteúdo da lista: [ ");

    while (lista != NULL) {
        printf("%d ", lista->valor);
        lista = lista->proximo;
    }

    printf("]");
}
