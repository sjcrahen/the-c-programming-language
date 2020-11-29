#include <stdio.h>

#define swap(t, x, y) { t temp = x; x = y; y = temp; }

int main() {
	int m, n;

	m = 5;
	n = 10;

	printf("m is %d, n is %d\n", m, n);

	swap(int, m, n);
	printf("after swap:\n");
	printf("m is %d, n is %d\n", m, n);
}
