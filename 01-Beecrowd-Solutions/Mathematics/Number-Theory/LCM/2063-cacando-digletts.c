/*
Beecrowd : 2063 - Caçando Digletts
https://judge.beecrowd.com/pt/problems/view/2063

**Explicação do Código:**
Este programa determina o momento em que um conjunto de Digletts aparecerão simultaneamente na superfície novamente.
Para isso, é necessário calcular o Mínimo Múltiplo Comum (MMC ou LCM) de todos os intervalos de tempo fornecidos.

O algoritmo funciona da seguinte forma:
1. Lê a quantidade de números (intervalos).
2. Calcula o MMC de forma progressiva:
   - Inicia o resultado com o primeiro número.
   - Para cada número subsequente, calcula o MMC entre o resultado acumulado e o novo número.
   - O MMC de dois números é calculado pela fórmula: `(a * b) / MDC(a, b)`.
*/

#include <stdio.h>

// Protótipos das funções
long long int CalculateLCM(int, int);
int CalculateGCD(int, int);

int main()
{
    int numElements, firstNumber, nextNumber;
    long long int lcmResult = 0;
    
    scanf("%d", &numElements);
    scanf("%d", &firstNumber);
    
    // Inicializa o resultado com o primeiro valor lido
    lcmResult = firstNumber;

    // Loop para processar os números restantes
    for(int i = 1; i < numElements ; i++) {
        scanf(" %d", &nextNumber);
        // Atualiza o resultado calculando o MMC entre o valor atual e o próximo
        lcmResult = CalculateLCM(lcmResult, nextNumber);
    }
    
    printf("%lld\n", lcmResult);

    return 0;
}

long long int CalculateLCM(int a, int b)
/*	Retorna o Mínimo Múltiplo Comum (LCM) de a e b
    (Adaptado do tutorial topcoder)
*/
{	
    return b * a / CalculateGCD(a, b);
}

int CalculateGCD(int m, int n)
/* Retorna o Máximo Divisor Comum (GCD) de m e n */
{	
    // Trabalha com valores absolutos
    if (m < 0) m = -m;
    if (n < 0) n = -n;

    if (m % n == 0)
        return n;
    else
        // Chamada recursiva do Algoritmo de Euclides
        return CalculateGCD(n, m % n);
}