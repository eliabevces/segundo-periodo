#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(){

 char s[MAX], pos[MAX];
     int n=0,*v,op;
     while(1){
         printf("Quantos literais deseja usar na expressao? ");
         scanf("%d", &n);
         setbuf(stdin,NULL);
         if(n<10) break;
         else system("clear");
     }
     v=(int *)malloc(n*sizeof(int));
     for(int i=0;i<n;i++){
         printf("%c = ", 'A'+i);
         scanf("%d", &v[i]);
         setbuf(stdin,NULL);
     }
     printf("Em qual forma deseja entrar com sua expressao?\n");
    printf("(1)Pos-fixa\t(2)Infixa,escopo completo\t(3)Infixa,escopo eventual\n");
     scanf("%d", &op);
     setbuf(stdin,NULL);
     if(op==1){
         printf("Digite a expressao na forma valida!\n");
         scanf("%s", s);
         if(escopo_valido(s)) printf("Resultado: %d\n",resultado_pos(s) );
     }
     else if(op==2){
         printf("Digite a expressao na forma valida!\n");
         scanf("%s", s);
         if(escopo_valido(s)) infixa_posfixa(s,pos);
         printf("Resultado: %d\n", resultado_pos(s) );
     }
     free(v);
    return 0;
}