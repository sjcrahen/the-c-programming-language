#include <stdio.h>

/* setbits: set n bits of x from position p to rightmost n bits of y */
unsigned setbits(unsigned x, int p, int n, unsigned y) {
	return (x & (~(~(~0 << n) << (p+1-n)))) | ((y & (~(~0 << n))) << (p+1-n));
}

int main() {
	unsigned x = 20;
	unsigned y = 5;
	printf("x is: %u  y is: %u\n", x, y);
	printf("setbits(x, 4, 3, y) expecting 20: %u\n", setbits(x, 4, 3, y));	
	x = 20;
	y = 7;
	printf("\nx is: %u  y is: %u\n", x, y);
	printf("setbits(x, 4, 3, y) expecting 28: %u\n", setbits(x, 4, 3, y));
	x = 102;
	y = 51;
	printf("\nx is: %u  y is: %u\n", x, y);
	printf("setbits(x, 5, 2, y) expecting 118: %u\n", setbits(x, 5, 2, y));
	x = 102;
	y = 55;
	printf("\nx is: %u  y is: %u\n", x, y);
	printf("setbits(x, 4, 3, y) expecting 126: %u\n", setbits(x, 4, 3, y));
	x = 126;
	y = 24;
	printf("\nx is: %u  y is: %u\n", x, y);
	printf("setbits(x, 3, 1, y) expecting 118: %u\n", setbits(x, 3, 1, y));

}
