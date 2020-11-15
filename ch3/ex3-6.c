/* Exercise 3-6 */

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

/* itoa: convert int n to character string s with minimum width w */
void itoa(int n, char s[], int w) {
	int i, sign;

	i = 0;
	if ((sign = n) < 0) {
		do { 
			s[i++] = -(n % 10) + '0'; 
		} while ((n /= 10) < 0); 
	} else { 
		do {
			s[i++] = n % 10 + '0';
		} while ((n /= 10) > 0);
	}
	if (sign < 0)
		s[i++] = '-';
	while (i < w) // pad string to match width w
		s[i++] = ' ';
	s[i] = '\0';
	reverse(s);
}

int main() {
	char s[12];
	int n = (int) -1 * pow(2, sizeof(int) * 8 - 1);
	printf("n is: %d\n", n);
	itoa(n, s, 5);
	printf("itoa gives: %s\n", s);
	n++;
	printf("n is now: %d\n", n);
	itoa(n, s, 5);
	printf("itoa gives: %s\n", s);
	n = (int) pow(2, sizeof(int) * 8 - 1);
	printf("n is now: %d\n", n);
	itoa(n, s, 5);
	printf("itoa gives: %s\n", s);
	n = 0;
	printf("n is now: %d\n", n);
	itoa(n, s, 5);
	printf("itoa gives: %s\n", s);
	n--;
	printf("n is now: %d\n", n);
	itoa(n, s, 5);
	printf("itoa gives: %s\n", s);
	n = 1;
	printf("n is now: %d\n", n);
	itoa(n, s, 5);
	printf("itoa gives: %s\n", s);
}
