#include <stdio.h>

long long int mmc(int, int );
int mdc(int, int );

int main()
{
	int N, F1,F2;
	long long int res= 0 ;
	scanf("%d", &N);
	scanf("%d", &F1);
	res = F1;

	for(int i = 1; i < N ; i++) {
		scanf(" %d", &F2);
		res = mmc(res, F2 );

	}
	printf("%lld\n", res);

	return 0;
}

long long int mmc(int a, int b)
/*	Retorna o Minimo Multiplo Comum de a e b
	(Adaptado do tutorial topcoder)
*/
{	return b * a / mdc(a, b);
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

