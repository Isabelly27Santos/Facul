
#include <stdio.h>
#include <stdlib.h>

struct semafaro {
 char cor[10];
 int id;
};
struct semafaro s1 = {"Vermelho", 1};
struct semafaro s2 = {"Amarelo", 2};
struct semafaro s3 = {"Verde", 3};
struct semafaro *ptr_s;
int main(){
 ptr_s = &s1; 
 printf("%d - %s\n", (*ptr_s).id,(*ptr_s).cor); 
 ptr_s = ptr_s + 1;
 printf("%d - %s\n", (*ptr_s).id,(*ptr_s).cor); 
 ptr_s = ptr_s + 1;
 printf("%d - %s\n", (*ptr_s).id,(*ptr_s).cor); 
 system("Pause");
 return(0);
}
