#include <stdlib.h>

int main(){
	system("gcc -c pilha.c");
	system("gcc -c user.c");
	system("gcc -o pilha pilha.o user.o");
}