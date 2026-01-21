/*
Beecrowd : 2129 - Fatorial
https://judge.beecrowd.com/pt/problems/view/2129

**Explicação do Código:**
Este programa calcula o último dígito não zero do fatorial de um número N (N!).
Como fatoriais de números grandes são gigantes, é impossível armazenar o valor completo em tipos inteiros comuns.
Para resolver isso, o algoritmo utiliza uma técnica de truncamento e remoção de zeros:
1. Calcula o fatorial iterativamente.
2. A cada multiplicação, remove todos os zeros à direita do número, pois eles não afetam o último dígito não zero final.
3. Mantém o valor truncado dentro de um limite seguro (módulo 1.000.000), pois apenas os últimos dígitos são relevantes para determinar o resultado final.
*/

#include <stdio.h>

int main()
{
    int number;
    long long int aux; 
    int instanceNumber = 0;

    while(scanf(" %d", &number)!= EOF ) {

        instanceNumber++;

        long long int nonZeroPart = 1;

        for (int j = 2; j <= number; j++) {

            nonZeroPart = nonZeroPart * j;

            // Remove zeros à direita que aparecem na multiplicação
            while (nonZeroPart % 10 == 0) {
                nonZeroPart /= 10;
            }
            // Mantém o número pequeno para evitar estouro de memória (overflow)
            nonZeroPart = nonZeroPart % 1000000;
        }

        int result = nonZeroPart % 10;

        printf("Instancia %d\n", instanceNumber);
        printf("%lld\n\n", result % 10 );

    }

    return 0;
}