#include <stdio.h>
#include <stdlib.h>

typedef struct deque * Deque;
typedef struct no * Elem;

Deque cria_deque();
int deque_vazio(Deque d);
int insere_inicio(Deque d, int elem);
int insere_final(Deque d, int elem);
int remove_inicio(Deque dq);
int remove_final(Deque dq);
int imprime_deque(Deque dq);