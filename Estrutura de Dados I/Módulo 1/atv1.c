
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    int *ponteiro;
    setlocale(LC_ALL,"Portuguese_Brazil");
    ponteiro=(int*)malloc(sizeof(int));
    if(ponteiro==NULL){
        wprintf("Erro!");
    }
    else{
        *ponteiro=42;
        wprintf("Endereço do ponteiro: %i\nValor: %i\n",&ponteiro,*ponteiro);
    }    
    return 0;
}



