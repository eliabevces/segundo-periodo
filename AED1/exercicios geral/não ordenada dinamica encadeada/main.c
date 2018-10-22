#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{
    Lista lsta;
    int a, b=15, i;
    char s;
    lsta = cria_lista();
    if(lista_vazia(lsta)==1)printf("vazia\n");

    do
    {
        printf("Quantos elementos na lista? (MAX 10) ");
        scanf("%d", &b);
    }
    while(b>10);
    for(i=0; i<b; i++)
    {
        printf("digite os elementos: ");
        scanf("%d", &a);
        insere_elem(&lsta, a);
    }
    printf("Deseja remover algum elemento? (Y/N)");
    setbuf(stdin, NULL);
    scanf("%c", &s);
    if(s=='y' || s== 'Y')
    {
        printf("Escolha o elemento: ");
        scanf("%d", &a);
        remove_elem(&lsta, a);
    }
    printar(lsta);
    
    return 0;
}
