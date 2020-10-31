/* test getchar() != EOF is 0 or 1 
 * demonstrates order of operations
 * correct application is:
 * if ((c = getchar()) != EOF)...
*/

#include <stdio.h>

int main() {
	int c;
	printf("run program missing parentheses to demo error\n");
	while (c = getchar() != EOF) {
		printf("%d\n", c);
	}
	return 0;
}
