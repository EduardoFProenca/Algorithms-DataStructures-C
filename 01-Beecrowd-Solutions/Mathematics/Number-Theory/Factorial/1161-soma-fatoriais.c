/*
Beecrowd : 1161 - Soma de Fatoriais
https://judge.beecrowd.com/pt/problems/view/1161

**Explicação do Código:**
Este programa lê dois números inteiros e calcula a soma de seus fatoriais.
O fatorial de um número n (escrito como n!) é o produto de todos os inteiros positivos de 1 até n.
Exemplo: 3! = 3 * 2 * 1 = 6.

O fluxo do algoritmo é:
1. Lê múltiplos pares de números até o fim da entrada (EOF).
2. Para cada par, calcula o fatorial do primeiro número.
3. Calcula o fatorial do segundo número.
4. Soma os dois valores e imprime o resultado.
*/

#include <stdio.h>

// Protótipo da função de cálculo de fatorial
long long int CalculateFactorial(int n);

int main()
{
    int num1, num2;

    // Loop que continua lendo enquanto houverem dois números na entrada
    while (scanf(" %d %d", &num1, &num2) != EOF )
    {
        // Imprime a soma dos fatoriais de num1 e num2
        printf("%lld\n", CalculateFactorial(num1) + CalculateFactorial(num2));
    }

    return 0;
}

// Função para calcular o fatorial de um número inteiro
long long int CalculateFactorial(int n)
{
    long long int result;
    int i;

    if (n < 0)
        return -1LL; // Tratamento para números negativos
    else if (n == 0)
        return 1LL; // Por definição, o fatorial de 0 é 1
    else
    {
        // Inicializa o resultado com n
        result = n;
        
        // Multiplica result pelos números inteiros antecedentes até chegar em 1
        for (i = n - 1; i > 0; i--)
            result = result * i;

        return result;
    }
}