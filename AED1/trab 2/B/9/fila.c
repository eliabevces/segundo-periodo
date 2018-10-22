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

int insere(Fila f, int elem) {
    struct no *aux = (struct no *) malloc(sizeof(struct no));
    if (aux == NULL)
        return 0;
    aux->info = elem; 
    
// Preenche campo prox
    if (fila_vazia(f) == 1){
        f->ini = f->fim = aux; 
        aux->prox = NULL;
        return 1;
    }
   if(elem<=f->ini->info){
        aux->prox=f->ini;
        f->ini=aux;
        return 1;
    }
    if(elem>=f->fim->info){
        f->fim->prox=aux;
        aux->prox=NULL;
        f->fim=aux;
        return 1;
    }
    struct no *aux2;
    for(aux2=f->ini;aux2->prox!=NULL &&
     aux2->prox->info<elem;aux2=aux2->prox);
    aux->prox=aux2->prox;
    aux2->prox=aux;
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
    if(fila_vazia(f)) return 0;
	struct no *aux = f->ini;
	while(aux!=NULL){
		printf("%d ", aux->info);
		aux = aux->prox;
	}
	printf("\n");
	return 1;
}

