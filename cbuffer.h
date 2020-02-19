#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef uint16_t meta; 
typedef unsigned char uchar;

meta size(uchar *b) {
	meta res = b[-3];
	res <<= 8;
	res += b[-4];
	return res;
}

meta cap(uchar *b) {
printf("gc%d %x\n", b[-1], b[-2]);
	meta res = b[-1];
	res <<= 8;
	res += b[-2];
	return res;
}

void ssize(uchar *b, meta s) {
	b[-4] = s & 0xFF;
	s >>= 8;
	b[-3] = s;
}

void scap(uchar *b, meta c) {
printf("oc%d\n", c);
	b[-2] = c & 0xFF;
printf("lc%d\n", c & 0xFF);
	c >>= 8;
printf("hc%d\n", c);
	b[-1] = c;
}

uchar *grow(uchar *b, meta c) {
printf("growing to %d\n", c);
		if(!b) {
			uchar *res = calloc(c + 4, sizeof(uchar));
			res += 4;
			scap(res, c);
			return res;
		}
		uchar *a = b - 4;
		uchar *res = calloc(c + 4, sizeof(uchar));
		memcpy(res, a, (size(b)+4)*sizeof(uchar));
		free(a);
		res += 4;
		scap(res, c);
		return res;
}

void push(uchar **b, uchar x) {
	if(!*b) {
		*b = grow(0, 8);
	}
	if(size(*b) >= cap(*b)) {
		*b = grow(*b, cap(*b)<<1);
	}
	(*b)[size(*b)] = x;
	ssize(*b, size(*b)+1);
}

uchar pop(uchar *b) {
	ssize(b, size(b)-1);
	return b[size(b)];
}

