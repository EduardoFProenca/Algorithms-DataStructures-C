#include <stdio.h>
#include <string.h>

long long int fatorial(int n);

int main()
{
	int num;
	char S[16];

	while (1){
	scanf(" %s", S);
	if(S[0] == '0' )
	    break;
	printf( "%lld\n", fatorial(strlen(S) ));
	}
	return 0;
}

long long int fatorial(int n)
{	
long long int resp;
	int c;

	if (n < 0)
		return -1LL;
	else
		if (n == 0)
			return 1LL;
		else
		{	resp = n;
			for (c = n - 1; c > 0; c--)
				resp = resp * c;
				
			return resp;
		}
}