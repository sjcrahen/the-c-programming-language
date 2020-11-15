/* Exercise 3-4
 *
 * Book version of itoa() does not handle largest negative number
 * equal to -1 * pow(2, wordsize - 1).
 *
 * The problem results from overflow when the number is converted from
 * negative to positive: n = -n;
 * 
 * The simplest solution is to process negative numbers differently
 * from positive numbers, rather than convert to positive, to prevent
 * overflow.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

void reverse(char s[]) {
	int c, i, j;

	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

void itoa(int n, char s[]) {
	int i, sign;

	i = 0;
	if ((sign = n) < 0) {
		// n = -n;
		do { // process negative numbers
			s[i++] = -(n % 10) + '0'; // negate the popped digit
		} while ((n /= 10) < 0); // test whether number is still negative
	} else { // process positive numbers
		do {
			s[i++] = n % 10 + '0';
		} while ((n /= 10) > 0);
	}
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

int main() {
	char s[12];
	int n = (int) -1 * pow(2, sizeof(int) * 8 - 1);
	printf("n is: %d\n", n);
	itoa(n, s);
	printf("itoa gives: %s\n", s);
	n++;
	printf("n is now: %d\n", n);
	itoa(n, s);
	printf("itoa gives: %s\n", s);
	n = (int) pow(2, sizeof(int) * 8 - 1);
	printf("n is now: %d\n", n);
	itoa(n, s);
	printf("itoa gives: %s\n", s);
	n = 0;
	printf("n is now: %d\n", n);
	itoa(n, s);
	printf("itoa gives: %s\n", s);
	n--;
	printf("n is now: %d\n", n);
	itoa(n, s);
	printf("itoa gives: %s\n", s);
	n = 1;
	printf("n is now: %d\n", n);
	itoa(n, s);
	printf("itoa gives: %s\n", s);
}
