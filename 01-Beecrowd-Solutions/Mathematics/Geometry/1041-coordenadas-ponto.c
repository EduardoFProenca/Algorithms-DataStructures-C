/*
Beecrowd : 1041 - Coordenadas de um Ponto
https://judge.beecrowd.com/pt/problems/view/1041

**Explicação do Código:**
Este programa lê as coordenadas (X, Y) de um ponto no plano cartesiano e determina sua localização específica.
A verificação é feita da seguinte forma:
1. Se X é 0 e Y não é 0, o ponto está sobre o Eixo Y.
2. Se Y é 0 e X não é 0, o ponto está sobre o Eixo X.
3. Caso contrário, utiliza-se a função auxiliar para identificar em qual Quadrante (1, 2, 3 ou 4)
   o ponto se encontra, ou se é a Origem.
*/

#include <math.h>
#include <stdio.h>

#define TRUE  1
#define FALSE 0

typedef struct {
    double x, y;
} TPoint;

// Protótipos das funções
int GetQuadrant(TPoint);

int main()
{
    TPoint point;

    // Array com as strings de resultado correspondentes aos índices retornados
    char quadrantNames[5][10] = {"Origem", "Q1", "Q2", "Q3", "Q4"};

    scanf(" %lf %lf", &point.x, &point.y);

    // Verifica se está nos eixos antes de verificar os quadrantes
    if(point.x == 0 && point.y != 0)
        printf("Eixo Y\n");
    else if(point.x != 0 && point.y == 0)
        printf("Eixo X\n");
    else
        // Se não está nos eixos, imprime o quadrante ou a origem baseado no índice
        printf("%s\n", quadrantNames[GetQuadrant(point)]);

    return 0;
}

int GetQuadrant(TPoint p)
/* Determina o quadrante (1, 2, 3 ou 4) de um ponto no plano.
   Se origem, retorna 0. Retorna 5 ou 6 se estiver sobre um dos eixos. */
{	
    if (p.x > 0.0 && p.y > 0.0)
        return 1; // Q1
    if (p.x < 0.0 && p.y > 0.0)
        return 2; // Q2
    if (p.x < 0.0 && p.y < 0.0)
        return 3; // Q3
    if (p.x > 0.0 && p.y < 0.0)
        return 4; // Q4
    
    // Nota: Os retornos 5 e 6 abaixo não são alcançados pelo fluxo atual da main,
    // pois a main verifica os eixos antes de chamar esta função.
    if (p.x > 0.0 && p.y == 0.0)
        return 5;
    if (p.x == 0.0 && p.y > 0.0)
        return 6;

    return 0; // Origem
}