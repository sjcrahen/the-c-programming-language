#include <stdio.h>
#define DEFAULT_SIZE 1000

int copyLine();

char line[DEFAULT_SIZE];

int main() {
	int len, i;

	while ((len = copyLine()) > 0) {
		i = len - 1;
		while (line[i] == '\n' || line[i] == '\t' || line[i] == ' ') {
			i--;	
		}
		if (i >= 0) {
			for (int j = 0; j < i + 1; j++) {
				printf("%c", line[j]);
			}
			printf("\n");
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
