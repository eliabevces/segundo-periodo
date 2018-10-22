#include <stdlib.h>

int main(){
	system("gcc -c lista.c");
	system("gcc -c user.c");
	system("gcc -o cab lista.o user.o");
}