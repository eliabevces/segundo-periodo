#include "deque.h"

struct no{
	struct no *ant, *prox;
	int info;
};

struct deque{
	struct no *ini, *fim;
	int qtd;
};

Deque cria_deque(){
	Deque dq = (Deque) malloc(sizeof(struct deque));
	if(dq != NULL){
		dq->fim = NULL;
		dq->ini=NULL;
		dq->qtd = 0;
	}
	return dq;
}

int deque_vazio(Deque dq){
	if(dq == NULL|| dq->ini==NULL) return 1;
	return 0;

}

int insere_inicio(Deque dq, int elem){
	if(dq == NULL) return 0;

	Elem no = (Elem) malloc(sizeof(struct no));
	if(no == NULL) return 0;

	no->info = elem;
	no->prox = dq->ini;
	no->ant = NULL;

	if(dq->ini == NULL){
		dq->fim = no;
	}
	else dq->ini->ant = no;

	dq->ini = no;
	dq->qtd++;
	return 1;
}
int insere_final(Deque d, int n){
	if( d == NULL) return 0;
	struct no *no = (struct no*) malloc(sizeof(struct no));
	if(no == NULL) return 0;

no->info = n;
no->prox = NULL;

if(d->fim == NULL){
	no->ant = NULL;
	d->ini = no;
}else{
	no->ant = d->fim;
	d->fim->prox = no;
}

d->fim - no;
d->qtd++;
return 1;
}

int remove_inicio(Deque dq)
{
    if(dq == NULL || deque_vazio(dq))
        return 0;

    Elem no = dq->ini;
    dq->ini = dq->ini->prox;
    if(dq->ini == NULL)
        dq->fim = NULL;
    else
        dq->fim->ant = NULL;
    free(no);
    dq->qtd--;
    return 1;
}

int remove_final(Deque d)
{
    if(deque_vazio(d)==1) return 0;

    Elem no = d->fim;
    if(no == d->ini){ //! so tem um elemento
        d->ini = NULL;
        d->fim = NULL;
    }else{
        no->ant->prox = NULL;
        d->fim = no->ant;
    }
    free(no);
    d->qtd--;
    return 1;
}

int imprime_deque(Deque dq)
{
    Elem no = dq->ini;
    printf("Deque:\n\t{ ");
    while(no != NULL) {
        printf("%d ", no->info);
        no = no->prox;
    }
    printf("}\n");
    return 1;
}