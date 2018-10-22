#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


int main(){
    Lista lsta;
    int a, b=15, i;
    char s;
    lsta = cria_lista();
    lista_vazia(lsta);
    if(lista_cheia(lsta)==1) printf("a lista esta cheia");

    do {
        printf("Quantos elementos na lista? (MAX 10) ");
        scanf("%d", &b);
}while(b>10);
    for(i=0;i<b;b++) {
        scanf("%d", &a);
        insere_elem(lsta, a);
    }
    /* printf("Deseja remover algum elemento? (Y/N)");
    scanf("%c", s);
    if(s=='y' || s== 'Y') {
        printf("Escolha o elemento: ");
        scanf("%d", a);
        remove_elem(lsta, a);
    }

    insere_ord(lsta, a);
    remove_ord(lsta, a); */
}
