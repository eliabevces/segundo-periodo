#include <stdlib.h>

int main(){
	system("gcc -c fila.c");
	system("gcc -c user.c");
	system("gcc -o fila fila.o user.o");
}