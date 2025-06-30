#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define tamanho 5 //tamanho da pilha

struct pilha_livros {
  int codigo[tamanho]; 
  char titulo[tamanho][30]; // um t�tulo por posi��o
  char autor[tamanho][30];  // um autor por posi��o
  int inicio;
  int fim;  
};

struct pilha_livros livros; //vari�veis globais
int op = 1;

// Prot�tipos
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
    wprintf("\nA pilha est� cheia, imposs�vel empilhar!\n\n");
    system("pause");      
  } else {    
    wprintf("\nDigite o c�digo do livro: ");        
    scanf(" %d", &livros.codigo[livros.fim]);  

    // Limpar o buffer ap�s scanf
    while ((ch = getchar()) != '\n' && ch != EOF);

    wprintf("Digite o t�tulo do livro: ");        
    fgets(livros.titulo[livros.fim], sizeof(livros.titulo[livros.fim]), stdin);
    livros.titulo[livros.fim][strcspn(livros.titulo[livros.fim], "\n")] = '\0';

    wprintf("Digite o autor do livro: ");        
    fgets(livros.autor[livros.fim], sizeof(livros.autor[livros.fim]), stdin);
    livros.autor[livros.fim][strcspn(livros.autor[livros.fim], "\n")] = '\0';

    livros.fim++;  
    wprintf("\n\nLivro adicionado com sucesso!!\n\n\n");
    system("pause");  
  }        
}

void remover_livros() {
  if (livros.inicio == livros.fim) {
    wprintf("\nA pilha est� vazia, imposs�vel desempilhar!\n\n");
    system("pause");      
  } else {
    livros.fim--; // aponta para o �ltimo
    wprintf("\n\nLivro \"%s\" removido com sucesso!!\n\n\n", livros.titulo[livros.fim]);

    // Zera os dados (opcional, s� para limpeza visual)
    livros.codigo[livros.fim] = 0;
    livros.titulo[livros.fim][0] = '\0';
    livros.autor[livros.fim][0] = '\0';

    system("pause");        
  }  
}

void exibir_livros() {         
  if (livros.inicio == livros.fim) {
    wprintf("\nA pilha est� vazia!\n");
  } else {
    for (int i = livros.fim - 1; i >= livros.inicio; i--) {
      wprintf("\nC�digo: %d", livros.codigo[i]);      
      wprintf("\nT�tulo: %s", livros.titulo[i]);
      wprintf("\nAutor: %s", livros.autor[i]);
      wprintf("\n_____________________________________\n");
    }   
  }
  system("pause");
}

void exibir_menu() {
  wprintf("\nEscolha uma op��o:\n");        
  wprintf("1 - Adicionar novo livro na pilha\n");            
  wprintf("2 - Remover livro da pilha\n");     
  wprintf("3 - Exibir livros empilhados\n");          
  wprintf("0 - Sair\n\n");          
}
