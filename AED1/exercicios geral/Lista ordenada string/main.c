#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#define MAX 10

int main()
{
    Lista *lsta;
    char s, q[MAX];
    lsta = cria_lista();
    printar(lsta);

    do{
        printf("\nDeseja adicionar alguma palavra (Y/N)");
        scanf("%c",&s);
        setbuf(stdin,NULL);
        if(s=='Y' || s=='y'){
            printf("\ndigite o elemento: \n");
            scanf("%[^\n]s", q);
            setbuf(stdin,NULL);
            if(insere_ord(lsta,q)==0)printf("\n--\t--\t--\t--\n");
        }else break;
        }while(1);

    printar(lsta);
   
   char r, f[MAX];

   do{
    setbuf(stdin,NULL);
    printf("Deseja apagar alguma letra??");
    scanf("%c", &r);
    setbuf(stdin,NULL);
    if(r=='Y'||r=='y'){
        printf("qual elemento?");
        scanf("%[^\ns", &f);
        setbuf(stdin,NULL);
        remove_ord(lsta,f);
    }
    printar(lsta);
    }while(r=='y'|| r=='Y');
}
