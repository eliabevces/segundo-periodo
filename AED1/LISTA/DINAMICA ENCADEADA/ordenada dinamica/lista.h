#include <stdio.h>
#include <stdlib.h>

typedef struct no*Lista;

Lista cria_lista();
Lista concatena(Lista *lst, Lista *lst1);
int lista_vazia(Lista lst);
int lista_cheia(Lista *lst);
int insere_ord (Lista *lst, int elem);
int remove_ord (Lista *lst, int elem);
int printar(Lista *lst);
int remove_impar(Lista *lst);
int menor(Lista *lst);
int tamanho(Lista lst);
int compara(Lista *lst, Lista*lst1);