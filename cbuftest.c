#include "cbuffer.h"

char *test = NULL;

void printbuf(char *b) {
	printf("s%d c%d\n", size(b), cap(b));
	for(int i = 0; i < size(b); i++) {
		printf("%c ", b[i]);
	}
	printf("\n");
}

int main(int argc, char ** argv) {
	push(&test, 'z');
	printbuf(test);
	for(int i = 0; i < 100; i++) {
		push(&test, 'a' + (i % 26));
printbuf(test);
	}
	printbuf(test);
	for(int i = 0; i < 50; i++) {
		pop(test);
	}
	printbuf(test);
}
