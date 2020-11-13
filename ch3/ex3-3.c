/* Exercise 3-3 */

#include <stdio.h>
#include <ctype.h>

#define MAX 1000

/* expand: expands shorthand notation like a-z in the string s1 into the
 * equivalent complete list abc...xyz in s2. Handles lower & upper case
 * letters and digits.
 */
void expand(char s1[], char s2[]) {
	int i, j, c;

	s2[0] = s1[0];
	for (i = 1, j = 1; (c = s1[i]) != '\0'; i++) {
		if (c == '-' && isalnum(s1[i-1]) && isalnum(s1[i+1])) {
			if (islower(s1[i-1]) && islower(s1[i+1]) && s1[i-1] < s1[i+1]) {
				for (int k = s1[i-1] + 1; k < s1[i+1]; k++) {
					s2[j++] = k;
				}	
			} else if (isupper(s1[i-1]) && isupper(s1[i+1]) && s1[i-1] < s1[i+1]) {
				for (int k = s1[i-1] + 1; k < s1[i+1]; k++) {
					s2[j++] = k;
				}	
			} else if (isdigit(s1[i-1]) && isdigit(s1[i+1]) && s1[i-1] < s1[i+1]) {
				for (int k = s1[i-1] + 1; k < s1[i+1]; k++) {
					s2[j++] = k;
				}	
			} else {
				s2[j++] = s1[i];
			}
		} else {
			s2[j++] = s1[i];
		}	
	}
	s2[j] = '\0';
}

int main() {
	char a[] = "a-zA-Z0-9";
	char b[MAX] = "\0";
	expand(a, b);
	printf("string is: %s\nexpanded is: %s\n", a, b);	
	char c[] = "-g-m-q test 3-4-7 test B-L-";
	char d[MAX] = "\0";
	expand(c, d);
	printf("\nstring is: %s\nexpanded is: %s\n", c, d);
	char e[] = "-m-g-- test 9-4- out of order Z--G double dash a-5G-b-9";
	char f[MAX] = "\0";
	expand(e, f);
	printf("\nstring is: %s\nexpanded is: %s\n", e, f);
}
