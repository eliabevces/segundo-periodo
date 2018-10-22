#include "pilha.h"

struct pilha{
	int info[MAX];
	int topo;
};

Pilha cria_pilha(){
	Pilha p = (Pilha) malloc(sizeof(struct pilha));
	if(p != NULL){
		p->topo = -1;
	}
	return p;
}


int pilha_vazia(Pilha p){
	if(p==NULL|| p->topo == -1) return 1;
	return 0;
}

int pilha_cheia(Pilha p){
	if(p->topo == MAX-1) return 1;
	return 0;
}

int push(Pilha p, int elem){
	if(p==NULL || pilha_cheia(p)) return 0;
	p->topo++;
	p->info[p->topo] = elem;
	return 1;
}

int pop(Pilha p, int *elem){
	if(pilha_vazia(p) || p==NULL) return 0;
	*elem = p->info[p->topo];
	p->topo--;
	return 1;
}

int printar(Pilha p){
	int i;
	if(pilha_vazia(p) || p==NULL) return 0;
	for (i = p->topo; i >= 0; i--)
	{
		printf("%d\n", p->info[i]);
	}
	printf("\n\n");
	return 1;
}

int printar_rev(Pilha p){
	int i;
	if(pilha_vazia(p) || p==NULL) return 0;
	for (i = 0; i < p->topo+1; i++)
	{
		printf("%d\n", p->info[i]);
	}
	printf("\n\n");
	return 1;
}


int le_topo (Pilha p, int *elem) {
if (p == NULL || pilha_vazia(p) == 1) return 0;
*elem = p->info[p->topo]; 
return 1;
}

int parimpar(Pilha p, Pilha p1, Pilha p2){
	int i;
	for (i = 0; i < p->topo+1; i++){
		if(p->info[i]%2) push(p1,p->info[i]);
		else push(p2, p->info[i]);
	}
	return 1;
}

