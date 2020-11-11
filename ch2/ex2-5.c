/*
 * program that returns the first location in s1 where any character from s2 occurs,
 * or -1 if s1 contains no characters from s2
 */

#include <stdio.h>

int any(char s1[], char s2[]) {
	int i, j;

	for (i = 0; s1[i] != '\0'; i++) {
		for (j = 0; s2[j] != '\0'; j++) {
			if (s1[i] == s2[j])
				return i;
		}
	}
	return -1;
}

int main() {
	printf("--- test case 1 (s1 contains char from s2) ---\n");
	char s1[] = "string";
	char s2[] = "aeiou";
	printf("s1: %s\n", s1);
	printf("s2: %s\n", s2);	
	printf("s1 contains char from s2 at index: %d\n", any(s1, s2));

	printf("\n--- test case 2 (s1 does not contain char from s2) ---\n");
	char s3[] = "bcdfghjklmnpqrstvwxyz";
	char s4[] = "aeiou";
	printf("s1: %s\n", s3);
	printf("s2: %s\n", s4);
	printf("s1 contains char from s2 at index: %d\n", any(s3, s4));
}
