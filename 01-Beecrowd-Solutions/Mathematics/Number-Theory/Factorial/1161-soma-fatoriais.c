#include <stdio.h>

long long int fatorial(int n);

int main()
{
	int M, N;

	while (scanf(" %d %d", &M, &N) != EOF  )
		printf( "%lld\n", fatorial(M) + fatorial(N));

	return 0;
}

long long int fatorial(int n)
{
	long long int resp;
	int c;

	if (n < 0)
		return -1LL;
	else if (n == 0)
		return 1LL;
	else
	{	resp = n;
		for (c = n - 1; c > 0; c--)
			resp = resp * c;

		return resp;
	}
}