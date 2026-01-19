
#include <stdio.h>
#include <math.h>

#define TRUE  1
#define FALSE 0

long long int fatorial(int);

int main()
{
	int num, res = 0;
do{
	scanf(" %d", &num);
	
	if(num == 0)
	    break;
	    
	for(int i = 1; num != 0  ; i++) {
		res += ((num % 10)  * fatorial(i));
		num =  num / 10;
	}

	printf("%d\n",res);
    res = 0;
}while( 1 );
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

