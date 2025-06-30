#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define tamanho 5 //tamanho da pilha

struct pilha_livros {
  int codigo[tamanho]; 
  char titulo[tamanho][30]; // um título por posição
  char autor[tamanho][30];  // um autor por posição
  int inicio;
  int fim;  
};

struct pilha_livros livros; //variáveis globais
int op = 1;

// Protótipos
void adicionar_livros();
void remover_livros();
void exibir_livros();
void exibir_menu();

int main(){
  setlocale(LC_ALL, "Portuguese");    
  livros.inicio = 0;
  livros.fim = 0;
  while (op != 0) {
    system("cls");  
    exibir_menu();
    scanf(" %d", &op);
    switch (op) {
      case 1:
        adicionar_livros();
        break;
      case 2:
        remover_livros();
        break;
      case 3:
        exibir_livros();
        break;
    }      
  }  
  return 0;
}

void adicionar_livros(){
  int ch;
  if (livros.fim == tamanho) {
    printf("\nA pilha está cheia, impossível empilhar!\n\n");
    system("pause");      
  } else {    
    printf("\nDigite o código do livro: ");        
    scanf(" %d", &livros.codigo[livros.fim]);  

    // Limpar o buffer após scanf
    while ((ch = getchar()) != '\n' && ch != EOF);

    printf("Digite o título do livro: ");        
    fgets(livros.titulo[livros.fim], sizeof(livros.titulo[livros.fim]), stdin);
    livros.titulo[livros.fim][strcspn(livros.titulo[livros.fim], "\n")] = '\0';

    printf("Digite o autor do livro: ");        
    fgets(livros.autor[livros.fim], sizeof(livros.autor[livros.fim]), stdin);
    livros.autor[livros.fim][strcspn(livros.autor[livros.fim], "\n")] = '\0';

    livros.fim++;  
    printf("\n\nLivro adicionado com sucesso!!\n\n\n");
    system("pause");  
  }        
}

void remover_livros() {
  if (livros.inicio == livros.fim) {
    printf("\nA pilha está vazia, impossível desempilhar!\n\n");
    system("pause");      
  } else {
    livros.fim--; // aponta para o último
    printf("\n\nLivro \"%s\" removido com sucesso!!\n\n\n", livros.titulo[livros.fim]);

    // Zera os dados (opcional, só para limpeza visual)
    livros.codigo[livros.fim] = 0;
    livros.titulo[livros.fim][0] = '\0';
    livros.autor[livros.fim][0] = '\0';

    system("pause");        
  }  
}

void exibir_livros() {         
  if (livros.inicio == livros.fim) {
    printf("\nA pilha está vazia!\n");
  } else {
    for (int i = livros.fim - 1; i >= livros.inicio; i--) {
      printf("\nCódigo: %d", livros.codigo[i]);      
      printf("\nTítulo: %s", livros.titulo[i]);
      printf("\nAutor: %s", livros.autor[i]);
      printf("\n_____________________________________\n");
    }   
  }
  system("pause");
}

void exibir_menu() {
  printf("\nEscolha uma opção:\n");        
  printf("1 - Adicionar novo livro na pilha\n");            
  printf("2 - Remover livro da pilha\n");     
  printf("3 - Exibir livros empilhados\n");          
  printf("0 - Sair\n\n");          
}
