#include <stdlib.h>

int main(){
	system("gcc -c lista.c");
	system("gcc -c main.c");
	system("gcc -o norde lista.o main.o");
}