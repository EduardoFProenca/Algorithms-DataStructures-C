/*
Beecrowd : 2204 - Pare a Bomba!
https://judge.beecrowd.com/pt/problems/view/2204

**Explicação do Código:**
Este programa lê um número inteiro `numCases` que indica a quantidade de casos de teste.
Para cada caso, lê duas strings (`stringA` e `stringB`) e realiza uma comparação simples.

A lógica implementada é a seguinte:
- Se as duas strings forem exatamente idênticas (`strcmp` retorna 0), o programa imprime a própria string.
- Se as strings forem diferentes, o programa imprime o número "1".

*/

#include <stdio.h>
#include <string.h>

int main() {
    int numCases;
    char stringA[1001], stringB[1001];

    scanf(" %d", &numCases);
    
    while (numCases > 0) {

        scanf(" %s %s", stringA, stringB);

        // Compara se as strings são iguais
        if (strcmp(stringA, stringB) == 0)
            printf("%s\n", stringA);
        else
            printf("1\n");

        numCases--;
    }
    return 0;
}