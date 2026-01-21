/*
Beecrowd : 1028 - Figurinhas
https://judge.beecrowd.com/pt/problems/view/1028

**Explicação do Código:**
Este programa resolve o problema de encontrar o maior número de figurinhas que podem ser trocadas
entre dois amigos para que ambos fiquem com a mesma quantidade, sem sobrar nenhuma figurinha repetida.
Matematicamente, isso é equivalente a calcular o Máximo Divisor Comum (MDC ou GCD em inglês)
das quantidades de figurinhas de cada pessoa.

O algoritmo utilizado é o Algoritmo de Euclides, implementado de forma recursiva.
Ele funciona substituindo o maior número pelo resto da divisão entre os dois até que um deles seja zero.
O número restante é o MDC.
*/

#include <stdio.h>

// Protótipo da função para calcular o MDC (GCD)
int CalculateGCD(int, int);

int main()
{
    int numCases, quantity1, quantity2;
    scanf(" %d", &numCases);

    for(int i = 0; i < numCases; i++) {
        scanf(" %d %d", &quantity1, &quantity2);

        // Imprime o MDC das duas quantidades lidas
        printf("%d\n", CalculateGCD(quantity1, quantity2));
    }
    return 0;
}

int CalculateGCD(int a, int b)
/* Retorna o Máximo Divisor Comum (GCD) de a e b */
{	
    // Trabalha com valores absolutos para garantir que o algoritmo funcione com negativos
    if (a < 0) a = -a;
    if (b < 0) b = -b;

    if (a % b == 0)
        return b;
    else
        // Chamada recursiva para encontrar o GCD
        return CalculateGCD(b, a % b);
}