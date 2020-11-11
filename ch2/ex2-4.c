/* program which deletes each character in s1 that matches any character in s2 */

#include <stdio.h>

void squeeze(char s1[], char s2[]) {
	int i, j, k, match;

	for (i = j = 0; s1[i] != '\0'; i++) {
		match = 0;
		for (k = 0; s2[k] != '\0'; k++) {
			if (s1[i] == s2[k]) {
				match++;
				break;
			}
		}
		if (match == 0) {
			s1[j++] = s1[i];
		}	
	}
	s1[j] = '\0';
}

int main() {
	char s1[] = "test string, remove all vowels";
	char s2[] = "aeiou";
	printf("test string is: %s", s1);
	squeeze(s1, s2);
	printf("\nnew string is: %s\n", s1);
}	
