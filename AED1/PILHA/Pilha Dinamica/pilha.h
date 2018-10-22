
#include<stdio.h>
#include<stdlib.h>

typedef struct no * Pilha;

Pilha cria_pilha();
int pilha_vazia(Pilha p);
int push(Pilha *p, int elem);
int pop(Pilha *p, int *elem);
int printar(Pilha *p);
int le_topo (Pilha *p, int *elem);
int parimpar(Pilha *p,Pilha *p1,Pilha *p2);