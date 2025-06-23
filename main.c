#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main()
{
    int x,i;
    int *ptr1;
    int *ptr2;

    setlocale(LC_ALL,"Portuguese");
    printf("Escolha um tamanho para o vetor: ");
    scanf("%d",&x);
    ptr1=(int*)malloc(sizeof(int)*x);
    ptr2=(int*)malloc(sizeof(int)*(x*2));

    printf("\n\nVetor 1\n");
    for ( i = 0; i < x; i++)
    {
        ptr1[i]=pow(2,i);
        printf("Posição %d: %d \n",i+1,ptr1[i]);
    }
    printf("\nVetor 2\n");
    {
        ptr2[i]=pow(3,i);
        printf("Posição %d: %d \n",i+1,ptr2[i]);
    }
    
    return 0;
}