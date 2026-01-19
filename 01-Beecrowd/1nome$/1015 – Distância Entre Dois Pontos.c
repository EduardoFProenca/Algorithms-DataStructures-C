
#include <stdio.h>
#include <math.h>

typedef struct {
	double x, y;
} TPonto;


double distPontos2d(TPonto, TPonto);



int main()
{
     TPonto p1, p2;

    scanf("%lf %lf %lf %lf", &p1.x, &p1.y, &p2.x, &p2.y);

	printf("%.4f\n", distPontos2d(p1,p2));

	return 0;
}

double distPontos2d(TPonto p1, TPonto p2)
/* Retorna a distC"ncia entre dois pontos no plano */
{
	return sqrt(pow(p1.x - p2.x, 2.0) + pow(p1.y - p2.y, 2.0));
}