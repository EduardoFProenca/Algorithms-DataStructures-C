/*
Beecrowd : 1429 - Fatorial de Novo!
https://judge.beecrowd.com/pt/problems/view/1429

**Explicação do Código:**
Este programa resolve o problema de calcular o "Fatorial de Novo".
A lógica consiste em ler um número inteiro e processá-lo dígito por dígito,
da direita para a esquerda (unidades, dezenas, centenas...).

Para cada dígito encontrado na posição i (começando de 1):
1. Calcula o fatorial da posição i (i!).
2. Multiplica o valor do dígito pelo fatorial calculado.
3. Acumula esse valor em uma soma total.

O programa imprime o total para cada número lido, até que o número 0 seja inserido para encerrar.
*/

#include <stdio.h>
#include <math.h>

#define TRUE  1
#define FALSE 0

// Protótipo da função de cálculo de fatorial
long long int CalculateFactorial(int);

int main()
{
    int number;
    int sum = 0; // Variável para armazenar o resultado da soma
    
    do {
        scanf(" %d", &number);
        
        // Se o número for 0, encerra o loop e o programa
        if(number == 0)
            break;
            
        // Loop que percorre os dígitos do número da direita para a esquerda
        // 'i' representa a posição do dígito (1ª, 2ª, 3ª...)
        for(int i = 1; number != 0 ; i++) {
            // Pega o último dígito com o operador módulo (%) e multiplica pelo fatorial da posição
            sum += ((number % 10) * CalculateFactorial(i));
            // Remove o último dígito dividindo por 10
            number = number / 10;
        }

        printf("%d\n", sum);
        // Reinicia a soma para o próximo caso de teste
        sum = 0;
    } while(1); // Loop infinito, encerrado apenas pelo 'break' quando num == 0
    
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
        // Loop de multiplicação de 1 até n (ou n até 1)
        for (i = n - 1; i > 0; i--)
            result = result * i;

        return result;
    }
}