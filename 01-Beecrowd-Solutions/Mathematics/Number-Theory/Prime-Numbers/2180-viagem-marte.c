/*
Beecrowd : 2180 - Viagem à Marte na Velocidade de Primo
https://judge.beecrowd.com/pt/problems/view/2180

**Explicação do Código:**
Este programa calcula a duração de uma viagem a Marte baseada em uma "velocidade de primo".
A velocidade é definida como a soma dos 10 primeiros números primos que são maiores ou iguais
ao número inteiro fornecido na entrada.

O fluxo do algoritmo é:
1. Lê um número inteiro de entrada (`startNumber`).
2. A partir desse número, busca os próximos 10 números primos.
3. Soma esses 10 números primos para definir a velocidade da nave (`totalSpeed`).
4. Considerando uma distância fixa de 60.000.000 km, calcula o tempo de viagem em horas.
5. Converte o tempo de horas para dias e imprime a velocidade, as horas e os dias.
*/

#include <math.h>
#include <stdio.h>

#define TRUE  1
#define FALSE 0

char IsPrime(int);

int main()
{
    int startNumber, totalSpeed = 0, primeCount = 0, days;
    double hours;
    
    scanf(" %d", &startNumber);
    int i = 0;

    // Loop para encontrar os 10 primeiros primos a partir de startNumber
    for(i = startNumber; 10 > primeCount; i++) {
        if(IsPrime(i)) {
            primeCount++;
            totalSpeed = i + totalSpeed;
        }
    }

    // Cálculo do tempo: Distância / Velocidade
    hours = 60000000 / totalSpeed;
    days = hours / 24;
    
    printf("%d km/h\n", totalSpeed);
    printf("%.0f h / %d d\n", hours, days);

    return 0;
}

char IsPrime(int n)
/* Retorna TRUE se n for um número primo */
{
    int p, maxP = sqrt(n) + 2;

    if (n < 0) return IsPrime(-n);
    if (n < 5 || !(n % 2) || !(n % 3)) return (n == 2 || n == 3);

    // Otimização verificando apenas divisores da forma 6k ± 1
    for (p = 5; p < maxP; p += 6)
        if ((!(n % p)) || (!(n % (p + 2)))) return FALSE;

    return TRUE;
}