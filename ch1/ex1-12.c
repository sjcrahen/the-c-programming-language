#include <stdio.h>

int main() {
	int c; 

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			while (c == ' ' || c == '\n' || c == '\t') 
				c = getchar();
			printf("\n");
		}
		putchar(c);
	}
	return 0;
}
