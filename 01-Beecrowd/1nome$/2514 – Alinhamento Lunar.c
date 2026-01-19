
#include <stdio.h>
int mdc(int, int );
long long int mmc(int, int );

int main()
{
	int M, L1, L2, L3, res;


	while(	scanf( " %d", &M) != EOF) {

		scanf( " %d %d %d", &L1, &L2, &L3);

		res = mmc(L1,mmc(L2,L3 ) );
		printf("%d\n", res- M);
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

long long int mmc(int a, int b)
/*	Retorna o Minimo Multiplo Comum de a e b
	(Adaptado do tutorial topcoder)
*/
{	return b * a / mdc(a, b);
}