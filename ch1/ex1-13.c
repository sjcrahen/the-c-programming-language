#include <stdio.h>

#define TRUE 1
#define FALSE 0

int main() {
	int c, charCount, inWord, maxLength, hiCount;
	int chars[20];
	for (int i = 0; i < 20; i++) {
		chars[i] = 0;
	}

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			if (inWord == TRUE) {
				chars[charCount]++;
				if (chars[charCount] > maxLength)
					maxLength = chars[charCount];
				if (charCount > hiCount)
					hiCount = charCount;
				charCount = 0;
			}
			inWord = FALSE;
		} else if (inWord == FALSE) {
			inWord = TRUE;
		}
		if (inWord == TRUE) {
			charCount++;
		}
	}
	printf("number of words by word length\n\n");
	while (maxLength > 0) {
		for (int i = 1; i <= hiCount; i++) {
			if (chars[i] >= maxLength) {
				printf("* ");
			} else {
				printf("  ");
			}
		}
		printf("\n");
		maxLength--;	
	}
	for (int i = 1; i <= hiCount; i++) {
		printf("%d ", i);
	}
	printf("\n");
	return 0;
}	
