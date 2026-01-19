#include <math.h>
#include <stdio.h>

#define TRUE  1
#define FALSE 0

char is_prime(int);


int main()
{
	int num,velocidade  = 0, quat = 0, dia;
	double hora;
	scanf(" %d", &num);
	int i = 0;


	for(i = num; 10 > quat; i++) {
		if(is_prime(i)) {
			quat++;
			velocidade = i + velocidade;
		}
	}
    
    hora = 60000000 / velocidade;
    dia =   hora / 24;
	printf("%d km/h\n",velocidade );
    printf("%.0f h / %d d\n",hora, dia );

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