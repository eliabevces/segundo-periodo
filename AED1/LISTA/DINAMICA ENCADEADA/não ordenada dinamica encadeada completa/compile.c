#include <stdlib.h>

int main(){
	system("gcc -c lista.c");
	system("gcc -c main.c");
	system("gcc -o encad lista.o main.o");
}