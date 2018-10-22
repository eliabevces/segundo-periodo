#define MAX 11
#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

struct no
{
int info;
struct no *prox;
};

Lista cria_lista() {
return NULL;
}

int lista_vazia(Lista lst) {
if (lst == NULL) return 1; // Lista vazia
else return 0; // Lista NÃO vazia
}



int insere_elem (Lista *lst, int elem) {
// Aloca um novo nó
Lista N = (Lista) malloc(sizeof(struct no));
if (N == NULL) { return 0; } 
// Falha: nó não alocado
// Preenche os campos do novo nó
N->info = elem; 
// Insere o conteúdo (valor do elem)
N->prox = *lst; 
// Aponta para o 1onó atual da lista
*lst = N; 
// Faz a lista apontar para o novo nó
return 1;
}



int remove_elem (Lista *lst, int elem) {
if (lista_vazia(*lst) == 1)
return 0; 
// Falha
Lista aux = *lst; 
// Ponteiro auxiliar para o 1 nó
// Trata elemento = 1o nó da lista
if (elem == (*lst)->info) 
{
*lst = aux->prox; 
// Lista aponta para o 2o nó
free(aux); 
// Libera memória alocada
return 1; 
}
// Percorrimento até achar o elem ou final de lista
while (aux->prox != NULL && aux->prox->info != elem)
aux = aux->prox;
if (aux->prox == NULL) 
// Trata final de lista
return 0; 
// Falha
// Remove elemento ≠ 1o nó da lista
Lista aux2 = aux->prox; 
// Aponta nó a ser removido
aux->prox = aux2->prox; 
// Retira nó apontado p/ aux2 da lista
free(aux2); 
// Libera memória alocada
return 1;
}

void printar(Lista lst){
    Lista aux;
    aux = lst;
    printf("{\n");
    while(aux!= NULL){
     printf("%d ", aux->info);
    aux=aux->prox;
}
printf("\n}\n");
}




