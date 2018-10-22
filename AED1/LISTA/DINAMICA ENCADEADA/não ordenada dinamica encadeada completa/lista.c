
#include "lista.h"


struct no{
int info;
struct no * prox;
};

Lista cria_lista() {
return NULL;
}

int lista_vazia(Lista lst) {
if (lst == NULL)return 1; // Lista vazia
else return 0;  // Lista NÃO vazia
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
*lst = N; 
// Faz a lista apontar para o novo nó
return 1;
}

int insere_fim(Lista *lst, int elem){
	Lista aux = *lst;
	while(aux->prox!=NULL){
		aux = aux->prox;
	}
	Lista N = (Lista) malloc(sizeof(struct no));
	N->info = elem;
	aux->prox = N;
	N->prox = NULL;
	return 1;
}


int remove_elem (Lista *lst, int elem) {
if (lista_vazia(*lst) == 1)
return 0; 
// Falha
Lista aux = *lst; 

if (elem == (*lst)->info) 
{
*lst = aux->prox; 
free(aux); 
// Libera memória alocada
return 1; 
}
while (aux->prox != NULL && aux->prox->info != elem) aux = aux->prox;
if (aux->prox == NULL)  return 0; 
Lista aux2 = aux->prox; 
aux->prox = aux2->prox; 
free(aux2); 
return 1;
}


int remove_todas(Lista *lst, int elem){
if (lista_vazia(*lst) == 1)
return 0; 
Lista aux = *lst;
while (aux->prox != NULL){ 
if (elem == aux->info) {
	remove_elem(lst,elem); 
	aux = *lst;
}
aux=aux->prox;
}
return 1;
}


void printar(Lista lst){
	
	while(lst!=NULL){
		printf("%d  ",lst->info);
		lst = lst->prox;
	}
	
}



int tamanho(Lista lst){
	int tam=0;
	while(lst!=NULL){
	tam++;
	lst = lst->prox;	
	} 
return tam;
}

int remove_par(Lista *lst){
	Lista aux = *lst;
	int num[30],i=0,n=0;
	if (lista_vazia(*lst) == 1) return 0;
	while(aux!=NULL){
		if(aux->info%2==0) {
			num[i]=aux->info;
			i++;
			n++;
		}
		aux=aux->prox;
	}
	for(i=0;i<n;i++){
		remove_elem(lst,num[i]);
	}

return 1;
}

int maior (Lista *lst){
	int maior;
	Lista aux = *lst;
	if (lista_vazia(*lst) == 1) return 0;
	maior = aux->info;
	while(aux!=NULL){
		if(aux->info > maior) maior = aux->info;
		aux = aux->prox;
	}
	return maior;
}

Lista concatena(Lista *lst, Lista *lst1){
	Lista lstcon;
	Lista aux = *lst;
	Lista aux1 = *lst1;
	lstcon = cria_lista();
	while(aux!=NULL){
		insere_fim(&lstcon, aux->info);
		aux=aux->prox;
	}

	while(aux1!=NULL){
		insere_fim(&lstcon, aux1->info);
		aux1=aux1->prox;
	}

	return lstcon;

}