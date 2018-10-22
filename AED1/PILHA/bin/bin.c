#include "bin.h"

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

int pilha_cheia(Pilha p){
	if(p->topo == MAX-1) return 1;
	return 0;
}

int pilha_vazia(Pilha p){
	if(p==NULL|| p->topo == -1) return 1;
	return 0;
}

int push(Pilha p, int elem){
	if(p==NULL || pilha_cheia(p)) return 0;
	p->topo++;
	p->info[p->topo] = elem;
	return 1;
}

int printar(Pilha p){
	int i;
	if(pilha_vazia(p) || p==NULL) return 0;
	for (i = p->topo; i >= 0; i--)
	{	
		if(p->info[i]>=10){
		printf("%C", 'A'+(p->info[i]-10));
		}else printf("%d", p->info[i]);
		}
	return 1;
	}

int binario(int elem){
	Pilha p;
	p = cria_pilha();
	int resto[20] = {},i=0,j;
	while(elem!=0){
		resto[i] = elem%2;
		elem = elem/2;
		i++;
	}
	for(j =0; j<i;j++){
		push(p,resto[j]);
	}
	printar(p);

return 1;
}

int octal(int elem){
	Pilha p;
	p = cria_pilha();
	int resto1[20] = {},i=0,j;
	while(elem!=0){
		resto1[i] = elem%8;
		elem = elem/8;
		i++;
	}
	for(j =0; j<i+1;j++){
		push(p,resto1[j]);
	}
	printar(p);

return 1;
}

int hexa(int elem){
	Pilha p;
	p = cria_pilha();
	int resto1[20] = {},i=0,j;
	while(elem!=0){
		resto1[i] = elem%16;
		elem = elem/16;
		i++;
	}
	for(j =0; j<i+1;j++){
		push(p,resto1[j]);
	}
	printar(p);

return 1;
}