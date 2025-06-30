#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define TAMANHO 100
#define ESQUERDA 0
#define DIREITA 1
#define RAIZ -1

// Estrutura do nó
struct No {
    char letra;
    int esquerda;  // índice do filho esquerdo
    int direita;   // índice do filho direito
    int pai;       // índice do pai
};

// Vetor da árvore
struct No arvore[TAMANHO];
int proximoIndice = 0;

// Função para buscar um nó pelo caractere
int buscarIndice(char letra) {
    for (int i = 0; i < proximoIndice; i++) {
        if (arvore[i].letra == letra) {
            return i;
        }
    }
    return -1; // não encontrado
}

// Função para inserir um nó novo
void inserirNo(int indicePai, char letra, int lado) {
    if (proximoIndice >= TAMANHO) {
        wprintf("Erro: árvore cheia!\n");
        return;
    }

    if (lado == ESQUERDA && arvore[indicePai].esquerda != -1) {
        wprintf("Erro: o nó '%c' já possui um filho à esquerda.\n", arvore[indicePai].letra);
        return;
    }

    if (lado == DIREITA && arvore[indicePai].direita != -1) {
        wprintf("Erro: o nó '%c' já possui um filho à direita.\n", arvore[indicePai].letra);
        return;
    }

    arvore[proximoIndice].letra = letra;
    arvore[proximoIndice].pai = (lado == RAIZ) ? -1 : indicePai;
    arvore[proximoIndice].esquerda = -1;
    arvore[proximoIndice].direita = -1;

    if (lado == ESQUERDA) {
        arvore[indicePai].esquerda = proximoIndice;
    } else if (lado == DIREITA) {
        arvore[indicePai].direita = proximoIndice;
    }

    proximoIndice++;
}

// Exibe os nós existentes e o menu
void mostrarMenu() {
    system("cls || clear"); // compatível com Windows e Linux
    wprintf("NÓS ATUAIS NA ÁRVORE: ");
    for (int i = 0; i < proximoIndice; i++) {
        wprintf("%c - %d; ", arvore[i].letra);
    }
    wprintf("\n\n==== MENU ====\n");
    wprintf("1 - Inserir um NÓ na árvore\n");
    wprintf("2 - Pesquisar um NÓ na árvore\n");
    wprintf("0 - Sair\n\n");
}

// Função principal
int main() {
    setlocale(LC_ALL, "Portuguese");

    int opcao, lado, indicePai;
    char letraPai, letraNo;

    do {
        mostrarMenu();
        wprintf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // limpa o '\n' do buffer

        switch (opcao) {
            case 1:
                wprintf("\nDigite a letra do PAI (ou qualquer letra se for a RAIZ): ");
                scanf(" %c", &letraPai);

                wprintf("Digite a letra do NÓ que será incluído: ");
                scanf(" %c", &letraNo);

                wprintf("Digite o lado (Esquerda=%d / Direita=%d / Raiz=%d): ", ESQUERDA, DIREITA, RAIZ);
                scanf("%d", &lado);

                if (lado == RAIZ && proximoIndice == 0) {
                    inserirNo(-1, letraNo, RAIZ);
                } else if (lado != RAIZ) {
                    indicePai = buscarIndice(letraPai);
                    if (indicePai == -1) {
                        wprintf("Erro: PAI '%c' não encontrado.\n", letraPai);
                        system("pause");
                    } else {
                        inserirNo(indicePai, letraNo, lado);
                        system("pause");
                    }
                } else {
                    wprintf("Erro: Raiz já existe.\n");
                    system("pause");
                }
                break;

            case 2:
                wprintf("Digite a letra do NÓ a ser buscado: ");
                scanf(" %c", &letraNo);

                indicePai = buscarIndice(letraNo);
                if (indicePai == -1) {
                    wprintf("Nó não encontrado.\n");
                } else {
                    wprintf("\nNó encontrado: %c\n", arvore[indicePai].letra);

                    if (arvore[indicePai].esquerda != -1)
                        wprintf("Filho Esquerdo: %c\n", arvore[arvore[indicePai].esquerda].letra);
                    else
                        wprintf("Filho Esquerdo: (nenhum)\n");

                    if (arvore[indicePai].direita != -1)
                        wprintf("Filho Direito: %c\n", arvore[arvore[indicePai].direita].letra);
                    else
                        wprintf("Filho Direito: (nenhum)\n");
                }
                system("pause");
                break;

            case 0:
                wprintf("Saindo...\n");
                break;

            default:
                wprintf("Opção inválida!\n");
                system("pause");
        }

    } while (opcao != 0);

    return 0;
}
