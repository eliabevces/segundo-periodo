#include "lista.h"

struct no{
int info;
struct no *prox;
};



Lista cria_lista() {
return NULL;
}

int lista_vazia (Lista lst) {
if (lst == NULL)
return 1;
else
return 0;
}

int insere_final (Lista *lst, int elem) {
Lista N = (Lista) malloc(sizeof(struct no));
if (N == NULL) { return 0; } 
N->info = elem; 
if (lista_vazia(*lst) == 1) {
N->prox = N; 
*lst = N; 
}else {
N->prox = (*lst)->prox; 
(*lst)->prox = N; 
*lst = N; 
}
return 1;
}


int insere_inicio(Lista *lst, int elem){
	Lista N = (Lista) malloc(sizeof(struct no));
	if (N == NULL) { return 0; }
	N->info =  elem;
	if(lista_vazia(*lst) == 1) {
	N->prox = N;
	*lst = N;
	}else{
		N->prox = (*lst)->prox;
		(*lst)->prox = N;
	}
return 1;
}

int insere_n(Lista *lst, int elem, int pos){
	int i;
	Lista aux = *lst;
	Lista aux2 = *lst;

	Lista N = (Lista) malloc(sizeof(struct no));
	if (N == NULL) { return 0; }
	N->info =  elem;
	if(pos > tamanho(lst)) {
		return 0;
	}

	for(i=0;i<pos;i++){
		N->prox = aux->prox;
		aux = aux->prox;

	}

	for(i=0;i<pos-1;i++){
		aux2 = aux2->prox;
	}
aux2->prox = N;

return 1;
}

int remove_n(Lista *lst, int pos){
	Lista aux = *lst;
	Lista aux1 = *lst;
	Lista rem = *lst;
	int i;
	if(pos > tamanho(lst)) {
		return 0;
	}
	for(i=0;i<pos+1;i++){
		aux = aux->prox;
	}

	for(i=0;i<pos;i++){
		rem = rem->prox;
	}

	for(i=0;i<pos-1;i++){
		aux1 = aux1->prox;
	}
	aux1->prox = aux;
	if(rem == *lst){
		*lst = aux1;
	}
	return 1;
}

int remove_inicio (Lista *lst, int *elem) {
if (lista_vazia(*lst) == 1)
return 0;
Lista aux = (*lst)->prox; 
*elem = aux->info; 
if (*lst == (*lst)->prox) 
*lst = NULL;
else 
(*lst)->prox = aux->prox;
free(aux);
return 1;
}

void printar(Lista lst){
	Lista aux = lst->prox;
	printf("Lista = {");
	while(aux != lst){
		printf("%d  ",aux->info);
		aux = aux->prox;
	}
	printf("%d",aux->info);
	printf("}\n");
}

int tamanho(Lista *lst){
	int end, tam=0;
	Lista aux = *lst;
	if (lista_vazia(*lst) == 1) return 0;
	aux = aux->prox;
	Lista aux2;
	aux2 = (*lst)->prox;
	while(aux->prox != aux2){
		tam++;
		aux = aux->prox;
	}
	tam++;
return tam;
}

int maior(Lista *lst){
	int maior;
	if (lista_vazia(*lst) == 1)
	return 0;
	Lista aux = *lst;
	maior = (*lst)->info;
	while(aux->prox!= *lst){
		if(aux->info>maior) maior = aux->info;
		aux = aux->prox;
	}
	if(aux->info>maior) maior = aux->info; //se o maior for o penultimo numero
	return maior;
}
