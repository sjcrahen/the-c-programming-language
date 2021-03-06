/* print celsius to fahrenheit temperature conversion table */

#include <stdio.h>

/* print Fahrenheit-Celsius table
   for fahr = 0, 20, ..., 300; floating-point version */
int main() {
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;	/* lower limit of temperature table */
	upper = 300;	/* upper limit */
	step = 20;	/* step size */

	printf("%7s %6s\n", "celsius", "fahr");
	celsius = lower;
	while (celsius <= upper) {
		fahr = 32.0 + celsius * (9.0/5.0);
		printf("%7.0f %6.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
} 
