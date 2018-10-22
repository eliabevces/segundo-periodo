#include <stdlib.h>

int main(){
	system("gcc -c couch.c");
	system("gcc -c user.c");
	system("gcc -o couch couch.o user.o");
}