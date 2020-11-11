/* Program to convert a string of hexadecimal digits to an int */

#include <stdio.h>
#include <stdlib.h>

int htoi(char *s) {
	int i, c, n = 0;

	if (s[0] != '0' || (s[1] != 'x' && s[1] != 'X')) {
		printf("Must input a hexadecimal number that begins with 0x or 0X... ");
		return -1;
	} else {
		i = 2;
		while ((c = s[i++]) != '\0') {
			if (c >= '0' && c <= '9')
				n = 16 * n + (c - '0');
			else if (c >= 'A' && c <= 'F')
				n = 16 * n + (10 + c - 'A');
			else if (c >= 'a' && c <= 'f')
				n = 16 * n + (10 + c - 'a');
			else {
				printf("Must input a hexadecimal number with digits (0 - 9) or letters (a - f or A - F)... ");
				return -1;
			}
		}
		return n;
	}			
}

int main() {
	printf("test \"x12\"... ");
	printf("%d\n", htoi("x12"));	
	printf("test \"012\"... ");
	printf("%d\n", htoi("012"));
	printf("test \"0x12a4\"... ");
	printf("%d\n", htoi("0x12a4"));
	printf("test \"0X62D3\"... ");
	printf("%d\n", htoi("0X62D3"));
	printf("test \"0x4bef\"... ");
	printf("%d\n", htoi("0x4bef"));
	printf("test \"0XfFfF\"... ");
	printf("%d\n", htoi("0XfFfF"));
	printf("test \"0x1r25\"... ");
	printf("%d\n", htoi("0x1r25"));
}
