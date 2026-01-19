
#include <stdio.h>
#include <math.h>

#define TRUE  1
#define FALSE 0

char is_prime(int n);

int main()
{
    int num;
    while (scanf(" %d", &num) != EOF) {
        int p = 0;  
        int m = 0;  
        int i;

        for (i = 2; i <= num; i++) {
            if (is_prime(i)) {
                if (p != 0) {
                    int d = i - p;
                    if (d > m) 
                        m = d;
                }
                p = i;
            }
        }

        printf("%d\n", m);
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