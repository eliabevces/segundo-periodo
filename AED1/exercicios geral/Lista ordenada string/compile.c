#include <stdlib.h>

int main(){
	system("gcc -c lista.c");
	system("gcc -c main.c");
	system("gcc -o orde lista.o main.o");
}