#include <stdio.h>
#include <locale.h>

int buscarNaArvore(int arvore[], int valor, int tamanho) {
    int indiceAtual = 0;  // come�a na raiz
    int encontrado = -1;  // -1 indica que n�o achou
    int passos = 0;

    while (encontrado == -1 && indiceAtual < tamanho) { //se o �ndice for maior que 7, encerra o while
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
    // Vetor representando a �rvore bin�ria de busca
    int arvore[] = {50, 30, 70, 20, 40, 60, 80}; //o tamanho do vetor � igual a quant. de dados declarados
    int tamanho = sizeof(arvore) / sizeof(arvore[0]); //arvore tem 28 bytes / 4 bytes de arvore[0] = 7, ou seja, 7 n�meros no vetor 

    int valorProcurado;
    printf("Digite o valor que deseja buscar: ");
    scanf("%d", &valorProcurado);

    int resultado = buscarNaArvore(arvore, valorProcurado, tamanho);

    if (resultado != -1) {
        printf("Valor %d encontrado no �ndice %d do vetor (posi��o da �rvore).\n", valorProcurado, resultado);
    } else {
        printf("Valor %d n�o encontrado na �rvore.\n", valorProcurado);
    }

    return 0;
}
