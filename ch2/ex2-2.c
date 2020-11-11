/* write a loop equivelant to this for loop without using && or ||
 *
 * for (int i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF: ++i)
 * 	s[i] = c;
 *
 *
 * Answer:
 *
 * for (int i = 0; i < lim - 1; ++i) {
 * 	if ((c = getchar() != '\n')
 *			if (c != EOF)
 *          s[i] = c;
 * }
