#include<stdlib.h>

int main(){
	system("gcc -c bin.c");
	system("gcc -c user.c");
	system("gcc -o bin bin.o user.o");
}