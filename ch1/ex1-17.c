/* Prints all lines of the input that are longer than 80 characters */

#include <stdio.h>
#define DEFAULT_SIZE 1000

int getl();

char line[DEFAULT_SIZE];

int main() {
	int len;

	while ((len = getl()) > 0)
		if (len > 80) {
			for (int i = 0; i < len; i++)
				printf("%c", line[i]);
		}
	printf("\n");
	return 0;
}

int getl() {
	int c, i = 0;
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
