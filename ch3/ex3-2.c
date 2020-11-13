#include <stdio.h>

#define MAX 1000

/* escape: converts newline and tab characters to visible escape sequences
 *         as it copies string t to s
 */
void escape(char s[], char t[]) {
	int c, i, j;
	for (i = 0, j = 0; (c = t[i]) != '\0'; i++) {
		switch (c) {
			case '\n':
				s[j++] = '\\';
				s[j++] = 'n';
				break;
			case '\t':
				s[j++] = '\\';
				s[j++] = 't';
				break;
			default:
				s[j++] = t[i];
				break;
		}
	}
	s[j] = '\0';
}

/* descape: converts visible escape sequences to newline and tab characters
 *          as it copies string t to s
 */
void descape(char s[], char t[]) { 
	int c, i, j;
	for (i = 0, j = 0; (c = t[i]) != '\0'; i++) {
		if (c == '\\') {
			c = t[++i];
			switch (c) {
				case 'n':
					s[j++] = '\n';
					break;
				case 't':
					s[j++] = '\t';
					break;
				default:
					break;
			}
		} else {
			s[j++] = t[i];
		}
	}
	s[j] = '\0';
}

int main() {
	char s1[MAX] = "\0", s2[MAX] = "this\tis a test\nthis is\tthe second line\n", s3[MAX] = "\0";
	printf("string 1 is:\n%s\n", s1);
	printf("string 2 is:\n%s\n", s2);
	printf("string 3 is:\n%s\n", s3);
	printf("\ncopy string 2 to string 1 applying escape function\n");
	escape(s1, s2);
	printf("string 1 is now:\n%s\n", s1);
	printf("\ncopy string 1 to string 3 applying descape function\n");
	descape(s3, s1);
	printf("string 3 is now:\n%s\n", s3);
}
