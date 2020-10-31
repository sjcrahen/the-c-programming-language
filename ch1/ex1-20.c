/* Program that replaces tabs in the input with blanks to space to the next tab stop */

#include <stdio.h>

#define DEFAULT_SIZE 1000
#define TAB_STOP 3

int getLine();

int line[DEFAULT_SIZE];

int main() {
	int len;
	while ((len = getLine()) > 0) {
		int i = 0, c, precedingChars = 0, count = 0;
		while ((c = line[i]) != '\0') {
			if (c != '\t') {
				precedingChars++;
				printf("%c", c);
			} else {
				count = TAB_STOP - (precedingChars % TAB_STOP);
				while (count > 0) {
					printf(" ");
					count--;
				}
				precedingChars = 0;
			}
			i++;
		}
	}
}

int getLine() {
	int i = 0, c;
	while (i < DEFAULT_SIZE - 2 && (c = getchar()) != EOF && c != '\n') {
		line[i] = c;
		i++;
	}
	if (c == '\n') {
		line[i] = c;
		i++;
	}
	line[i] = '\0';
	return i;
}
