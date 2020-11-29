/* Exercise 4-13 
 *
 * Write a recursive version of reverse()
 * using the itoa() program from ex4-12 to demo new reverse() function
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

void reverse(char s[], int i, int j) {
	int c;
	
	if (i > j)
		return;	
	else {
		// swap char at index i with char at index j of s
		c = s[i];
		s[i] = s[j];
		s[j] = c;
		// recur
		reverse(s, ++i, --j);
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
		reverse(s, 0, strlen(s) - 1);
		return;
	}
	// base case 2
	else if (n == 0) {
		s[i] = '\0';
		reverse(s, 0, strlen(s) - 1);
		return;
	}
	// recursion
	else {
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
