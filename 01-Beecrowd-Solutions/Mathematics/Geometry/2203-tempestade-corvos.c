/*
Beecrowd : 2203 - Tempestade de Corvos
https://judge.beecrowd.com/pt/problems/view/2203

**Explicação do Código:**
Este código simula um cenário de movimento e alcance para determinar se um alvo é atingido.
Ele processa entradas contendo coordenadas de pontos, uma velocidade e raios de alcance.

A lógica implementada é a seguinte:
1. Lê as coordenadas (x, y) de dois pontos (p1 e p2).
2. Lê um valor de velocidade (speed) e dois valores de raio (radius1 e radius2).
3. Calcula um valor `totalDist` baseado na fórmula do código original:
   Soma-se a distância percorrida pela velocidade (considerando um tempo fixo de 1.5)
   com a distância euclidiana entre os dois pontos p1 e p2.
4. Verifica se essa `totalDist` é menor ou igual à soma dos raios (radius1 + radius2).
   - Se for verdadeiro, imprime "Y".
   - Caso contrário, imprime "N".
*/

#include <math.h>
#include <stdio.h>

typedef struct {
    double x, y;
} TPoint;

double CalculateDistance(TPoint, TPoint);

int main()
{
    TPoint p1, p2;
    int speed, radius1, radius2;
    double totalDist;

    while( scanf( " %lf %lf %lf %lf %d %d %d ", &p1.x, &p1.y, &p2.x, &p2.y, &speed, &radius1, &radius2) != EOF )
    {
        // Cálculo da distância total mantendo a lógica original: (velocidade * 1.5) + distância euclidiana
        totalDist = (speed * 1.5) + CalculateDistance(p1, p2);
        
        // Verificação condicional
        if(totalDist <= radius1 + radius2)
            printf("Y\n");
        else
            printf("N\n");
    }
    return 0;
}

// Função auxiliar para calcular a distância euclidiana entre dois pontos
double CalculateDistance(TPoint p1, TPoint p2)
/* Retorna a distância entre dois pontos no plano */
{
    return sqrt(pow(p1.x - p2.x, 2.0) + pow(p1.y - p2.y, 2.0));
}