/* Program to display ranges of different types */

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {

	printf("--- Signed Ranges ---\n");
	printf("char: %d to %d\n", SCHAR_MIN, SCHAR_MAX);
	printf("short: %d to %d\n", SHRT_MIN, SHRT_MAX);
	printf("int: %d to %d\n", INT_MIN, INT_MAX);
	printf("long: %ld to %ld\n", LONG_MIN, LONG_MAX);

	printf("\n--- Unsigned Ranges ---\n");
	printf("char: 0 to %u\n", UCHAR_MAX);
	printf("short: 0 to %u\n", USHRT_MAX);
	printf("int: 0 to %u\n", UINT_MAX);
	printf("long: 0 to %lu\n", ULONG_MAX);	

	printf("\n--- Float Ranges ---\n");
	printf("float: %e to %e\n", FLT_MIN, FLT_MAX);
	printf("double: %e to %e\n", DBL_MIN, DBL_MAX);
	printf("\n");
}
