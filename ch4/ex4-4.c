/* Exercise 4-4 base code adapted from text pp. 76-79
 * Tasks:
 * 1. add peek command to print top of stack
 * 2. add dup command to duplicate top of stack
 * 3. add swap command to swap top two elements of stack
 * 4. add clear command to clear stack
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXOP 100
#define NUMBER '0'
#define COMMAND '1'

int getop(char []);
void push(double);
double pop(void);
double peek(void);
void duptop(void);
void swaptop(void);
void clear(void);

int main() {
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
		case COMMAND:
			if (strcmp(s, "peek") == 0)
				peek();
			else if (strcmp(s, "dup") == 0)
				duptop();
			else if (strcmp(s, "swap") == 0)
				swaptop();
			else if (strcmp(s, "clear") == 0)
				clear();
			else
				printf("error: unknown command %s\n", s);
			break;
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();	
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break;
		case '%':
			op2 = pop();
			if (op2 != 0.0) {
				push((int)pop() % (int)op2);
			}
			else
				printf("error: zero divisor\n");
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}
	return 0;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f) {
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

double pop(void) {
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

double peek(void) {
	if (sp > 0) {
		printf("top: %g\n", val[sp-1]);
		return val[sp-1];
	} else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

void duptop(void) {
	if (sp > 0)
		push(val[sp-1]);
	else
		printf("error: stack empty\n");
}

void swaptop(void) {
	if (sp > 1) {
		double temp1 = pop();
		double temp2 = pop();
		push(temp1);
		push(temp2);
	} else
		printf("error: too few elements on stack to swap\n");
}

void clear(void) {
	while (sp > 0)
		pop();
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void) {
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

#include <ctype.h>

int getop(char s[]) {
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	i = 0;
	if (isalpha(c)) {
		s[i] = tolower(c);
		while (isalpha(c = getch()))
			s[++i] = tolower(c);
		s[++i] = '\0';
		if (c != EOF)
			ungetch(c);
		return COMMAND;
	}
	if (!isdigit(c) && c != '.' && c != '-') 
		return c;
	if (c == '-' && !isdigit(s[++i] = c = getch())) {
		s[i] = '\0';
		if (c != EOF)
			ungetch(c);
		return '-';
	}
	if (isdigit(c))
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}
