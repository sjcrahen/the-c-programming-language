/* Prints a histogram of the frequencies of characters in the input */

#include <stdio.h>

int main() {
	int c, hiCount = 0;
	int chars[256];
	for (int i = 0; i < 256; i++) {
		chars[i] = 0;
	}

	while ((c = getchar()) != EOF) {
		chars[c]++;
		if (chars[c] > hiCount && c > 32 && c < 127)
			hiCount = chars[c];
	}
	printf("character counts\n\n");
	while (hiCount > 0) {
		for (int i = 33; i < 127; i++) {
			if (chars[i] >= hiCount) 
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
		hiCount--;
	}
	for (int i = 33; i < 127; i++) {
		printf("%c", i);
	}
	printf("\n");
	return 0;
}
