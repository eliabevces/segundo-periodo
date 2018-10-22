#include "fila.h"

struct no
 {
    int info;
    struct no *prox;
};

struct fila
 {
    struct no *ini;
    struct no *fim;
};

Fila cria_fila() {
    Fila f;
    f = (Fila) malloc(sizeof(struct fila));
    if (f != NULL) {
        f->ini = NULL;
        f->fim = NULL;
    }
    return f;
}

int fila_vazia(Fila f) {
    if (f->ini == NULL)
        return 1;
    else
        return 0;
}

int insere_fim(Fila f, int elem) {
    struct no *N;
    N = (struct no *) malloc(sizeof(struct no));
    if (N == NULL)
        return 0;
    N->info = elem; 
// Preenche campo info
    N->prox = NULL; 
// Preenche campo prox
    if (fila_vazia(f) == 1)
        f->ini = N; 
// Se fila vazia
    else
        (f->fim)->prox = N; 
// Se fila com elementos (NÃO vazia)
    f->fim = N; 
// Campo fim aponta para N
    return 1;
}

int remove_ini(Fila f, int *elem) {
    if (fila_vazia(f) == 1)
        return 0;
    struct no * aux = f->ini;
// Aux aponta para o 1o nó
*elem = aux->info; 
// Retorna valor do elemento
// Verifica se a fila tem um único nó
    if (f->ini == f->fim)
        f->fim = NULL;
    f->ini = aux->prox; 
// Retira 1o nó da fila
    free(aux); 
// Libera a memória alocada
    return 1;
}

int printar(Fila f){
	Fila aux = f;
	while(aux->ini!=NULL){
		printf("%d ", (aux->ini)->info);
		aux->ini = (aux->ini)->prox;
	}
	free(aux);
	printf("\n");
	return 1;
}

