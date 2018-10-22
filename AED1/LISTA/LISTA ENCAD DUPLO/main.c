#include "lista.h"
int main(){
	Lista lsta, lsta1;
    int a, b, i;
    char s;
    lsta = cria_lista();

    if(lista_vazia(lsta)==1)printf("lista 1 pronta \n");

    {
        printf("Quantos elementos na lista? ");
        scanf("%d", &b);
    }

    for(i=0; i<b; i++)
    {
        printf("digite os elementos: ");
        scanf("%d", &a);
        insere_elemento(&lsta, a);
    }

    printf("\n-------------------\n");
    printar(lsta);
    printf("\n-------------------\n");
    printf("TAMANHO: %d\n", tamanho(lsta));
    printf("\n-------------------\n");

    printf("Deseja remover algum elemento? (Y/N)");
    setbuf(stdin, NULL);
    do{scanf("%c", &s);}while(s!='y' && s!= 'Y' && s!= 'N' && s != 'n');
    if(s=='y' || s== 'Y')
    {
    	printf("Escolha o elemento: ");
        scanf("%d", &a);
        remove_elemento(&lsta, a);

    }

    printf("Deseja remover algum elemento (da lista completa)? (Y/N)");
    setbuf(stdin, NULL);
    do{scanf("%c", &s);}while(s!='y' && s!= 'Y' && s!= 'N' && s != 'n');
    if(s=='y' || s== 'Y')
    {
        printf("Escolha o elemento: ");
        scanf("%d", &a);
        remove_todos(&lsta, a);

    }

    printf("Deseja remover o maior elemento? (Y/N)");
    setbuf(stdin, NULL);
    do{scanf("%c", &s);}while(s!='y' && s!= 'Y' && s!= 'N' && s != 'n');
    if(s=='y' || s== 'Y')
    {
        remove_maior(&lsta);

    }

    lsta1 = multi3(&lsta);

    printf("\n-------------------\n");
    printar(lsta);
    printf("\n-------------------\n");
    printf("TAMANHO: %d\n", tamanho(lsta));
    printf("\n-------------------\n");
    printf("MULTIPLOS DE 3: \n");
    printar(lsta1);

return 0;
}