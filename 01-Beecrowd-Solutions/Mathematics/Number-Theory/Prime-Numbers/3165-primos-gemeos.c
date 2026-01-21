/*
Beecrowd : 3165 - Primos Gêmeos
https://judge.beecrowd.com/pt/problems/view/3165

**Explicação do Código:**
Este programa lê um número inteiro e encontra o maior par de primos gêmeos (twin primes)
que seja menor ou igual a esse número.
Primos gêmeos são dois números primos que possuem uma diferença de 2 entre si (ex: 3 e 5, 11 e 13).

A lógica do algoritmo é a seguinte:
1. Lê um número inteiro `number`.
2. Verifica se o número está dentro do intervalo permitido (5 a 1000).
3. Executa um loop decrementando o número a partir do valor de entrada até que seja encontrada
   uma situação onde `number` é primo E `number - 2` também é primo.
4. Quando esse par é encontrado, imprime os dois valores (`number - 2` e `number`).
*/

#include <stdio.h>
#include <math.h>

#define TRUE  1
#define FALSE 0

char IsPrime(int n);

int main(int argc, char *argv[])
{
    int number;

    scanf(" %d", &number);

    // Verifica se o número está dentro das restrições do problema
    if(5 <= number && number <= 1000) {
        // Loop regressivo procurando o par de primos gêmeos
        while(number > 0) {
            // Verifica se o número atual e o número duas unidades menor são primos
            if (IsPrime(number) && IsPrime(number - 2)) {
                break;
            }
            number--;
        }
        // Imprime o par encontrado (menor, maior)
        printf("%d %d\n", number - 2, number);
    }

    return 0;
}

char IsPrime(int n)
/* Retorna TRUE se n for um número primo */
{	
    int i, limit = sqrt(n) + 2;

    if (n < 0) return IsPrime(-n);
    if (n < 5 || !(n % 2) || !(n % 3)) return (n == 2 || n == 3);

    // Otimização: verificando divisores de 6k ± 1
    for (i = 5; i < limit; i += 6)
        if ((!(n % i)) || (!(n % (i + 2)))) return FALSE;

    return TRUE;
}