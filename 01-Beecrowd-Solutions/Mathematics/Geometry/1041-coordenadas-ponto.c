#include <math.h>
#include <stdio.h>

#define TRUE  1
#define FALSE 0

typedef struct {
	double x, y;
} TPonto;

char is_prime(int);

int quadPonto2d(TPonto);

int main()
{

	TPonto p1;

	char res[5][10] = {"Origem", "Q1", "Q2", "Q3", "Q4"};
	scanf(" %lf %lf", &p1.x, &p1.y);

	if(p1.x == 0 && p1.y != 0)
		printf("Eixo Y\n");
	else if(p1.x != 0 && p1.y == 0)
		printf("Eixo X\n");
	else
		printf("%s\n", res[quadPonto2d(p1)]);


	return 0;
}


int quadPonto2d(TPonto p)
/* Determina o quadrante (1, 2, 3 ou 4) de um ponto no plano.
   Se origem, retorna 0. Retorna 5 ou 6 se estiver sobre um dos eixos. */
{	if (p.x > 0.0 && p.y > 0.0)
		return 1;
	if (p.x < 0.0 && p.y > 0.0)
		return 2;
	if (p.x < 0.0 && p.y < 0.0)
		return 3;
	if (p.x > 0.0 && p.y < 0.0)
		return 4;
	if (p.x > 0.0 && p.y == 0.0)
		return 5;
	if (p.x == 0.0 && p.y > 0.0)
		return 6;

	return 0;
}