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
