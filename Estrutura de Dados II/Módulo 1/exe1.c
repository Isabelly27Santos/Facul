#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define TAMANHO 100
#define ESQUERDA 0
#define DIREITA 1
#define RAIZ -1

// Estrutura do n�
struct No {
    char letra;
    int esquerda;  // �ndice do filho esquerdo
    int direita;   // �ndice do filho direito
    int pai;       // �ndice do pai
};

// Vetor da �rvore
struct No arvore[TAMANHO];
int proximoIndice = 0;

// Fun��o para buscar um n� pelo caractere
int buscarIndice(char letra) {
    for (int i = 0; i < proximoIndice; i++) {
        if (arvore[i].letra == letra) {
            return i;
        }
    }
    return -1; // n�o encontrado
}

// Fun��o para inserir um n� novo
void inserirNo(int indicePai, char letra, int lado) {
    if (proximoIndice >= TAMANHO) {
        wprintf("Erro: �rvore cheia!\n");
        return;
    }

    if (lado == ESQUERDA && arvore[indicePai].esquerda != -1) {
        wprintf("Erro: o n� '%c' j� possui um filho � esquerda.\n", arvore[indicePai].letra);
        return;
    }

    if (lado == DIREITA && arvore[indicePai].direita != -1) {
        wprintf("Erro: o n� '%c' j� possui um filho � direita.\n", arvore[indicePai].letra);
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

// Exibe os n�s existentes e o menu
void mostrarMenu() {
    system("cls || clear"); // compat�vel com Windows e Linux
    wprintf("N�S ATUAIS NA �RVORE: ");
    for (int i = 0; i < proximoIndice; i++) {
        wprintf("%c - %d; ", arvore[i].letra);
    }
    wprintf("\n\n==== MENU ====\n");
    wprintf("1 - Inserir um N� na �rvore\n");
    wprintf("2 - Pesquisar um N� na �rvore\n");
    wprintf("0 - Sair\n\n");
}

// Fun��o principal
int main() {
    setlocale(LC_ALL, "Portuguese");

    int opcao, lado, indicePai;
    char letraPai, letraNo;

    do {
        mostrarMenu();
        wprintf("Escolha uma op��o: ");
        scanf("%d", &opcao);
        getchar(); // limpa o '\n' do buffer

        switch (opcao) {
            case 1:
                wprintf("\nDigite a letra do PAI (ou qualquer letra se for a RAIZ): ");
                scanf(" %c", &letraPai);

                wprintf("Digite a letra do N� que ser� inclu�do: ");
                scanf(" %c", &letraNo);

                wprintf("Digite o lado (Esquerda=%d / Direita=%d / Raiz=%d): ", ESQUERDA, DIREITA, RAIZ);
                scanf("%d", &lado);

                if (lado == RAIZ && proximoIndice == 0) {
                    inserirNo(-1, letraNo, RAIZ);
                } else if (lado != RAIZ) {
                    indicePai = buscarIndice(letraPai);
                    if (indicePai == -1) {
                        wprintf("Erro: PAI '%c' n�o encontrado.\n", letraPai);
                        system("pause");
                    } else {
                        inserirNo(indicePai, letraNo, lado);
                        system("pause");
                    }
                } else {
                    wprintf("Erro: Raiz j� existe.\n");
                    system("pause");
                }
                break;

            case 2:
                wprintf("Digite a letra do N� a ser buscado: ");
                scanf(" %c", &letraNo);

                indicePai = buscarIndice(letraNo);
                if (indicePai == -1) {
                    wprintf("N� n�o encontrado.\n");
                } else {
                    wprintf("\nN� encontrado: %c\n", arvore[indicePai].letra);

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
                wprintf("Op��o inv�lida!\n");
                system("pause");
        }

    } while (opcao != 0);

    return 0;
}
