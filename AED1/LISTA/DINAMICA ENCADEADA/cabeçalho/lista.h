#include <stdio.h>
#include <stdlib.h>

typedef struct no * Lista;

Lista cria_lista();
int lista_vazia(Lista lst);
int insere_elem(Lista *lst, int elem);
int remove_elem (Lista *lst, int elem);
void printar(Lista lst);
int tamanho(Lista *lst);