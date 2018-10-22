#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{
    Lista *lsta, *lsta1, *lsta2;
    int a, b=15, i, c=15;
    char s;
    lsta = cria_lista();
    lsta1 = cria_lista();
    lsta2 = cria_lista();
    if(lista_vazia(lsta)==1)printf("lista 1 vazia\n");
    if(lista_cheia(lsta)==1) printf("a lista 1 esta cheia\n");
    if(lista_vazia(lsta1)==1)printf("lista 2 pronta\n");
    if(lista_cheia(lsta1)==1) printf("a lista 2 esta cheia\n");
    if(lista_vazia(lsta2)==1)printf("lista 3 pronta\n");
    if(lista_cheia(lsta2)==1) printf("a lista 3 esta cheia\n");
    

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
        insere_ord(lsta, a);
    }
    printf("Deseja remover algum elemento? (Y/N)");
    setbuf(stdin, NULL);
    do{scanf("%c", &s);}while(s!='y' && s!= 'Y' && s!= 'N' && s != 'n');
    if(s=='y' || s== 'Y')
    {
        printf("Escolha o elemento: ");
        scanf("%d", &a);
        remove_ord(lsta, a);
    }
    printf("Lista: \n");
    printar(lsta);
    printf("\n");

    printf("Deseja remover algum elemento (da lista inteira)? (Y/N)");
    setbuf(stdin, NULL);
    do{scanf("%c", &s);}while(s!='y' && s!= 'Y' && s!= 'N' && s != 'n');
    if(s=='y' || s== 'Y')
    {
        printf("Escolha o elemento: ");
        scanf("%d", &a);
        remove_todos(lsta, a);
    }

    printf("Deseja remover os numeros pares? (Y/N)");
    setbuf(stdin, NULL);
    do{scanf("%c", &s);}while(s!='y' && s!= 'Y' && s!= 'N' && s != 'n');
    if(s=='y' || s== 'Y') remove_par(lsta);


        printf("\n-------------------\n");
        printf("Lista 1: {  ");
        printar(lsta);
        printf("}\n-------------------\n");
        printf("MAIOR: %d\n",maior(lsta) );
        printf("\n-------------------\n");
        printf("Tamanho: %d\n",tamanho(lsta) );

    printf("Deseja criar uma segunda Lista?? (Y/N)");
    setbuf(stdin, NULL);
    do{scanf("%c", &s);}while(s!='y' && s!= 'Y' && s!= 'N' && s != 'n');
    if(s=='y' || s== 'Y')
    {

        do{
        printf("Quantos elementos na lista 2? (MAX 10) ");
        scanf("%d", &b);
            }while(b>10);

        for(i=0; i<b; i++){
        printf("digite o elemento %d da lista 2: ", i+1);
        scanf("%d", &a);
        insere_ord(lsta1, a);
                            }

        printf("Deseja comparar as Listas?? (Y/N)");
        setbuf(stdin, NULL);
        do{scanf("%c", &s);}while(s!='y' && s!= 'Y' && s!= 'N' && s != 'n');
        if(s=='y' || s== 'Y')
                {
            if(compara(lsta,lsta1)) printf("As Listas sao iguais\n");
            else printf("As Listas sao diferentes\n");

                }






        printf("Deseja concatenar a primeira lista com a  segunda lista?? (Y/N)");
        setbuf(stdin, NULL);
        do{scanf("%c", &s);}while(s!='y' && s!= 'Y' && s!= 'N' && s != 'n');
        if(s=='y' || s== 'Y'){
        lsta2 = intercala_ord(lsta, lsta1);

        printf("\n-------------------\n");
        printf("Lista 1: {  ");
        printar(lsta);
        printf("}\n-------------------\n");
        printf("Lista 2: {  ");
        printar(lsta1);
        printf("}\n-------------------\n");
        printf("Lista 3: {  ");
        printar(lsta2);
        printf("}\n-------------------\n");
        printf("MAIOR: %d\n",maior(lsta2) );
        printf("\n-------------------\n");
        printf("Tamanho: %d\n",tamanho(lsta2) );
        } 


        printf("Deseja remover os numeros pares da nova lista? (Y/N)");
        setbuf(stdin, NULL);
        do{scanf("%c", &s);}while(s!='y' && s!= 'Y' && s!= 'N' && s != 'n');
        if(s=='y' || s== 'Y') {
        remove_par(lsta2);
        printf("Lista 3: {  ");
        printar(lsta2);
        printf("}\n-------------------\n");
        printf("MAIOR: %d\n",maior(lsta2) );
        printf("\n-------------------\n");
        printf("Tamanho: %d\n",tamanho(lsta2) );
        }

        }else{
        printf("\n-------------------\n");
        printf("Lista 1: {  ");
        printar(lsta);
        printf("}\n-------------------\n");
        printf("MAIOR: %d\n",maior(lsta) );
        printf("\n-------------------\n");
        printf("Tamanho: %d\n",tamanho(lsta) );

    }



    return 0;
}
