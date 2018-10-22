#include "couch.h"

struct no {
char info;
struct no* prox;
};

Pilha cria_pilha(){
	return NULL;
}

int pilha_vazia(Pilha p){
	if(p==NULL) return 1;
	return 0;
}

int push(Pilha *p, char elem){
	Pilha N = (Pilha) malloc(sizeof(struct no));
	if(N==NULL) return 0;
	N->info = elem;
	N->prox= *p;
	*p = N;
	return 1;
}

int pop(Pilha *p){
	
if (pilha_vazia(*p) == 1)
return 0;

Pilha aux = *p;

*p = aux->prox;
free(aux);

return 1;
}

int printar(Pilha *p){
	Pilha aux;
	aux = *p;
	while(aux != NULL){
	 printf("%d\n", aux->info);
	 aux = aux->prox;
	}
}

int validade(char *s){
int i=0, cont=0;
Pilha aux;
aux = cria_pilha();

while(i<=strlen(s)){

if(s[i]=='(' || s[i]=='[' || s[i]=='{') {push(&aux,s[i]);cont++;}
if(s[i]==')' || s[i]==']' || s[i]=='}'){

if(s[i] == ')'){if(aux->info == '(') {pop(&aux);cont--;}
else return 0;
}
if(s[i] == ']'){if(aux->info == '[') {pop(&aux);cont--;}
else return 0;
}
if(s[i] == '}'){if(aux->info == '{') {pop(&aux);cont--;}
else return 0;
}
}
}
}

int le_topo (Pilha *p, int *elem) {

if (pilha_vazia(*p) == 1)
return 0;
*elem = (*p)->info;
return 1;
}