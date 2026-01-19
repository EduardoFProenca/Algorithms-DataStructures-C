
#include <stdio.h>
#include <math.h>

#define TRUE  1
#define FALSE 0

char is_prime(int n);

int main(int argc, char *argv[])
{
	int num;

	scanf(" %d", &num);

	if( 5  <=  num &&  num <= 1000  ) {
		while(num > 0) {
			if (is_prime(num) && is_prime(num- 2)) {

				break;
			}
			num--;
		}
		printf("%d %d\n", num - 2, num);
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