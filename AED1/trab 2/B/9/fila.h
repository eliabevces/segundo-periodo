#include<stdio.h>
#include<stdlib.h>


typedef struct fila *Fila;

Fila cria_fila();
int fila_vazia(Fila f) ;
int insere(Fila f, int elem);
int remove_ini(Fila f, int *elem);
int printar(Fila f);

