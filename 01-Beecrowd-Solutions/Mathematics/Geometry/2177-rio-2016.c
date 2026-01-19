#include <stdio.h>
#include <math.h>

typedef struct {
    double x, y;
    int i; 
} TPonto;

double distPontos2d(TPonto , TPonto );

int main() {
    TPonto m, p;
    
    scanf("%lf %lf %d", &m.x, &m.y, &m.i);

    int validos[m.i];
    int count = 0;

    for (int j = 0; j < m.i; j++) {
        scanf("%lf %lf %d", &p.x, &p.y, &p.i);

        double d = distPontos2d(m, p);

        if (d < p.i) {
            validos[count] = j + 1;  
            count++;
        }
    }

    if (count == 0) {
        printf("-1\n");
    } else {
        for (int i = 0; i < count; i++) {
            if (i > 0) printf(" ");
            printf("%d", validos[i]);
        }
        printf("\n");
    }

    return 0;
}

double distPontos2d(TPonto p1, TPonto p2)
/* Retorna a distC"ncia entre dois pontos no plano */
{	return sqrt(pow(p1.x - p2.x, 2.0) + pow(p1.y - p2.y, 2.0));
}