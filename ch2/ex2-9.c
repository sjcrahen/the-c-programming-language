/* Exercise 2-9
 * In a two's complement number system, x &= (x-1) deletes the
 * rightmost 1-bit in x. Explain why. Use this observation to 
 * write a faster version of bitcount.
 *
 * Bit patterns for decimal 15 to 20:
 *
 * 0001 0100 = 20
 * 0001 0011 = 19
 * 0001 0010 = 18
 * 0001 0001 = 17
 * 0001 0000 = 16
 * 0000 1111 = 15
 *
 * Notice 20 & 19 = 16, effectively deleting the 1-bit in the 4's place
 * and leaving only the 1-bit in the 16's place. A quick test of the
 * other values demonstrates this is true for all numbers. Then, consider
 * 16 & 15 = 0, which again deletes the rightmost 1-bit, leaving no more
 * 1-bits to count. The operation was repeated one time for each 1-bit
 * in the original number. Because x &= (x-1) deletes the rightmost 1-bit,
 * it is generalizable that the number of repetitions of this operation
 * required to convert a number to zero is equivalent to the number
 * of 1-bits in the number.
 */

#include <stdio.h>

/* bitcount: count 1 bits in x (faster version) */
int bitcount(unsigned x) {
	int result = 0;
	while (x > 0) {
		result++;
		x &= (x-1);
	}
	return result;
}

int main() {
	unsigned x;
	for (x = 20; x >= 15; x--) {
		printf("%u has %d 1-bits\n", x, bitcount(x));
	}
	for (x = 235; x >= 145; x -= 15) {
		printf("%u has %d 1-bits\n", x, bitcount(x));
	}
}
