#include <stdio.h>

int mdc(int, int );

int main()
{
	int N, F1,F2;
	scanf(" %d", &N);

	for(int i = 0; i < N ; i++) {
		scanf(" %d %d", &F1, &F2);

		printf("%d\n", mdc(F1,F2));
	}
	return 0;
}

int mdc(int m, int n)
/* Retorna o MC!ximo Divisor Comum de m e n */
{	if (m < 0) m = -m;
	if (n < 0) n = -n;

	if (m % n == 0)
		return n;
	else
		return mdc(n, m % n);
}
