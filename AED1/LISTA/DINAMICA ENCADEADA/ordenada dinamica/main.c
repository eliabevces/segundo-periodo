
#include "lista.h"

int main(){
    Lista lsta, lsta1, lsta2;
    int a, b, i;
    char s;
    lsta = cria_lista();
    lsta1 = cria_lista();
    lsta2 = cria_lista();
    if(lista_vazia(lsta)==1)printf("vazia\n");

        printf("Quantos elementos na lista?  ");
        scanf("%d", &b);

    for(i=0; i<b; i++)
    {
        printf("digite os elementos: ");
        scanf("%d", &a);
        insere_ord(&lsta, a);
    }
    printf("Deseja remover algum elemento? (Y/N)");
    setbuf(stdin, NULL);
    scanf("%c", &s);
    if(s=='y' || s== 'Y')
    {
        printf("Escolha o elemento: ");
        scanf("%d", &a);
        remove_ord(&lsta, a);
    }


    printf("Deseja remover os numeros impares? (Y/N)");
    setbuf(stdin, NULL);
    do{scanf("%c", &s);}while(s!='y' && s!= 'Y' && s!= 'N' && s != 'n');
    if(s=='y' || s== 'Y'){
    remove_impar(&lsta);
    
    }


        printf("\n-------------------\n");
        printf("Lista 1: {  ");
        printar(&lsta);
        printf("}\n-------------------\n");
        printf("MENOR: %d\n", menor(&lsta));
        printf("}\n-------------------\n");
        printf("TAMANHO: %d\n", tamanho(lsta));
        printf("}\n-------------------\n");
        if(tamanho(lsta)==0){
            printf("Nao eh possivel continuar com uma lista vazia\n");
            return 0;

        }

    printf("Deseja criar uma segunda Lista?? (Y/N)");
    setbuf(stdin, NULL);
    do{scanf("%c", &s);}while(s!='y' && s!= 'Y' && s!= 'N' && s != 'n');
    if(s=='y' || s== 'Y')
    {

        
        printf("Quantos elementos na lista 2? ");
        scanf("%d", &b);
            

        for(i=0; i<b; i++){
        printf("digite o elemento %d da lista 2: ", i+1);
        scanf("%d", &a);
        insere_ord(&lsta1, a);
                            }

        printf("Lista 2: {  ");
        printar(&lsta1);
        printf("}\n-------------------\n");
        printf("MENOR: %d\n", menor(&lsta1));
        printf("}\n-------------------\n");
        printf("TAMANHO: %d\n", tamanho(lsta1));
        printf("}\n-------------------\n");
        if(tamanho(lsta1)==0){
            printf("Nao eh possivel continuar com uma lista vazia\n");
            return 0;

        }

        printf("Deseja comparar as Listas?? (Y/N)");
        setbuf(stdin, NULL);
        do{scanf("%c", &s);}while(s!='y' && s!= 'Y' && s!= 'N' && s != 'n');
        if(s=='y' || s== 'Y')
                {
            if(compara(&lsta,&lsta1)) printf("As Listas sao iguais\n");
            else printf("As Listas sao diferentes\n");

                }






        printf("Deseja concatenar a primeira lista com a  segunda lista?? (Y/N)");
        setbuf(stdin, NULL);
        do{scanf("%c", &s);}while(s!='y' && s!= 'Y' && s!= 'N' && s != 'n');
        if(s=='y' || s== 'Y'){
        lsta2 = concatena(&lsta, &lsta1);

        printf("\n-------------------\n");
        printf("Lista 1: {  ");
        printar(&lsta);
        printf("}\n-------------------\n");
        printf("MENOR: %d\n", menor(&lsta));
        printf("}\n-------------------\n");
        printf("TAMANHO: %d\n", tamanho(lsta));
        printf("}\n-------------------\n");
        if(tamanho(lsta)==0){
            printf("Nao eh possivel continuar com uma lista vazia\n");
            return 0;

        }

        printf("Lista 2: {  ");
        printar(&lsta1);
        printf("}\n-------------------\n");
        printf("MENOR: %d\n", menor(&lsta1));
        printf("}\n-------------------\n");
        printf("TAMANHO: %d\n", tamanho(lsta1));
        printf("}\n-------------------\n");
        if(tamanho(lsta1)==0){
            printf("Nao eh possivel continuar com uma lista vazia\n");
            return 0;

        }

        printf("Lista 3: {  ");
        printar(&lsta2);
        printf("}\n-------------------\n");
        printf("MENOR: %d\n", menor(&lsta2));
        printf("}\n-------------------\n");
        printf("TAMANHO: %d\n", tamanho(lsta2));
        printf("}\n-------------------\n");
        if(tamanho(lsta2)==0){
            printf("Nao eh possivel continuar com uma lista vazia\n");
            return 0;

        }

        } 


        printf("Deseja remover os numeros impares da nova lista? (Y/N)");
        setbuf(stdin, NULL);
        do{scanf("%c", &s);}while(s!='y' && s!= 'Y' && s!= 'N' && s != 'n');
        if(s=='y' || s== 'Y') {
        remove_impar(&lsta2);

        printf("Lista 3: {  ");
        printar(&lsta2);
        printf("}\n-------------------\n");
        printf("MENOR: %d\n", menor(&lsta2));
        printf("}\n-------------------\n");
        printf("TAMANHO: %d\n", tamanho(lsta2));
        printf("}\n-------------------\n");
        if(tamanho(lsta2)==0){
            printf("Nao eh possivel continuar com uma lista vazia\n");
            return 0;

        }

            }

        

    }else{
        printf("\n-------------------\n");
        printf("Lista 1: {  ");
        printar(&lsta);
        printf("}\n-------------------\n");
        printf("MENOR: %d\n", menor(&lsta));
        printf("}\n-------------------\n");
        printf("TAMANHO: %d\n", tamanho(lsta));
        printf("}\n-------------------\n");
        if(tamanho(lsta)==0){
            printf("Nao eh possivel continuar com uma lista vazia\n");
            return 0;

        }

    }
    
    return 0;
}
