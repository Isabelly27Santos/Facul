#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <locale.h>
#define tamanho 5 //tamanho da pilha

struct str_pilha {
  int dados[tamanho]; 
  int inicio;
  int fim;  
};

struct str_pilha pilha; //variáveis globais
int op=1;

//Protipação
void adicionar_livros();
void remover_livros();
void exibir_livros();
void exibir_menu();

//Função principal
int main(){
  setlocale(LC_ALL, "Portuguese");    
  pilha.inicio = 0;
  pilha.fim = 0;
  while (op != 0) {
     system("cls");  
     exibir_livros();
     exibir_menu();
     scanf(" %d", &op);
     switch (op) {
         case 1:
            adicionar_livros();
         break;
         case 2:
           remover_livros();
         break;
        }      
    }  
  return(0);
}

//Adicionar um elemento no final da Pilha
void adicionar_livros(){
  if (pilha.fim == tamanho) {
     printf("\nA pilha está cheia, impossível empilhar!\n\n");
     system("pause");      
   }  
  else {    
     printf("\nDigite o valor a ser empilhado: ");        
     scanf(" %d", &pilha.dados[pilha.fim]);  
     pilha.fim++;  
   }  
}

//Retirar o último elemento da Pilha
void remover_livros() {
  if (pilha.inicio == pilha.fim) {
    printf("\nA pilha está vazia, impossível desempilhar!\n\n");
    system("pause");      
  }          
  else {
    pilha.dados[pilha.fim-1] = 0;
    pilha.fim--;
  }  
}

//Mostrar o conteúdo da Pilha
void exibir_livros() {  
  printf("[  ");        
  for (int i = 0; i < tamanho; i++) {
     printf("%d  ", pilha.dados[i]);          
  }
  printf("]\n\n");        
}

//Mostrar o menu de opções
void exibir_menu() {
  printf("\nEscolha uma opção:\n");        
  printf("1 - Empilhar\n");            
  printf("2 - Desempilhar\n");            
  printf("0 - Sair\n\n");          
}