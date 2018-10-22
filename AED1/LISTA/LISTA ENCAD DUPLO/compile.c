#include <stdlib.h>

int main(){
	system("gcc -c lista.c");
	system("gcc -c main.c");
	system("gcc -o dupla lista.o main.o");
}