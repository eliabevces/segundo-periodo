#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{
    Lista *lsta, *lsta1, *lstacon;
    int a, b=15, i, menor;
    char s;
    lsta = cria_lista();
    lsta1 = cria_lista();
    lstacon = cria_lista();

    if(lista_vazia(lsta)==1)printf("lista 1 pronta\n");
    if(lista_cheia(lsta)==1) printf("a lista 1 esta cheia\n");
    if(lista_vazia(lsta1)==1)printf("lista 2 pronta\n");
    if(lista_cheia(lsta1)==1) printf("a lista 2 esta cheia\n");
    if(lista_vazia(lstacon)==1)printf("lista 3 pronta\n");
    if(lista_cheia(lstacon)==1) printf("a lista 3 esta cheia\n");

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
        insere_elem(lsta, a);
    }


    printf("Deseja adicionar algum elemento ao inicio da lista? (Y/N)");
    setbuf(stdin, NULL);
    do{scanf("%c", &s);}while(s!='y' && s!= 'Y' && s!= 'N' && s != 'n');
    if(s=='y' || s== 'Y')
    {
        printf("Escolha o elemento: ");
        scanf("%d", &a);
        add_inicius(lsta, a, b);
    }


    printf("Deseja remover algum elemento? (Y/N)");
    setbuf(stdin, NULL);
    do{scanf("%c", &s);}while(s!='y' && s!= 'Y' && s!= 'N' && s != 'n');
    if(s=='y' || s== 'Y')
    {
        printf("Escolha o elemento: ");
        scanf("%d", &a);
        remove_elem(lsta, a);
    }

    printf("Deseja remover algum elemento? (da lista inteira) (Y/N)");
    setbuf(stdin, NULL);
    do{scanf("%c", &s);}while(s!='y' && s!= 'Y' && s!= 'N' && s != 'n');
    if(s=='y' || s== 'Y')
    {
        printf("Escolha o elemento: ");
        scanf("%d", &a);
        remove_todos(lsta, a);
    }

    printf("Deseja remover os numeros impares? (Y/N)");
    setbuf(stdin, NULL);
    do{scanf("%c", &s);}while(s!='y' && s!= 'Y' && s!= 'N' && s != 'n');
    if(s=='y' || s== 'Y') remove_impar(lsta);
    
    printf("Lista: {  ");
    printar(lsta);
    printf("}\n-------------------\n");

    menor_elem(lsta);

    printf("\n-------------------\n");

    tamanho(lsta);

    printf("\n-------------------\n");

    printf("Deseja concatenar com outra lista? (Y/N)");
    setbuf(stdin, NULL);
    do{scanf("%c", &s);}while(s!='y' && s!= 'Y' && s!= 'N' && s != 'n');
    if(s=='y' || s== 'Y')
    {
        do{
        printf("Quantos elementos na segunda lista? (MAX 10) ");
        scanf("%d", &b);
    }
    while(b>10);
    for(i=0; i<b; i++)
    {
        printf("digite os elementos: ");
        scanf("%d", &a);
        insere_elem(lsta1, a);
    }

    lstacon = concatena(lsta,lsta1);

    printf("\n-------------------\n");
    printf("Lista 1: {  ");
    printar(lsta);
    printf("}\n-------------------\n");
    printf("Lista 2: {  ");
    printar(lsta1);
    printf("}\n-------------------\n");
    printf("Lista 3: {  ");
    printar(lstacon);
    printf("}\n-------------------\n");

    }

    return 0;
}
