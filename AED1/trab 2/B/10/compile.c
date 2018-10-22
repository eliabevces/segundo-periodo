#include <stdlib.h>

int main(){
	system("gcc -c deque.c");
	system("gcc -c user.c");
	system("gcc -o deque deque.o user.o");
}