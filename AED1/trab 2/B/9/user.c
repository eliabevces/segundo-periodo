#include "fila.h"

int main() {
	Fila a;
	int n,x;
	while(1)
	{	
		printf("escolha um caso:\n 1- criar fila\n 2- inserir elemento\n 3- remover\n 4- imprimir lista\n\n");
	    scanf("%d", &x);
	    printf("\n\n");
		switch(x){
		case 1:
			a = cria_fila();
			break;
		case 2:
			printf("insira um numero: \n");
			scanf("%d", &n);
			insere(a,n);	
			break;
		case 3:
			remove_ini(a, &n);
			printf("REMOVIDO: %d\n", n);
			break;
		case 4:
			printar(a);
			break;
		default:
			printf("FIM\n");
			return 0; 
		}
	}
}