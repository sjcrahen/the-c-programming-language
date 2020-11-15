/* Exercise 3-5 */

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

/* itob: converts the integer n into a signed, base b character representation
 * in the string s.
 */
void itob(int n, char s[], int b) {
	int i, sign;

	i = 0;
	if ((sign = n) < 0) { // process negative numbers
		do {
			if (-(n % b) < 10)
				s[i++] = -(n % b) + '0';
			else
				s[i++] = -(n % b) - 10 + 'A';
		} while ((n /= b) < 0);
	} else { // process positive numbers
		do {
			if (n % b < 10)
				s[i++] = n % b + '0';
			else
				s[i++] = n % b - 10 + 'A';
		} while ((n /= b) > 0);
	}
	if (b == 8) // add prefix for octal
		s[i++] = '0';
	if (b == 16) { // add prefix for hex
		s[i++] = 'x';
		s[i++] = '0';
	}
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

int main() {
	char s[32];
	printf("test to binary: ");
	itob(4352, s, 2);
	printf("%s\n", s);
	printf("test to octal: ");
	itob(755, s, 8);
	printf("%s\n", s);
	printf("test to hex: ");
	itob(94634, s, 16);
	printf("%s\n", s);
}
