/*
Beecrowd : 2589 - Maior Distância Entre Primos Consecutivos
https://judge.beecrowd.com/pt/problems/view/2589

**Explicação do Código:**
Este programa tem como objetivo encontrar a maior diferença (o maior "gap") entre dois números primos
consecutivos dentro de um intervalo que vai de 2 até um número limite N fornecido.

O algoritmo funciona da seguinte maneira:
1. Lê o valor limite `upperBound`.
2. Percorre todos os números inteiros de 2 até `upperBound`.
3. Para cada número, verifica se ele é primo usando a função auxiliar `IsPrime`.
4. Se o número atual for primo:
   - Se já houver um primo anterior identificado (`lastPrime`), calcula a distância entre eles.
   - Atualiza a variável `maxDistance` se essa distância for maior que a registrada anteriormente.
   - Atualiza o `lastPrime` para o número atual.
5. Ao final do loop, imprime a maior distância encontrada.
*/

#include <stdio.h>
#include <math.h>

#define TRUE  1
#define FALSE 0

char IsPrime(int n);

int main()
{
    int upperBound;
    
    while (scanf(" %d", &upperBound) != EOF) {
        int lastPrime = 0;  
        int maxDistance = 0;  
        int currentNum;

        // Loop de 2 até o limite fornecido
        for (currentNum = 2; currentNum <= upperBound; currentNum++) {
            if (IsPrime(currentNum)) {
                // Se não é o primeiro primo encontrado (lastPrime != 0)
                if (lastPrime != 0) {
                    // Calcula a distância entre o primo atual e o anterior
                    int currentDist = currentNum - lastPrime;
                    // Se a distância atual for maior que a máxima registrada, atualiza
                    if (currentDist > maxDistance) 
                        maxDistance = currentDist;
                }
                // Atualiza o último primo encontrado
                lastPrime = currentNum;
            }
        }

        printf("%d\n", maxDistance);
    }
    return 0;
}

char IsPrime(int n)
/* Retorna TRUE se n for um número primo */
{	
    int p, maxP = sqrt(n) + 2;

    if (n < 0) return IsPrime(-n);
    if (n < 5 || !(n % 2) || !(n % 3)) return (n == 2 || n == 3);

    // Otimização: verificando divisores de 6k ± 1
    for (p = 5; p < maxP; p += 6)
        if ((!(n % p)) || (!(n % (p + 2)))) return FALSE;

    return TRUE;
}