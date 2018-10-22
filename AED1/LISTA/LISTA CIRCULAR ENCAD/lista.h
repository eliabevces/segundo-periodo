#include <stdio.h>
#include <stdlib.h>

typedef struct no *Lista;

Lista cria_lista();
int lista_vazia (Lista lst);
int insere_final (Lista *lst, int elem);
int insere_inicio(Lista *lst, int elem);
int insere_n(Lista *lst, int elem, int pos);
int remove_inicio (Lista *lst, int *elem);
int remove_n(Lista *lst, int pos);
void printar(Lista lst);
int tamanho(Lista *lst);
int maior(Lista *lst);

