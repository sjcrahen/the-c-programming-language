#include <stdio.h>

int main() {
	int c;
	printf("run program missing parentheses to demo error\n");
	while (c = getchar() != EOF) {
		printf("%d\n", c);
	}
	return 0;
}
