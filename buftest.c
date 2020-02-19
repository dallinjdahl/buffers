#include "buffer.h"

uint *test = NULL;
char *bound = "hello world";

void printbuf(uint *b) {
	printf("s%d c%d\n", size(b), cap(b));
	for(int i = 0; i < size(b); i++) {
		printf("%d ", b[i]);
	}
	printf("\n");
}

int main(int argc, char ** argv) {
	push(&test, 5);
	printbuf(test);
	for(int i = 0; i < 100; i++) {
		push(&test, i);
	}
	printbuf(test);
	for(int i = 0; i < 50; i++) {
		pop(test);
	}
	printbuf(test);
}
