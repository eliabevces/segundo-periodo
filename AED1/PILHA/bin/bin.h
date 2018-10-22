
#include<stdio.h>
#include<stdlib.h>
#define MAX 50
typedef struct pilha * Pilha;

Pilha cria_pilha();
int pilha_vazia(Pilha p);
int push(Pilha p, int elem);
int printar(Pilha p);
int binario(int elem);
int octal(int elem);
int hexa(int elem);