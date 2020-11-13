/* Exercise 3-1 - modified binary search */

#include <stdio.h>
#include <time.h>

int N = 1000000;

/* binsearch function from book, pg. 58 */
int binsearch(int x, int v[], int n) {
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else // found match
			return mid;
	} return -1; // no match
}

/* modified_binsearch exercise 3-1 */
int modified_binsearch(int x, int v[], int n) {
	int low, mid, high;

	low = 0;
	mid = -1;
	high = n - 1;
	while (low <= high && v[mid] != x) {
		mid = (low + high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	if (v[mid] == x)
		return mid;
	else
		return -1;
}

int main() {
	int answer, x = 2377, v[N];
	clock_t start, stop;
	double elapsed;
	for (int i = 0; i < N; i++) {
		v[i] = i;
	}
	// test original binsearch
	start = clock();	
	answer = binsearch(x, v, N);
	stop = clock();
	elapsed = (stop - start);
	printf("using original binsearch:\n");
	printf("%d was found at index: %d in %g clocks\n", x, answer, elapsed);	
	// test modified binsearch
	start = clock();	
	answer = modified_binsearch(x, v, N);
	stop = clock();
	elapsed = (stop - start);
	printf("using modified binsearch:\n");
	printf("%d was found at index: %d in %g clocks\n", x, answer, elapsed);	
}
