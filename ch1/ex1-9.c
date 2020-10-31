/* Copies input to output, replacing each string of one or more blanks by a single blank */

#include <stdio.h>

int main() {
	int c;

	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			while ((c = getchar()) == ' ') {
				continue;
			}
			printf(" ");	
		}
		putchar(c);
	}
	return 0;
}
