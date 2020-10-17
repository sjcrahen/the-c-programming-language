#include <stdio.h>

int main() {
	FILE *input_file_p;
	input_file_p = fopen("ex1-6.c", "r");
	int c;
	printf("run program missing parentheses to demo error\n");
	while (c = getc(input_file_p) != EOF) {
		putc(c, stdout);
	}
	fclose(input_file_p);
	return 0;
}
