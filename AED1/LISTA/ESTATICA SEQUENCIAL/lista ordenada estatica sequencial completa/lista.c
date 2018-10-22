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


int insere_ord(Lista *lst, int elem)
{
    if (lst == NULL || lista_cheia(lst) == 1)
        return 0;
// Falha
// Trata lista vazia ou elemento ≥ último da lista
    if (lista_vazia(lst) == 1 || elem >= lst->no[lst->Fim-1])
    {
        lst->no[lst->Fim] = elem; // Insere no final
    }
    else
    {
        int i, aux= 0;
        while (elem >= lst->no[aux])
// Percorrimento
            aux++;
        for (i =lst->Fim; i > aux; i--)// Deslocamento
            lst->no[i] = lst->no[i-1];
        lst->no[aux] = elem;
// Inclui o elemento na lista
    }
    lst->Fim++;
// Avança o Fim
    return 1;
}

int remove_ord (Lista *lst, int elem)
{
    if (lst == NULL || lista_vazia(lst) == 1 || elem < lst->no[0] || elem > lst->no[lst->Fim-1])
        return 0;
// Falha
    int i, Aux = 0;
// Percorre até achar o elem ou nó maior, ou final de lista
    while (Aux < lst->Fim && lst->no[Aux] < elem)
        Aux++;
    if (Aux == lst->Fim || lst->no[Aux] > elem)
// elem
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
            remove_ord (lst,elem);
            if(remove_ord (lst,elem)) --i;
    }
return 1;
}



Lista* intercala_ord(Lista *lst, Lista *lst1){
    Lista *lisord;
    int i,a;
    lisord = cria_lista();
    for(i=0;i<lst->Fim;i++){
        insere_ord(lisord, lst->no[i]);
    }
    for(i=0;i<lst1->Fim;i++){
        insere_ord(lisord, lst1->no[i]);
    }
    return lisord;

}

int remove_par(Lista *lst){
    int i;
    if (lst == NULL || lista_vazia(lst) == 1)
        return 0;
    for(i=0;i<lst->Fim;i++){
        if(lst->no[i]%2 == 0){
            remove_ord(lst, lst->no[i]);
            i=i-1;
    }
}
    return 1;
}

int maior(Lista  *lst){
    return lst->no[lst->Fim-1];
}

int tamanho(Lista *lst){
    return lst->Fim;
}

int compara(Lista *lst, Lista *lst1){
    int i;
    if(lst->Fim==lst1->Fim){
        for(i=0;i<lst->Fim;i++){
            if(lst->no[i]==lst1->no[i]) return 1;
            else return 0;
        }
    }else return 0;
}