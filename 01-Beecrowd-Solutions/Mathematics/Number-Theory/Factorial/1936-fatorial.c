/*
Beecrowd : 1936 - Fatorial
https://judge.beecrowd.com/pt/problems/view/1936

**Explicação do Código:**
Este programa resolve o problema de decompor um número inteiro em uma soma de fatoriais distintos.
O objetivo é encontrar a menor quantidade possível de termos fatoriais que somados resultam no número de entrada.

A lógica implementada utiliza uma abordagem gulosa (greedy):
1. Lê o número alvo (`targetNum`).
2. Encontra o maior número `i` tal que o fatorial de `i` seja menor ou igual ao número alvo.
3. Subtrai esse fatorial do alvo e incrementa a contagem de termos.
4. Repete o processo para o valor restante, testando fatoriais menores (decrementando o índice),
   até que a soma dos fatoriais seja igual ao número original.
*/

#include <stdio.h>
#include <math.h>

// Protótipo da função de cálculo de fatorial
long long int CalculateFactorial(int);

int main()
{
    int targetNum, count = 0, currentSum = 0;
    int i = 0;
    scanf(" %d", &targetNum);

    // Primeiro loop: Encontra o limite onde i! excede o número alvo
    // Assim, sabemos que (i-1)! é o maior fatorial que podemos usar.
    for(i = 1; targetNum != 0 ; i++) {
        if( targetNum < CalculateFactorial(i) )
            break;
    }

    // Ajusta 'i' para o maior fatorial válido (menor ou igual ao alvo)
    i = i - 1;
    currentSum += CalculateFactorial(i);
    count++;

    // Segundo loop: Tenta preencher o restante do valor com fatoriais menores
    for(int j = i ; targetNum != currentSum; ) {
        // Se adicionar o fatorial atual (j!) exceder o alvo, tenta um fatorial menor
        if(targetNum < (currentSum + CalculateFactorial(j)) ) {
            j--;
        }
        else {
            // Se cabe, adiciona à soma e incrementa a contagem
            currentSum += CalculateFactorial(j) ;
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}

// Função para calcular o fatorial de um número inteiro
long long int CalculateFactorial(int n)
/* Retorna o fatorial de n */
{	
    long long int result;
    int i;

    if (n < 0)
        return -1LL;
    else if (n == 0)
        return 1LL;
    else
    {
        result = n;
        // Loop de multiplicação
        for (i = n - 1; i > 0; i--)
            result = result * i;

        return result;
    }
}