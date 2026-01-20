/*
Beecrowd : 2718 - Luzes de Natal
https://judge.beecrowd.com/pt/problems/view/2718

**Explicação do Código:**
O objetivo deste programa é determinar o maior tempo de espera (ou a maior sequência de luzes acesas)
ao analisar a representação binária de um número.

A lógica funciona da seguinte maneira:
1. Lê-se a quantidade de números a serem processados.
2. Para cada número:
   a. Converte-se o número decimal para uma string binária (invertida, calculada pelo resto da divisão por 2).
   b. Percorre-se a string binária para contar a maior sequência consecutiva de dígitos '1'.
3. Imprime-se o tamanho da maior sequência de '1's encontrada.

Isso resolve o problema, pois a ordem dos bits na string não afeta a contagem de sequências consecutivas,
apenas a ordem relativa entre 0 e 1, que é preservada em blocos.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{

    char binaryString[1001]; // String para armazenar a representação binária
    unsigned long long numCases, currentNumber;
    
    scanf(" %llu", &numCases); // Lê a quantidade de casos de teste
    
    for(int i = 0; i < numCases; i++) {
        scanf(" %llu", &currentNumber); // Lê o número decimal atual

        int binaryIndex;
        // Loop de conversão de Decimal para Binário (divide por 2 sucessivamente)
        for(binaryIndex = 0; currentNumber != 0; binaryIndex++) {
            // Armazena o resto da divisão (0 ou 1) como caractere na string
            binaryString[binaryIndex] = (currentNumber % 2) + '0';
            currentNumber = currentNumber / 2;
        }
        binaryString[binaryIndex] = '\0'; // Adiciona o terminador nulo ao final da string

        int currentOnes = 0, maxOnes = 0;
        
        // Loop para percorrer a string binária e encontrar a maior sequência de '1's
        for (int j = 0; j < strlen(binaryString); j++) {
            if(binaryString[j] == '1') {
                currentOnes++; // Incrementa a contagem da sequência atual de '1's
            } else {
                // Se encontrou um '0', verifica se a sequência que acabou é a maior
                if (maxOnes < currentOnes)
                    maxOnes = currentOnes;
                currentOnes = 0; // Reinicia a contagem da sequência atual
            }
        }
        
        // Verificação final após o loop, caso o número termine com uma sequência de '1's
        if (currentOnes > maxOnes)
            maxOnes = currentOnes;

        printf("%d\n", maxOnes); // Imprime o tamanho da maior sequência encontrada
    }
    return 0;
}