
#include "bin.h"

int main(){
	int resto[20]={},x;
	int num;
	Pilha p;
	printf("Escreva um numero em decimal?\n");
	scanf("%d", &num);
	p = cria_pilha();


while(1)
{	
		printf("escolha um caso:\n 1- converter para binario\n 2- converter para octal\n 3- converter hexadecimal\n");
	    scanf("%d", &x);
	    printf("\n\n");
		switch(x){
		case 1:
			binario(num);
			break;
		case 2:
			octal(num);
			break;
		case 3:
			hexa(num);
			break;
		default:
			printf("FIM\n");
			return 0; 
	}
	
	return 0;
}
}