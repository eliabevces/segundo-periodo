#include <stdio.h>
#include <stdlib.h>
#define MAX 11
typedef struct no*Lista;

Lista cria_lista();
int lista_vazia(Lista lst);
int insere_elem (Lista *lst, int elem);
int remove_elem (Lista *lst, int elem);
int remove_todas(Lista *lst, int elem);
int remove_par(Lista *lst);
int insere_fim(Lista *lst, int elem);
int maior (Lista *lst);
Lista concatena(Lista *lst, Lista *lst1);
void printar(Lista lst);
int tamanho(Lista lst);

