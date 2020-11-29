/* Exercise 4-12 
 *
 * Write a recursive version of itoa()
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

void itoa(int i, int n, char s[]) {
	int sign = n;

	// original number was zero 
	if (n == 0 && i == 0) {
		s[i++] = '0';
		s[i] = '\0';
		return;	
	}
	// base case 1
	if (sign < 0 && n / 10 == 0) {
		s[i++] = -(n % 10) + '0';
		s[i++] = '-';
		s[i] = '\0';
		reverse(s);
		return;
	} // base case 2
	else if (n == 0) {
		s[i] = '\0';
		reverse(s);
		return;
	}
	else { // recursion
		if (sign < 0)
			s[i++] = -(n % 10) + '0';
		else
			s[i++] = n % 10 + '0';
		itoa(i, n /= 10, s);	
	}
}

int main() {
	char s[12];
	int n = (int) -1 * pow(2, sizeof(int) * 8 - 1);
	printf("n is: %d\n", n);
	itoa(0, n, s);
	printf("itoa gives: %s\n", s);
	n++;
	printf("n is now: %d\n", n);
	itoa(0, n, s);
	printf("itoa gives: %s\n", s);
	n = (int) pow(2, sizeof(int) * 8 - 1);
	printf("n is now: %d\n", n);
	itoa(0, n, s);
	printf("itoa gives: %s\n", s);
	n = 0;
	printf("n is now: %d\n", n);
	itoa(0, n, s);
	printf("itoa gives: %s\n", s);
	n--;
	printf("n is now: %d\n", n);
	itoa(0, n, s);
	printf("itoa gives: %s\n", s);
	n = 1;
	printf("n is now: %d\n", n);
	itoa(0, n, s);
	printf("itoa gives: %s\n", s);
}
