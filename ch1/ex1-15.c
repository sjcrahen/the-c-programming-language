#include <stdio.h>

float calcCelsius(float fahr) {
	return (5.0/9.0) * (fahr-32.0);
}

/* print Fahrenheit-Celsius table
   for fahr = 0, 20, ..., 300; floating-point version */
int main() {
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;	/* lower limit of temperature table */
	upper = 300;	/* upper limit */
	step = 20;	/* step size */

	printf("%s %s\n", "fahr", "celsuis");
	for (fahr = lower; fahr <= upper; fahr += step) {
		celsius = calcCelsius(fahr);
		printf("%3.0f %6.1f\n", fahr, celsius);
	}
} 
