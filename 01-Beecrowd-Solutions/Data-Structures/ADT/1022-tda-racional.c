/*
Beecrowd : 1022 - TDA Racional
https://judge.beecrowd.com/pt/problems/view/1022

**Explicação do Código:**
Este programa realiza operações matemáticas (adição, subtração, multiplicação e divisão) 
entre números racionais (frações). O processo é o seguinte:
1. Lê a quantidade de casos de teste.
2. Para cada caso, lê duas frações (numerador/denominador) e um operador.
3. Executa a operação correspondente seguindo as regras matemáticas para frações.
4. Simplifica o resultado obtido dividindo o numerador e o denominador pelo 
   Máximo Divisor Comum (MDC ou GCD em inglês).
5. Imprime o resultado não simplificado e o resultado simplificado no formato "N1/D1 = N2/D2".
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Definição da estrutura para números racionais
typedef struct { int numerator, denominator; } TRational;

/* Protótipos das funções */
TRational AddRational(TRational, TRational);
TRational SubRational(TRational, TRational);
TRational MultRational(TRational, TRational);
TRational DivRational(TRational, TRational);
TRational SimplifyRational(TRational);
int gcd(int, int); // GCD = Greatest Common Divisor (MDC)

int main(void)
{
    TRational r1, r2, result, copyResult;
    int testCases, i;
    char operator;

    scanf(" %d", &testCases);

    // Arrays para armazenar os resultados (bruto e simplificado) de cada teste
    TRational rawResults[testCases];
    TRational simplifiedResults[testCases];

    // Verificação de range mantida da lógica original
    if (1 <= testCases && 10000 >= testCases)
        for (i = 0; i < testCases; i++) {
            scanf("%d / %d %c %d / %d", &r1.numerator, &r1.denominator, &operator, &r2.numerator, &r2.denominator);

            switch (operator) {
                case '+':
                    result = AddRational(r1, r2);
                    break;

                case '-':
                    result = SubRational(r1, r2);
                    break;

                case '*':
                    result = MultRational(r1, r2);
                    break;

                case '/':
                    result = DivRational(r1, r2);
                    break;

                default:
                    return 1;
            }
            // Copia o resultado para simplificação (mantendo a lógica original da variável 'b')
            copyResult = result;
            rawResults[i] = result;
            simplifiedResults[i] = SimplifyRational(copyResult);
        }

    // Loop de impressão dos resultados
    for (int i = 0; i < testCases; i++) {
        printf("%d/%d = %d/%d\n", rawResults[i].numerator, rawResults[i].denominator,
               simplifiedResults[i].numerator, simplifiedResults[i].denominator);
    }

    return 0;
}

// Função de Adição
TRational AddRational(TRational n1, TRational n2)
{
    TRational res;
    res.numerator = n1.numerator * n2.denominator + n2.numerator * n1.denominator;
    res.denominator = n1.denominator * n2.denominator;
    return res;
}

// Função de Subtração
TRational SubRational(TRational n1, TRational n2)
{
    TRational res;
    res.numerator = n1.numerator * n2.denominator - n2.numerator * n1.denominator;
    res.denominator = n1.denominator * n2.denominator;
    return res;
}

// Função de Multiplicação
TRational MultRational(TRational n1, TRational n2)
{
    TRational res;
    res.numerator = n1.numerator * n2.numerator;
    res.denominator = n1.denominator * n2.denominator;
    return res;
}

// Função de Divisão
TRational DivRational(TRational n1, TRational n2)
{
    TRational res;
    res.numerator = n1.numerator * n2.denominator;
    res.denominator = n2.numerator * n1.denominator;
    return res;
}

// Função de Simplificação
TRational SimplifyRational(TRational n1)
{
    TRational res;
    res.numerator = n1.numerator / gcd(n1.numerator, n1.denominator);
    res.denominator = n1.denominator / gcd(n1.numerator, n1.denominator);
    return res;
}

// Função para calcular o Máximo Divisor Comum (GCD)
int gcd(int m, int n)
{
    if (m < 0) m = -m;
    if (n < 0) n = -n;
    if (m % n == 0)
        return n;
    else
        return gcd(n, m % n);
}