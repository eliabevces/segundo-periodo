#include "lista.h"

struct no
{
int info;
struct no * prox;
};

Lista cria_lista() {
Lista cab;
cab = (Lista) malloc(sizeof(struct no));
if (cab != NULL) { 
cab->prox = NULL;
cab->info = 0; } 
return cab;
}

int lista_vazia(Lista lst) {
if (lst->prox == NULL)
return 1; 
else
return 0; 
}

int insere_ord (Lista *lst,int elem) {
Lista N = (Lista) malloc(sizeof(struct no));
if (N == NULL) { return 0; } 
N->info = elem; 
Lista aux = *lst; 
while (aux->prox != NULL && aux->prox->info < elem)
aux = aux->prox; 
N->prox = aux->prox;
aux->prox = N;
(*lst)->info++; 
return 1;  }

int remove_ord (Lista *lst, int elem) {
if (lista_vazia(*lst) == 1)
return 0; 
Lista aux = *lst;
// Ponteiro auxiliar
while (aux->prox != NULL && aux->prox->info < elem)
aux = aux->prox;
if (aux->prox == NULL || aux->prox->info > elem)
return 0; 
Lista aux2 = aux->prox; 
aux->prox = aux2->prox; 
free(aux2); 
(*lst)->info--;
return 1;  }

void printar(Lista lst){
    Lista aux;
    aux = lst;
    aux = aux->prox;
    while(aux!= NULL){
     printf("%d ", aux->info);
    aux=aux->prox;
}
}

int tamanho(Lista *lst){
	return (*lst)->info;
}

int remove_impar(Lista *lst){
Lista aux = *lst;
    int num[30],i=0,n=0;
    if (lista_vazia(*lst) == 1) return 0;
    aux = aux->prox;
    while(aux!=NULL){
        if(aux->info%2) {
            num[i]=aux->info;
            i++;
            n++;
        }
        aux=aux->prox;
    }
    for(i=0;i<n;i++){
        remove_ord(lst,num[i]);
    }

return 1;
}

int menor(Lista lst){
	return lst->prox->info;
}

int compara(Lista *lst, Lista*lst1){
    Lista aux = *lst;
    Lista aux1 = *lst1;
    int i, vet[tamanho(&aux)], vet1[tamanho(&aux1)];
    if(tamanho(&aux) != tamanho(&aux1)) return 0;
        for(i=0;i<tamanho(&aux);i++){
            vet[i] = aux->info;
            aux = aux->prox;
        }
    for(i=0;i<tamanho(&aux1);i++){
            vet1[i] = aux1->info;
            aux1 = aux1->prox;
        }
         for (i = 0; i < tamanho(&aux); i++)
         {
             if(vet[i] != vet1[i]) return 0;
         }
        return 1;
}
Lista concatena(Lista *lst, Lista *lst1){
	Lista lstcon;
    Lista aux = *lst;
    Lista aux1 = *lst1;
    aux = aux->prox;
    aux1 = aux1->prox;
    lstcon = cria_lista();
    while(aux!=NULL){
        insere_ord(&lstcon, aux->info);
        aux=aux->prox;
    }

    while(aux1!=NULL){
        insere_ord(&lstcon, aux1->info);
        aux1=aux1->prox;
    }

    return lstcon;
}