#include "pilha.h"

int main(){
	Pilha p,p1,p2;
	int elem, n, x;

	

	while(1)
{	
		printf("escolha um caso:\n 1- criar listas\n 2- inserir elemento\n 3- remover topo e imprimir removido\n 4- le topo\n 5- imprimir listas\n 6- separar em pilhas par e impar\n");
	    scanf("%d", &x);
	    printf("\n\n");
		switch(x){
		case 1:
			p = cria_pilha();
			p1 = cria_pilha();
			p2 = cria_pilha();
			break;
		case 2:
			printf("insira um numero: \n");
			scanf("%d", &n);
			push(&p, n);	
			break;
		case 3:
			pop(&p, &elem);
			printf("REMOVIDO: %d\n", elem);
			break;
		case 4:
			le_topo(&p, &elem);
			printf("TOPO: %d\n", elem);
			break;
		case 5:
			printf("LISTA ORIGINAL:\n");
			printar(&p);
			printf("\n");
			printf("LISTA IMPAR:\n");
			printar(&p1);
			printf("\n");
			printf("LISTA PAR:\n");
			printar(&p2);
			printf("\n");
			break;
		case 6:
			parimpar(&p,&p1,&p2);
			printf("outaq");
			break;
		default:
			printf("FIM\n");
			return 0; 
	}
}
}