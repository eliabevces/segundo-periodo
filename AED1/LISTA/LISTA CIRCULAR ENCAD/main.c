#include "lista.h"

int main(){
	Lista lsta, lsta1 , lstacon;
    int a, b, i,pos;
    char s;
    lsta = cria_lista();
    lsta1 = cria_lista();
    lstacon = cria_lista();

    if(lista_vazia(lsta)==1)printf("lista 1 pronta \n");
    if(lista_vazia(lsta1)==1)printf("lista 2 pronta\n");
    if(lista_vazia(lstacon)==1)printf("lista 3 pronta\n");

    printf("Deseja inserir no final da lista? (Y/N)");
    setbuf(stdin, NULL);
    do{scanf("%c", &s);}while(s!='y' && s!= 'Y' && s!= 'N' && s != 'n');
    if(s=='y' || s== 'Y')
    {
    printf("Quantos elementos na lista? ");
    scanf("%d", &b);

    for(i=0; i<b; i++)
    {
        printf("digite os elementos: ");
        scanf("%d", &a);
        insere_final(&lsta, a);
    }

    printf("\n-------------------\n");
    printar(lsta);
    printf("TAMANHO: %d\n", tamanho(&lsta));
    printf("\n-------------------\n");
    printf("MAIOR: %d\n", maior(&lsta));
    printf("\n-------------------\n");
    }

    printf("Deseja inserir no inicio da lista? (Y/N)");
    setbuf(stdin, NULL);
    do{scanf("%c", &s);}while(s!='y' && s!= 'Y' && s!= 'N' && s != 'n');
    if(s=='y' || s== 'Y')
    {
    printf("Quantos elementos na lista? ");
    scanf("%d", &b);

    for(i=0; i<b; i++)
    {
        printf("digite os elementos: ");
        scanf("%d", &a);
        insere_inicio(&lsta, a);
    }
    printf("\n-------------------\n");
    printar(lsta);
    printf("TAMANHO: %d\n", tamanho(&lsta));
    printf("\n-------------------\n");
    printf("MAIOR: %d\n", maior(&lsta));
    printf("\n-------------------\n");

    }

    printf("Deseja inserir em uma posicao especifica da lista? (Y/N)");
    setbuf(stdin, NULL);
    do{scanf("%c", &s);}while(s!='y' && s!= 'Y' && s!= 'N' && s != 'n');
    if(s=='y' || s== 'Y')
    {   
        do{
        printf("escolha a posicao desejada: \n");
        scanf("%d", &pos);
        }while(pos>tamanho(&lsta));

        printf("digite o elemento: ");
        scanf("%d", &a);
        
        insere_n(&lsta, a, pos);
    printf("\n-------------------\n");
    printar(lsta);
    printf("TAMANHO: %d\n", tamanho(&lsta));
    printf("\n-------------------\n");
    printf("MAIOR: %d\n", maior(&lsta));
    printf("\n-------------------\n");

    }


    printf("Deseja remover o inicio da lista? (Y/N)");
    setbuf(stdin, NULL);
    do{scanf("%c", &s);}while(s!='y' && s!= 'Y' && s!= 'N' && s != 'n');
    if(s=='y' || s== 'Y')
    {
        remove_inicio(&lsta, &a);
    printf("\n-------------------\n");
    printar(lsta);
    printf("REMOVIDO: %d\n", a);
    printf("\n-------------------\n");
    printf("TAMANHO: %d\n", tamanho(&lsta));
    printf("\n-------------------\n");
    printf("MAIOR: %d\n", maior(&lsta));
    printf("\n-------------------\n");

    }

    printf("Deseja remover uma posicao especifica da lista? (Y/N)");
    setbuf(stdin, NULL);
    do{scanf("%c", &s);}while(s!='y' && s!= 'Y' && s!= 'N' && s != 'n');
    if(s=='y' || s== 'Y')
    {   
        do{
        printf("escolha a posicao desejada: \n");
        scanf("%d", &pos);
        }while(pos>tamanho(&lsta));

        remove_n(&lsta, pos);
    printf("\n-------------------\n");
    printar(lsta);
    printf("TAMANHO: %d\n", tamanho(&lsta));
    printf("\n-------------------\n");
    printf("MAIOR: %d\n", maior(&lsta));
    printf("\n-------------------\n");

    }


    

return 0;
}