#include "lista.h"

struct no{
int info;
struct no * prox;
};

Lista cria_lista() {
return NULL;
}

int lista_vazia(Lista lst) {
if (lst == NULL) return 1; // Lista vazia
else return 0; // Lista NÃO vazia
}



int insere_ord (Lista *lst, int elem) {
	Lista N = (Lista) malloc(sizeof(struct no));
if (N == NULL) { return 0; } 
N->info = elem; 
if (lista_vazia(*lst) || elem <= (*lst)->info) {
	N->prox = *lst; 
	*lst = N; 
	return 1;  
}
Lista aux = *lst; 
while (aux->prox != NULL && aux->prox->info < elem)
aux = aux->prox; 
N->prox = aux->prox;
aux->prox = N;
return 1;  
}


int remove_ord (Lista *lst, int elem) {
if (lista_vazia(*lst) == 1 || elem < (*lst)->info)
return 0; // Falha
Lista aux = *lst; // Ponteiro auxiliar para o 1onó
if (elem == (*lst)->info) 
{
// Remove elemento onóda lista
*lst = aux->prox; 
// Lista aponta para o 2onó
free(aux); 
// Libera memória alocada
return 1; 
}
while (aux->prox != NULL && aux->prox->info < elem)
aux = aux->prox;
if (aux->prox == NULL || aux->prox->info > elem)
return 0; 
// Falha
// Remove elemento (após o 1onó da lista)
Lista aux2 = aux->prox; 
// Aponta nó a ser removido
aux->prox = aux2->prox; 
// Retira nó da lista
free(aux2); 
// Libera memória alocada
return 1;
}


int printar(Lista *lst){
    if(lista_vazia(*lst)) return 0;
    Lista aux;
    aux = *lst;
    while(aux!= NULL){
     printf("%d ", aux->info);
    aux=aux->prox;
    
}
}

Lista concatena(Lista *lst, Lista *lst1){
    Lista lstcon;
    Lista aux = *lst;
    Lista aux1 = *lst1;
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

int remove_impar(Lista *lst){
Lista aux = *lst;
    int num[30],i=0,n=0;
    if (lista_vazia(*lst) == 1) return 0;
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

int menor(Lista *lst){
    if(lista_vazia(*lst)) return 0;
    return (*lst)->info;
}

int tamanho(Lista lst){
    if(lista_vazia(lst)) return 0;
    int tam=0;
    while(lst!=NULL){
    tam++;
    lst = lst->prox;    
    } 
return tam;
}

int compara(Lista *lst, Lista*lst1){
    Lista aux = *lst;
    Lista aux1 = *lst1;
    int i, vet[tamanho(aux)], vet1[tamanho(aux1)];
    if(tamanho(aux) != tamanho(aux1)) return 0;
    printf("--2--\n");
        for(i=0;i<tamanho(aux);i++){
            vet[i] = aux->info;
            aux = aux->prox;
        }
    for(i=0;i<tamanho(aux1);i++){
            vet1[i] = aux1->info;
            aux1 = aux1->prox;
        }
         for (i = 0; i < tamanho(aux); i++)
         {
             if(vet[i] != vet1[i]) return 0;
         }
        return 1;
}