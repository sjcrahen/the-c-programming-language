/* Program that replaces spaces with the correct number of tabs and spaces to achieve the same spacing */

#include <stdio.h>

#define DEFAULT_SIZE 1000
#define TAB_STOP 3

int getLine();
void printTabs(int chars, int spaces);
int line[DEFAULT_SIZE];

int main() {
	int len;
	while ((len = getLine()) > 0) {
		int i = 0, c, chars = 0, spaces = 0;
		while ((c = line[i]) != '\0') {
			if (c != ' ') {
				chars++;
				printf("%c", c);
				i++;
			} else {
				do {
					chars++;
					spaces++;
					i++;
				} while ((c = line[i]) == ' ');
				printTabs(chars, spaces);
				spaces = 0;
			}
		}
	}
}

void printTabs(int chars, int spaces) {
	int spacesToNextTabstop;
	while (spaces > 0) {
		spacesToNextTabstop = TAB_STOP - ((chars - spaces) % TAB_STOP);
		if (spaces >= spacesToNextTabstop) {
			printf("\t");
			spaces -= spacesToNextTabstop;
		} else {
			printf(" ");
			spaces--;
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
