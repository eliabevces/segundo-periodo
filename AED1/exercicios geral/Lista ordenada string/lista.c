#define MAX 10
#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lista
{
    palavra* vet;
    int Fim;
};

Lista* cria_lista()
{
    Lista *lst;
    int i;
    lst = (Lista*) malloc(sizeof(Lista));
    for(i=0;i<MAX;i++){
        lst->vet[i]=(char*) malloc(MAX*sizeof(char));
    }
    if (lst != NULL)
        lst->Fim = 0; // Lista  vazia
    if(lst->Fim ==0)printf("Lista Criada com sucesso\n");
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
int insere_ord(Lista *lst, palavra x)
{
    if (lst == NULL || lista_cheia(lst) == 1)
        return 0;
// Falha
// Trata lista vazia ou elemento ≥ último da lista
    int i;
    i = lst->Fim;
    strcpy(lst->vet[lst->Fim++],x);
    if(lst->Fim>i)return 1;
    else return 0;
}

int remove_ord (Lista *lst, palavra x)
{
    if (lst == NULL || lista_vazia(lst) == 1)
        return 0;
// Falha
    int i, j;
    for(i=0;i<lst->Fim;i++){
        if(strcmp(lst->vet[i],x)==0){
            if(i==lst->Fim){
                lst->Fim--;
                return 1;
            }
            else{
                for(j=i;j<lst->Fim;j++){
                    strcpy(lst->vet[j],lst->vet[j+1]);
                }
                lst->Fim--;
                return 1;
            }
        }
    }
    return 0;
}

void printar(Lista *lst){
    int i;
    printf("\nLista : ");
    for(i=0;i<lst->Fim;i++){
        printf("%s", lst->vet[i]);
        if(i<lst->Fim-1) printf(" ");
    }
    printf("\n\n");
}


