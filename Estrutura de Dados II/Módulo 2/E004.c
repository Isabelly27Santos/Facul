#include <stdio.h>
#include <locale.h>

int buscarNaArvore(int arvore[], int valor, int tamanho) {
    int indiceAtual = 0;  // começa na raiz
    int encontrado = -1;  // -1 indica que não achou
    int passos = 0;

    while (encontrado == -1 && indiceAtual < tamanho) { //se o índice for maior que 7, encerra o while
        if (valor == arvore[indiceAtual]) {
            encontrado = indiceAtual;  // achou o valor
        }
        else if (valor < arvore[indiceAtual]) {
            indiceAtual = (2 * indiceAtual) + 1;  // vai para o filho da esquerda
        }
        else {
            indiceAtual = (2 * indiceAtual) + 2;  // vai para o filho da direita
        }
        passos++;
    }

    return encontrado;
}

int main() {
    setlocale(LC_ALL,"Portuguese");
    // Vetor representando a árvore binária de busca
    int arvore[] = {50, 30, 70, 20, 40, 60, 80}; //o tamanho do vetor é igual a quant. de dados declarados
    int tamanho = sizeof(arvore) / sizeof(arvore[0]); //arvore tem 28 bytes / 4 bytes de arvore[0] = 7, ou seja, 7 números no vetor 

    int valorProcurado;
    printf("Digite o valor que deseja buscar: ");
    scanf("%d", &valorProcurado);

    int resultado = buscarNaArvore(arvore, valorProcurado, tamanho);

    if (resultado != -1) {
        printf("Valor %d encontrado no índice %d do vetor (posição da árvore).\n", valorProcurado, resultado);
    } else {
        printf("Valor %d não encontrado na árvore.\n", valorProcurado);
    }

    return 0;
}
