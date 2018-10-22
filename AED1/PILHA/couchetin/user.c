#include "couch.h"

int main(){
	Pilha p;
	char s[MAX];
	int i,x,H=0;

	printf("Escreva a equação.\n");
	scanf("%s", &s[0]);
	
	if(validade(s)) printf("Expressao valida\n");
	else printf("Expressao invalida\n");

	return 0;
}