#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define tamanho 5

struct str_fila {
  int nome[tamanho];
  int inicio;
  int fim;  
};

struct str_fila fila;
int op=1;

//Protipação
void fila_entrar();
void fila_sair();
void fila_mostrar();
void exibir_menu();
 
//Função principal
int main(){
  setlocale(LC_ALL, "Portuguese");    
  fila.inicio = 0;
  fila.fim = 0;
  while (op != 0) {
        system("cls");  
        fila_mostrar();
        exibir_menu();
        scanf(" %d", &op);
        switch (op) {
        case 1:
            fila_entrar();
            break;
        case 2:
            fila_sair();
            break;
        }      
    }  
    return(0);
}
 
//Adicionar um elemento no final da Fila
void fila_entrar(){
  if (fila.fim == tamanho) {
        wprintf("\nA fila está cheia, volte outro dia!\n\n");          
        system("pause");      
    }  
  else {    
        wprintf("\nDigite o valor a ser inserido: ");        
        scanf(" %d", &fila.nome[fila.fim]);  
        fila.fim++;  
    }  
}

//Retirar o primeiro elemento da Fila
void fila_sair() {
  if (fila.inicio == fila.fim) {
        wprintf("\nFila vazia, mas logo aparece alguém!\n\n");          
        system("pause");      
    }          
  else {
        for (int i = 0; i < tamanho; i++) {
          fila.nome[i] = fila.nome[i+1];          
        }  
        fila.nome[fila.fim] = 0;
        fila.fim--;
    }  
}

//Mostrar o conteúdo da Fila
void fila_mostrar() {
  wprintf("[  ");        
  for (int i = 0; i < tamanho; i++) {
        wprintf("%d  ", fila.nome[i]);          
   }
  wprintf("]\n\n");        
}

//Mostrar o menu de opções
void exibir_menu() {
  wprintf("\nEscolha uma opção:\n");        
  wprintf("1 - Incluir na Fila\n");            
  wprintf("2 - Excluir da Fila\n");   
  wprintf("0 - Sair\n\n");           
}
     