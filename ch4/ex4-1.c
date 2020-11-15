/* Exercise 4-1 */

#include <stdio.h>

/* strindex: returns the position of the rightmost occurrence of t in s */
int strindex(char s[], char t[]) {
	int i, j, k, index = -1;

	for (i = 0; s[i] != '\0'; i++) {
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			if (i > index)
				index = i;
	}
	return index;
}

int main() {
	char string[] = "this is a test string\nthis string will test the\nfunction strindex";
	char pattern[] = "stri";
	printf("string is:\n\"%s\"\n", string);
	printf("find the pattern: \"%s\"\n", pattern);
	int index = strindex(string, pattern);
	printf("found at index %d\n", index);
}
