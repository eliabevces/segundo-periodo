#include "pilha.h"

int main(){
	Pilha p,p1,p2;
	int elem, n, x;

	

	while(1)
{	
		printf("escolha um caso:\n 1- criar Pilhas\n 2- inserir elemento na pilha original\n 3- remover topo e imprimir removido\n 4- imprimir pilhas\n 5- le topo da pilha original\n 6- imprime reverso da pilha original\n 7- separar em pilhas par e impar\n");
	    scanf("%d", &x);
	    printf("\n\n");
		switch(x){
		case 1:
			p  = cria_pilha();
			p1 = cria_pilha();
			p2 = cria_pilha();
			printf("Pilhas criadas\n");
			break;
		case 2:
			printf("insira um numero: \n");
			scanf("%d", &n);
			push(p, n);	
			break;
		case 3:
			pop(p, &elem);
			printf("REMOVIDO: %d\n", elem);
			break;
		case 4:
			printf("PILHA ORIGINAL:\n");
			printar(p);
			printf("\n");
			printf("PILHA IMPAR:\n");
			printar(p1);
			printf("\n");
			printf("PILHA PAR:\n");
			printar(p2);
			printf("\n");
			break;
		case 5:
			le_topo(p, &elem);
			printf("TOPO: %d\n", elem);
			break;
		case 6:
			printar_rev(p);
			break;
		case 7:
			parimpar(p,p1,p2);
			break;
		case 8:
			palindromo(char *s);
			break;
		default:
			printf("FIM\n");
			return 0; 
	}
}
}