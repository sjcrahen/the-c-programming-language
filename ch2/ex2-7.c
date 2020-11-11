
#include <stdio.h>

/* invert: return x with n bits beginning at p inverted */
unsigned invert(unsigned x, int p, int n) {
	return (x ^ (~(~0 << n) << (p+1-n)));
}

int main() {
	unsigned x = 9;
	printf("x is: %u\n", x);
	printf("invert(x, 3, 2) expect 5: %u\n", invert(x, 3, 2));
	x = 13;
	printf("x is: %u\n", x);
	printf("invert(x, 4, 3) expect 17: %u\n", invert(x, 4, 3));
	x = 85;
	printf("x is: %u\n", x);
	printf("invert(x, 5, 5) expect 107: %u\n", invert(x, 5, 5));

}
