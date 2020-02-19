#include <stdint.h>

typedef uint32_t uint;
#ifndef METADATA
#define size(u) ((u)[-1])
#define cap(u) ((u)[-2])
#include <stdlib.h>
#include <string.h>
uint * grow(uint *b, uint c) {
		if(!b) {
			uint * res = calloc(c + 2, sizeof(uint));
printf("r%x\n", res);
			res += 2;
			cap(res) = c;
			return res;
		}
		uint *a = b - 2;
		uint * res = calloc(c + 2, sizeof(uint));
		memcpy(res, a, (size(b)+2)*sizeof(uint));
printf("a%x\n", a);
		free(a);
		res += 2;
		cap(res) = c;
		return res;
}
#else
uint *(*grow)(uint *, uint);
#endif

void push(uint **b, uint x) {
	if(!*b) {
		*b = grow(0, 8);
	}
	if(size(*b) >= cap(*b)) {
		*b = grow(*b, cap(*b)<<1);
	}
	(*b)[size(*b)] = x;
	size(*b)++;
}

uint pop(uint *b) {
	return b[(size(b)--)-1];
}

