#include <stdio.h>
#include <stdlib.h>

typedef struct no *Lista;

Lista cria_lista();
Lista multi3(Lista *lst);
int lista_vazia (Lista lst);
int insere_elemento (Lista *lst, int elem);
int remove_elemento(Lista *lst, int elem);
int remove_todos(Lista *lst, int elem);
void printar(Lista lst);
int tamanho(Lista lst);
int remove_maior(Lista *lst);

