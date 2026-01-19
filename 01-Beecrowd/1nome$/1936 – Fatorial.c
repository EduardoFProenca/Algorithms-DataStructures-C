
#include <stdio.h>
#include <math.h>

long long int fatorial(int);

int main()
{
	int num, quat = 0, soma = 0;
	int i = 0;
	scanf(" %d", &num);


	for(i = 1; num != 0  ; i++) {
		if( num < fatorial(i) )
			break;
	}

	i =  i - 1;
	soma += fatorial(i);
	quat++;

	for(int j = i ; num != soma; ) {
		if(num  < (soma + fatorial(j)) ) {
			j--;
		}
		else {
			soma += fatorial(j) ;
			quat++;
		}
	}

	printf("%d\n",quat);

	return 0;
}
long long int fatorial(int n)
/* Retorna o fatorial de n */
{	long long int resp;
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