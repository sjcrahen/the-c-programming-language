/* Exercise 4-2 */

#include <stdio.h>
#include <ctype.h>
#include <math.h>

/* extended atof to handle scientific notation */
double atof(char s[]) {
	double val, power;
	int i, sign, esign, eval;

	for (i = 0; isspace(s[i]); i++)
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	if (s[i] == 'e' || s[i] == 'E') { // scientific notation
		i++;
		esign = (s[i] == '-') ? -1 : 1; // handle negative powers of ten
		if (s[i] == '+' || s[i] == '-')
			i++;
		for (eval = 0; isdigit(s[i]); i++) // calculate power of ten
			eval = 10 * eval + (s[i] - '0');		
		power /= pow(10, esign * eval); // adjust power by power of ten
	}
	return sign * val / power;
}

int main() {
	printf("-435.79 %g\n", atof("-435.79"));
	printf("-3.256 %g\n", atof("-325.6e-2"));
	printf("4.5865 %g\n", atof("45865E-4"));
	printf("835984 %g\n", atof("8.35984e+5"));
	printf("567 %g\n", atof("5.67e2"));
}
