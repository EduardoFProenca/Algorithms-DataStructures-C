/*
Beecrowd : 1153 - Fatorial Simples
https://judge.beecrowd.com/pt/problems/view/1153

**Explicação do Código:**
Este programa lê um número inteiro e calcula o seu fatorial.
O fatorial de um número N (escrito como N!) é o produto de todos os inteiros positivos de 1 até N.
Exemplo: 4! = 4 * 3 * 2 * 1 = 24.

A lógica implementada é a seguinte:
1. Lê um inteiro `number` do usuário.
2. Chama a função `CalculateFactorial`.
3. Dentro da função:
   - Se o número for menor que 0, retorna -1 (caso de erro, embora o problema garanta entrada válida).
   - Se o número for 0, retorna 1 (por definição, 0! = 1).
   - Para qualquer outro número, inicializa `result` com N e multiplica `result` pelos números inteiros antecedentes em um loop decrescente até 1.
4. Imprime o resultado final.
*/

#include <stdio.h>

long long int CalculateFactorial(int n);

int main(int argc, char *argv[])
{
    int number;
    scanf(" %d", &number);
    
    printf("%lld\n", CalculateFactorial(number));
    
    return 0;
}

long long int CalculateFactorial(int n)
{	
    long long int result;
    int i;

    if (n < 0)
        return -1LL;
    else
        if (n == 0)
            return 1LL;
        else
        {
            result = n;
            // Loop que multiplica `result` pelos números de (n-1) até 1
            for (i = n - 1; i > 0; i--)
                result = result * i;
                
            return result;
        }
}