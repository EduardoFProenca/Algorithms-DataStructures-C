/*
Beecrowd : 1980 - Embaralhando
https://judge.beecrowd.com/pt/problems/view/1980

**Explicação do Código:**
Este programa lê uma série de strings (palavras) e calcula a quantidade de permutações possíveis
(anagramas) para cada uma delas.
O processo é o seguinte:
1. Lê uma string do usuário.
2. Se a string for igual a "0", o programa é encerrado.
3. Para qualquer outra string, calcula o fatorial do tamanho da string (quantidade de caracteres).
   - O código assume o caso mais simples onde todos os caracteres são distintos, 
     onde o número de permutações é dado por N! (N fatorial).
4. Imprime o resultado do cálculo.
*/

#include <stdio.h>
#include <string.h>

// Protótipo da função de cálculo de fatorial
long long int CalculateFactorial(int n);

int main()
{
    int num; // Variável mantida conforme original, embora não utilizada na lógica do loop
    char inputString[16];

    while (1) {
        scanf(" %s", inputString);
        if(inputString[0] == '0')
            break;
            
        // Calcula e imprime o fatorial do tamanho da string lida
        printf("%lld\n", CalculateFactorial(strlen(inputString)));
    }
    return 0;
}

// Função para calcular o fatorial de um número inteiro
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
            // Loop de multiplicação regressiva
            for (i = n - 1; i > 0; i--)
                result = result * i;
                
            return result;
        }
}