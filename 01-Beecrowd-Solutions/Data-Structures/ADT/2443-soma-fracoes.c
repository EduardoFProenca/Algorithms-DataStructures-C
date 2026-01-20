/*
Beecrowd : 2443 - Soma de Frações
https://judge.beecrowd.com/pt/problems/view/2443

**Explicação do Código:**
Este programa tem como objetivo calcular a soma de dois números racionais (frações)
e apresentar o resultado na sua forma mais simples (irredutível).

O fluxo de execução é:
1. Lê o numerador e o denominador de duas frações.
2. Realiza a soma das frações utilizando a fórmula matemática padrão:
   (N1 * D2 + N2 * D1) / (D1 * D2).
3. Simplifica o resultado obtido dividindo tanto o numerador quanto o denominador
   pelo Máximo Divisor Comum (MDC ou GCD).
4. Imprime o numerador e o denominador do resultado simplificado.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Definição da estrutura para números racionais
typedef struct { int numerator, denominator; } TRational;

// Protótipos das funções
TRational AddRational(TRational, TRational);
TRational SimplifyRational(TRational);
int gcd(int, int); // GCD = Greatest Common Divisor (Máximo Divisor Comum)

int main(void)
{
    TRational f1, f2, sumResult, copyResult;

    // Leitura das duas frações (Numerador e Denominador da 1ª e da 2ª fração)
    scanf("%d %d %d %d", &f1.numerator, &f1.denominator, &f2.numerator, &f2.denominator);

    // Verifica se os números estão dentro do intervalo permitido (1 a 100)
    if ((f1.numerator >= 1 && 100 >= f1.numerator) &&
        (f1.denominator >= 1 && 100 >= f1.denominator) &&
        (f2.numerator >= 1 && 100 >= f2.numerator) &&
        (f2.denominator >= 1 && 100 >= f2.denominator)) {

        sumResult = AddRational(f1, f2); // Calcula a soma das frações
        copyResult = sumResult;          // Cria uma cópia para preservar o estado intermediário
        sumResult = SimplifyRational(copyResult); // Simplifica o resultado

        printf("%d %d\n", sumResult.numerator, sumResult.denominator);
    }
    return 0;
}

// Função para somar duas frações
TRational AddRational(TRational n1, TRational n2)
{
    TRational result;
    // Fórmula: (N1*D2 + N2*D1) / (D1*D2)
    result.numerator = n1.numerator * n2.denominator + n2.numerator * n1.denominator;
    result.denominator = n1.denominator * n2.denominator;

    return result;
}

// Função para simplificar a fração
TRational SimplifyRational(TRational n1)
{
    TRational result;
    // Divide ambos pelo MDC para obter a fração irredutível
    result.numerator = n1.numerator / gcd(n1.numerator, n1.denominator);
    result.denominator = n1.denominator / gcd(n1.numerator, n1.denominator);

    return result;
}

// Função recursiva para calcular o Máximo Divisor Comum (Algoritmo de Euclides)
int gcd(int m, int n)
{
    if (m < 0) m = -m;
    if (n < 0) n = -n;

    if (m % n == 0)
        return n;
    else
        return gcd(n, m % n);
}