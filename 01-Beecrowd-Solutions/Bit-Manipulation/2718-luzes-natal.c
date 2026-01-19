
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{

	char binaria [1001];
	unsigned long long n, x ;
	scanf(" %llu", &n);
	for(int i = 0; i < n ; i++) {
		scanf(" %llu", &x);

		int j;
		for( j= 0 ; x != 0 ; j++) {
			binaria [j] = (x % 2) + '0';
			x = x /2;
		}
		binaria [j]  = '\0';

		int queiMaior = 0, queiMenor = 0;
		for (int t = 0; t < strlen(binaria); t++) {
			if(binaria [t] == '1')
				queiMaior++;
			else {
				if (queiMenor < queiMaior)
					queiMenor = queiMaior;
				queiMaior = 0;
			}


		}
		if (queiMaior > queiMenor)
			queiMenor = queiMaior;

		printf("%d\n", queiMenor );
	}
	return 0;
}

