
#include <stdio.h>
#include <limits.h>

/* rightrot: return the value of x rotated right by n bit positions */
unsigned rightrot(unsigned x, int n) {
	int lsb, msb;
	
	for (int i = n; i > 0; i--) {
		lsb = x & 1;
		x >>= 1;
		msb = lsb << CHAR_BIT * sizeof(x) - 1;
		x |= msb;
	}
	return x;
}

int main() {
	unsigned x = 13;
	printf("x is: %u\n", x);
	printf("rightrot(x, 1) expect 2147483654: %u\n", rightrot(x, 1));
	printf("rightrot(x, 2) expect 1073741827: %u\n", rightrot(x, 2));
	printf("rightrot(x, 3) expect 2684354561: %u\n", rightrot(x, 3));
	x = 22;
	printf("x is: %u\n", x);
	printf("rightrot(x, 1) expect 11: %u\n", rightrot(x, 1));
	printf("rightrot(x, 2) expect 2147483653: %u\n", rightrot(x, 2));
	printf("rightrot(x, 3) expect 3221225474: %u\n", rightrot(x, 3));
	x = 104;
	printf("x is: %u\n", x);
	printf("rightrot(x, 1) expect 52: %u\n", rightrot(x, 1));
	printf("rightrot(x, 2) expect 26: %u\n", rightrot(x, 2));
	printf("rightrot(x, 3) expect 13: %u\n", rightrot(x, 3));
	printf("rightrot(x, 4) expect 2147483654: %u\n", rightrot(x, 4));
}
