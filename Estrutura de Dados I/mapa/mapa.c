#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Pilha {
    char itens[MAX_SIZE];
    int topo;
};

void inicializar(struct Pilha *p) {
    p->topo = -1;
}

int vazia(struct Pilha *p) {
    return p->topo == -1;
}

void push(struct Pilha *p, char item) {
    p->topo ++;
    p->itens[p->topo] = item;
}

char pop(struct Pilha *p) {
    if (!vazia(p)) {
        char removido = p->itens[p->topo];
        p->topo--;
        return removido;
        return '\0';
    }
}

char topo(struct Pilha *p) {
    if (vazia(p)) return '\0';
    return (p->itens[p->topo]);
}

void limpar(struct Pilha *p) {
    for (int i = 0; i <= p->topo; i++){
        p->itens[i] = '\0';
    }
    p->topo = -1;
}

int main() {
    setlocale(LC_ALL,"Portuguese");
    struct Pilha p;
    inicializar(&p);

    while (1) {
        printf("\n---------------------MENU---------------------\n");
        printf("\nDigite 1 para adicionar uma palavra � pilha\n");
        printf("Digite 2 para desempilhar a palavra\n");
        printf("Digite 3 para limpar a pilha\n");
        printf("Digite 4 para exibir o topo da pilha\n");
        printf("Digite 0 para sair\n");

        int opcao;
        printf("\nEscolha uma op��o: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                char palavra[MAX_SIZE];
                printf("\nDigite a palavra a ser adicionada: ");
                scanf("%s", palavra);
                for (int i = 0; i < strlen(palavra); i++) {
                    push(&p, palavra[i]);
                }
                printf("\nPalavra '%s' adicionada � pilha.\n", palavra);
                system ("pause");
                system ("cls");
                break;
            }
            case 2: {
                char palavra[MAX_SIZE];
                int indice = 0;
                while (!vazia(&p)) {
                    palavra[indice++] = pop(&p);
                }
                palavra[indice] = '\0';
                if (indice>0) {
                    printf("\nPalavra desempilhada: '%s'\n", palavra);
                } else {
                    printf("\nPilha vazia. Nenhum elemento para mostrar.\n");
                }
                system ("pause");
                system ("cls");
                break;
            }
            case 3: {
                limpar(&p);
                printf("\nPilha limpa.\n");
                system ("pause");
                system ("cls");
                break;
            }
            case 4: {
                char top = topo(&p);
                if (top == '\0') {
                    printf("\nPilha vazia. Nenhum elemento para mostrar.\n");
                } else {
                    printf("\nElemento no topo da pilha: %c\n", top);
                }
                system ("pause");
                system ("cls");
                break;
            }
            case 0: {
                return 0;
            }
            default: {
                printf("\nOp��o inv�lida. Digite 1, 2, 3, 4 ou 0.\n");
            }
        }
    }

    return 0;
}
