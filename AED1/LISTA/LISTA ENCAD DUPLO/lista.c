#include "lista.h"

struct no
{
int info;
struct no * prox;
struct no * ant;
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

int insere_elemento (Lista *lst, int elem) {
// Aloca um novo nó e preenche campo info
Lista N = (Lista) malloc(sizeof(struct no));
if (N == NULL) { return 0; } 
// Falha: nó não alocado
N->info = elem; 
// Insere o conteúdo (valor do elem)
N->ant = NULL; 
// Não tem antecessor do novo nó
N->prox = *lst; 
// Sucessor do novo nó recebe mesmo end. da lista
if (lista_vazia(*lst) == 0) 
// Se lista NÃO vazia
(*lst)->ant = N; 
// Faz o antecessor do 1o nó ser o novo nó
*lst = N; 
// Faz a lista apontar para o novo nó
return 1;
}

int remove_elemento(Lista *lst, int elem){
if (lista_vazia(*lst))
// Trata lista vazia
return 0;
Lista aux = *lst; 
// Faz aux apontar para 1o nó
while (aux->prox != NULL && aux->info != elem)
aux = aux->prox;
if (aux->info != elem) return 0; 
// Elemento não está na lista
if (aux->prox != NULL) (aux)->prox->ant = aux->ant;
if (aux->ant != NULL) (aux)->ant->prox = aux->prox;
if (aux == *lst) *lst = aux->prox;
free(aux);
return 1;
}

int remove_todos(Lista *lst, int elem){
	if (lista_vazia(*lst)) return 0;
	int n =  tamanho(*lst);
	for (int i = 0; i < n; i++)
	{
	remove_elemento(lst,elem);
	}
	if((*lst)->info == elem) {
		*lst = NULL;
		return 0;
		//se todos forem o numero que sera removido o programa acaba
	}
	return 1;
}

void printar(Lista lst){
	Lista aux = lst;
	printf("Lista = {");
	while(aux != lst->ant){
		printf("%d  ",aux->info);
		aux = aux->prox;
	}
	printf("}\n");
}

int tamanho(Lista lst){
	Lista aux = lst;
	int tam=0;
	while(aux->prox != lst->ant){
		tam++;
		aux=aux->prox;
	}
	tam++;
	return tam;
}

int remove_maior(Lista *lst){
	if (lista_vazia(*lst)) return 0;
	int maior;
	Lista aux = *lst;
	maior = aux->info;
	while(aux->prox != NULL){
		if(aux->info > maior) maior =  aux->info;
		aux = aux->prox;
	}
	if(aux->info > maior) maior =  aux->info;

	remove_todos(lst, maior);

	return 1;
}

Lista multi3(Lista *lst){
	if (lista_vazia(*lst)) return 0;
	Lista aux = *lst;
	int i;
	Lista mult;
	mult = cria_lista();
	for(i=0;i<tamanho(*lst);i++){
		if(aux->info%3 == 0){
			int n = aux->info;
			insere_elemento(&mult,n);
		}
		aux = aux->prox;
	}
return mult;
}