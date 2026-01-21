/*
Beecrowd : 1457 - Oráculo de Alexandria
https://judge.beecrowd.com/pt/problems/view/1457

**Explicação do Código:**
Este programa resolve o problema do "Oráculo de Alexandria", que consiste em calcular o fatorial
múltiplo de um número. A entrada é dada em uma string contendo um número inteiro seguido
por vários pontos de exclamação (ex: "3!!" ou "5!!!!").

A lógica funciona da seguinte maneira:
1. Lê a quantidade de casos de teste.
2. Para cada caso, lê a string de entrada.
3. Conta quantos pontos de exclamação ('!') existem na string. Essa quantidade define o "passo"
   do fatorial (de quanto em quanto os números diminuem na multiplicação).
4. Converte a parte numérica da string para um inteiro.
5. Calcula o fatorial múltiplo: Inicia com o número base e multiplica sucessivamente pelos valores
   (base - passo), (base - 2*passo), etc., enquanto o valor for positivo.
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    int numCases;
    int baseNum;
    char inputStr[23];

    scanf("%d", &numCases);

    for(int caseIndex = numCases; caseIndex > 0 ; caseIndex--) {
        scanf(" %s", inputStr);

        int i, factorialStep = 0;
        
        // Percorre a string para contar os pontos de exclamação
        for(i = 0; i < sizeof(inputStr) ; i++) {
            if(inputStr[i] == '!') {
                factorialStep++; // Conta quantos '!' existem (define o passo do fatorial)
                inputStr[i] = ' '; // Substitui '!' por espaço para facilitar o atoi
            }
        }
        
        // Converte a string para o número inteiro base
        baseNum = atoi(inputStr);
        
        long long int result = baseNum;

        // Loop de cálculo do fatorial múltiplo
        // Decrementa o índice pelo valor do passo a cada iteração
        for(int i = baseNum; i > 0 ;) {
            i = i - factorialStep;
            if(i <= 0)
                break;
            result = result * i;
        }
        
        printf("%lld\n", result);
    }
    return 0;
}