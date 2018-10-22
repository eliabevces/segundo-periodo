#define MAX 30
#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

struct lista
{
    int no[MAX];
    int Fim;
};

Lista* cria_lista()
{
    Lista *lst;
    lst = (Lista*) malloc(sizeof(Lista));
    if (lst != NULL)
        lst->Fim = 0; // Lista  vazia
    return lst;
}

int lista_vazia(Lista *lst)
{
    if (lst->Fim == 0)
        return 1;
// Lista vazia
    else
        return 0;
// Lista NÃO vazia
}

int lista_cheia(Lista *lst)
{
    if (lst->Fim == MAX)
        return 1;
// Lista cheia
    else
        return 0;
// Lista NÃO cheia
}

int insere_elem(Lista *lst, int elem)
{
    if (lst == NULL || lista_cheia(lst) == 1)
        return 0;
    lst->no[lst->Fim] = elem;
// Insere elemento
    lst->Fim++;
// Avança o Fim
    return 1;
}

int remove_elem (Lista *lst, int elem)
{
    if (lst == NULL || lista_vazia(lst) == 1)
        return 0;
// Falha
    int i, Aux = 0;
    while(Aux < lst->Fim && lst->no[Aux] != elem)
        Aux++;
    if (Aux == lst->Fim)
// Final de lista (elem)
        return 0;
// Falha
// Deslocamento à esq. do sucessor até o final da lista
    for (i = Aux+1; i < lst->Fim; i++)
        lst->no[i-1] = lst->no[i];
    lst->Fim--;
// Decremento do campo Fim
    return 1;
// Sucesso
}


int printar(Lista *lst){
    int i;
    for(i=0;i<lst->Fim;i++){
        printf("%d  ", lst->no[i]);
    }
}

int remove_todos(Lista *lst, int elem){
    int i;
    if (lst == NULL || lista_vazia(lst) == 1)
        return 0;
    for(i=0;i<lst->Fim;i++){
            remove_elem (lst,elem);
            if(remove_elem (lst,elem)) --i;
    }
return 1;
}

int add_inicius(Lista *lst, int elem, int tam){
    int i;

    if (lst == NULL || lista_vazia(lst) == 1)
        return 0;

    for(i=tam;i>-1;i--){
        lst->no[i]= lst->no[i-1];
    }
    lst->no[0]= elem;
    lst->Fim++;
    return 1;
}

int remove_impar(Lista *lst){
    int i;
    if (lst == NULL || lista_vazia(lst) == 1)
        return 0;
    for(i=0;i<lst->Fim;i++){
        if(lst->no[i]%2){
            remove_elem(lst, lst->no[i]);
            i=i-1;
    }
}
    return 1;
}

int menor_elem(Lista *lst){
    int men, i;
    men = lst->no[0];
    for(i=0;i<lst->Fim;i++){
        if(lst->no[i]<men) men = lst->no[i];
    }

     printf("O menor elemento da lista eh %d\n", men);
}

int tamanho(Lista *lst){
    printf("Tamanho: %d\n", lst->Fim);
}


Lista* concatena(Lista *lst, Lista *lst1){
    Lista *lstcon;
    int i,a;
    lstcon = cria_lista();
    for(i=0;i<lst->Fim;i++){
        insere_elem(lstcon, lst->no[i]);
    }
    for(i=0;i<lst1->Fim;i++){
        insere_elem(lstcon, lst1->no[i]);
    }
    return lstcon;
}