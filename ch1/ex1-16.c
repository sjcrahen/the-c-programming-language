/* Prints the length of the longest line of the input.
 * The length of the longest line can be arbitrarily long,
 * however, the printed length is limited to the buffer size.
*/

#include <stdio.h>
#define DEFAULT_SIZE 1000

int getl();
void copy(char to[], char from[]);

char line[DEFAULT_SIZE], longest[DEFAULT_SIZE];

int main() {
	int len, max;

	max = 0;
	while ((len = getl()) > 0)
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	printf("\nlength of longest line is: %d\n", max);
	if (max > 0)
		printf("%s", longest);
	printf("\n");
	return 0;
}

int getl() {
	int c, i = 0;
	while ((c = getchar()) != EOF) {
		if (i < DEFAULT_SIZE - 1)
			line[i] = c;
		i++;
		if (c == '\n')
			break;
	}
	line[i] = '\0';
	return i;	
}

void copy(char to[], char from[]) {
	int i;
	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
