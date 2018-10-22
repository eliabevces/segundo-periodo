#define MAX 40
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct pilha * Pilha;

Pilha cria_pilha();
int pilha_vazia(Pilha p);
int pilha_cheia(Pilha p);
int push(Pilha p, int elem);
int pop(Pilha p, int *elem);
int printar(Pilha p);
int printar_rev(Pilha p);
int le_topo (Pilha p, int *elem);
int parimpar(Pilha p, Pilha p1, Pilha p2);
