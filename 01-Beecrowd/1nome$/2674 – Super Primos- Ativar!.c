
#include <stdio.h>
#include <math.h>

#define TRUE  1
#define FALSE 0

char is_prime(int n);

char is_prime(int n);

int main()
{
	int num, temp;

	while( scanf(" %d", &num) != EOF) {

		if (is_prime(num) ) {
			temp = num;
			while(temp > 0) {
				if (is_prime(temp % 10)) {
					temp = temp / 10;
				} else {
					printf("Primo\n");
					break;
				}
			}
			if (temp == 0)
				printf("Super\n");

		} else
			printf("Nada\n");
	}
	return 0;
}


char is_prime(int n)
/* Retorna TRUE se n for um nC:mero primo */
{	int p, maxP = sqrt(n) + 2;

	if (n < 0) return is_prime(-n);
	if (n < 5 || !(n % 2) || !(n % 3)) return (n == 2 || n == 3);

	for (p = 5; p < maxP; p += 6)
		if ((!(n % p)) || (!(n % (p + 2)))) return FALSE;

	return TRUE;
}