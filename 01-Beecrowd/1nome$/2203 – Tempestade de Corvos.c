#include <math.h>
#include <stdio.h>

typedef struct {
	double x, y;
} TPonto;

double distPontos2d(TPonto, TPonto );

int main()
{
	TPonto p1, p2;

	int v, r1, r2;
    double dist;
	while( scanf( " %lf %lf %lf %lf %d %d %d ", &p1.x, &p1.y, &p2.x, &p2.y, &v, &r1, &r2) != EOF )
	{

        dist = (v*1.5) + distPontos2d( p1,  p2);
        
        if(dist <= r1+ r2 )
            printf("Y\n");
        else
            printf("N\n");
	}
	return 0;
}

double distPontos2d(TPonto p1, TPonto p2)
/* Retorna a distC"ncia entre dois pontos no plano */
{	return sqrt(pow(p1.x - p2.x, 2.0) + pow(p1.y - p2.y, 2.0));
}
