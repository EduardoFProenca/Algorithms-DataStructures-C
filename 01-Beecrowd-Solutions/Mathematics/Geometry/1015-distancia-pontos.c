/*
Beecrowd : 1015 - Distância Entre Dois Pontos
https://judge.beecrowd.com/pt/problems/view/1015

**Explicação do Código:**
Este programa calcula a distância euclidiana entre dois pontos em um plano cartesiano 2D.
A fórmula utilizada é derivada do Teorema de Pitágoras:
Distância = raiz_quadrada((x2 - x1)^2 + (y2 - y1)^2).

O processo é o seguinte:
1. Lê as coordenadas (x, y) de dois pontos (p1 e p2).
2. Aplica a fórmula matemática para calcular a distância entre eles.
3. Imprime o resultado com precisão de 4 casas decimais.
*/

#include <stdio.h>
#include <math.h>

typedef struct {
    double x, y;
} TPoint;

// Protótipo da função
double CalculateDistance(TPoint, TPoint);

int main()
{
     TPoint p1, p2;

    // Leitura das coordenadas dos dois pontos: x1 y1 x2 y2
    scanf("%lf %lf %lf %lf", &p1.x, &p1.y, &p2.x, &p2.y);

    // Impressão do resultado calculado pela função
    printf("%.4f\n", CalculateDistance(p1,p2));

    return 0;
}

// Função que recebe dois pontos e retorna a distância entre eles
double CalculateDistance(TPoint p1, TPoint p2)
/* Retorna a distância entre dois pontos no plano */
{
    return sqrt(pow(p1.x - p2.x, 2.0) + pow(p1.y - p2.y, 2.0));
}