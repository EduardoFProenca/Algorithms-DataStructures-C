/*
Beecrowd : 2514 - Alinhamento Lunar
https://judge.beecrowd.com/pt/problems/view/2514

**Explicação do Código:**
Este programa calcula o próximo dia em que três luas estarão alinhadas, dado o dia atual
e o período orbital de cada lua.
O problema é resolvido matematicamente calculando o Mínimo Múltiplo Comum (MMC ou LCM)
dos três períodos.

A lógica implementada é:
1. Lê o valor inicial M (dia atual).
2. Lê os três períodos L1, L2 e L3.
3. Calcula o MMC dos três períodos. Como o MMC é associativo, calculamos MMC(L1, L2) e
   depois o MMC desse resultado com L3.
4. Imprime a diferença entre o alinhamento (MMC) e o dia inicial M.
*/

#include <stdio.h>

// Protótipos das funções
int CalculateGCD(int, int);
long long int CalculateLCM(int, int);

int main()
{
    int startDay, cycle1, cycle2, cycle3;
    int lcmResult; 

    while(scanf(" %d", &startDay) != EOF) {

        scanf(" %d %d %d", &cycle1, &cycle2, &cycle3);

        // Calcula o MMC dos três ciclos de forma encadeada
        lcmResult = CalculateLCM(cycle1, CalculateLCM(cycle2, cycle3));
        
        // Imprime a diferença entre o dia de alinhamento e o dia atual
        printf("%d\n", lcmResult - startDay);
    }
    return 0;
}

int CalculateGCD(int m, int n)
/* Retorna o Máximo Divisor Comum (GCD) de m e n */
{
    if (m < 0) m = -m;
    if (n < 0) n = -n;

    if (m % n == 0)
        return n;
    else
        // Algoritmo de Euclides recursivo
        return CalculateGCD(n, m % n);
}

long long int CalculateLCM(int a, int b)
/*	Retorna o Mínimo Múltiplo Comum (LCM) de a e b
    (Adaptado do tutorial topcoder)
*/
{
    // Fórmula: MMC(a, b) = (a * b) / MDC(a, b)
    return b * a / CalculateGCD(a, b);
}