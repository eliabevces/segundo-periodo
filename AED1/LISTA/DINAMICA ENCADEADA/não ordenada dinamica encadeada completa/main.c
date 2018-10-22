
#include "lista.h"

int main(int argc, char const *argv[])
{
    Lista lsta, lsta1 , lstacon;
    int a, b=15, i;
    char s;
    lsta = cria_lista();
    lsta1 = cria_lista();
    lstacon = cria_lista();

    if(lista_vazia(lsta)==1)printf("lista 1 pronta \n");
    if(lista_vazia(lsta1)==1)printf("lista 2 pronta\n");
    if(lista_vazia(lstacon)==1)printf("lista 3 pronta\n");
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
    do{scanf("%c", &s);}while(s!='y' && s!= 'Y' && s!= 'N' && s != 'n');
    if(s=='y' || s== 'Y')
    {
        printf("Escolha o elemento: ");
        scanf("%d", &a);
        remove_elem(&lsta, a);
    }

    printf("Deseja remover algum elemento? (da lista inteira) (Y/N)");
    setbuf(stdin, NULL);
    do{scanf("%c", &s);}while(s!='y' && s!= 'Y' && s!= 'N' && s != 'n');
    if(s=='y' || s== 'Y')
    {
        printf("Escolha o elemento: ");
        scanf("%d", &a);
        remove_todas(&lsta, a);
    }

        printf("\n-------------------\n");
        printf("Lista 1: {  ");
        printar(lsta);
        printf("}\n-------------------\n");
        printf("MAIOR: %d\n",maior(&lsta) );
        printf("\n-------------------\n");
        printf("Tamanho: %d\n",tamanho(lsta) );

    
    printf("Deseja deseja inserir um elemento no Final? (Y/N)");
    setbuf(stdin, NULL);
    do{scanf("%c", &s);}while(s!='y' && s!= 'Y' && s!= 'N' && s != 'n');
    if(s=='y' || s== 'Y')
    {
        printf("Escolha o elemento: ");
        scanf("%d", &a);
        insere_fim(&lsta, a);
    }

    printf("Deseja remover os elementos pares? (Y/N)");
    setbuf(stdin, NULL);
    do{scanf("%c", &s);}while(s!='y' && s!= 'Y' && s!= 'N' && s != 'n');
    if(s=='y' || s== 'Y')
    {
        remove_par(&lsta);
    }

    printf("\n-------------------\n");
        printf("Lista 1: {  ");
        printar(lsta);
        printf("}\n-------------------\n");
        printf("MAIOR: %d\n",maior(&lsta) );
        printf("\n-------------------\n");
        printf("Tamanho: %d\n",tamanho(lsta) );



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
        insere_elem(&lsta1, a);
    }

    lstacon = concatena(&lsta,&lsta1);

    printf("\n-------------------\n");
    printf("Lista 1: {  ");
    printar(lsta);
    printf("}\n-------------------\n");
    printf("MAIOR: %d\n",maior(&lsta) );
    printf("\n-------------------\n");
    printf("Tamanho: %d\n",tamanho(lsta) );
    printf("\n-------------------\n");
    printf("Lista 2: {  ");
    printar(lsta1);
    printf("}\n-------------------\n");
    printf("MAIOR: %d\n",maior(&lsta1) );
    printf("\n-------------------\n");
    printf("Tamanho: %d\n",tamanho(lsta1) );
    printf("\n-------------------\n");
    printf("Lista 3: {  ");
    printar(lstacon);
    printf("}\n-------------------\n");
    printf("MAIOR: %d\n",maior(&lstacon) );
    printf("\n-------------------\n");
    printf("Tamanho: %d\n",tamanho(lstacon) );
    
        
    printf("Deseja remover os elementos pares da nova lista? (Y/N)");
    setbuf(stdin, NULL);
    do{scanf("%c", &s);}while(s!='y' && s!= 'Y' && s!= 'N' && s != 'n');
    if(s=='y' || s== 'Y')
    {
        remove_par(&lstacon);
    }

    printf("\n-------------------\n");
        printf("Lista 3: {  ");
        printar(lstacon);
        printf("}\n-------------------\n");
        printf("MAIOR: %d\n",maior(&lstacon) );
        printf("\n-------------------\n");
        printf("Tamanho: %d\n",tamanho(lstacon) );
    }
    return 0;
}


