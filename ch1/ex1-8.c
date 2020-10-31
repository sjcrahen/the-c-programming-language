/* this program counts blanks, tabs, and newlines */

#include <stdio.h> 

int main() { 
	int c, blankCount, tabCount, newlineCount; 
	blankCount = tabCount = newlineCount = 0;
	while((c = getchar()) != EOF) {
		if (c == ' ')
			blankCount++;
		if (c == '\t')
			tabCount++;
		if (c == '\n')
			newlineCount++;
	}
	printf("file has %d blanks\n", blankCount);
	printf("file has %d tabs\n", tabCount);
	printf("file has %d newlines\n", newlineCount);
	return 0;
}
