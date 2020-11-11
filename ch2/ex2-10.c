/* function lower() rewritten to use a conditional expression */

#include <stdio.h>

/* lower: convert c to lower case */
int lower(int c) {
	return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}

int main() {
	char s[] = "THIS IS A TEST STRING. CONVERTED TO LOWER CASE.";
	printf("test string: %s\n", s);
	for (int i = 0; s[i] != '\0'; i++) {
		s[i] = lower(s[i]);
	}
	printf("test string converted to lower case: %s\n", s);
}
