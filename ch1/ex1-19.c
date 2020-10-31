/* Program to reverse the input */

#include <stdio.h>
#define DEFAULT_SIZE 1000

int copyLine();
void reverse(char s[], int length);

char line[DEFAULT_SIZE];

int main() {
	int len, i;

	while ((len = copyLine()) > 0) {
		reverse(line, len);
		i = 0;
		while (line[i] != '\0') {
			printf("%c", line[i]);
			i++;
		}
	}
	return 0;
}

int copyLine() {
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

void reverse(char s[], int length) {
	int temp, i = 0, j = length - 2;
	while (j > i) {
		temp = line[i];
		line[i] = line[j];
		line[j] = temp;
		i++;
		j--;
	}
}
