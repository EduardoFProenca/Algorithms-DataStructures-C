/*
 * Este programa implementa a Função de Ackermann (Ackermann-Péter), uma
 * função matemática clássica utilizada em ciência da computação para demonstrar
 * o conceito de recursão profunda e as limitações de sistemas primitivos recursivos.
 *
 * CARACTERÍSTICAS:
 * - É uma função total computável, mas não é primitiva recursiva.
 * - Possui um crescimento extremamente rápido. Mesmo para entradas pequenas
 *   (ex: m=4, n=2), o resultado é um número astronômico.
 * - Devido à profundidade da recursão, entradas relativamente baixas (como m > 3)
 *   podem causar "Stack Overflow" (estouro de pilha) e travar o programa.
 *
 * DEFINIÇÃO MATEMÁTICA UTILIZADA:
 * A(m, n) =
 * - n + 1                       se m = 0
 * - A(m - 1, 1)                 se m > 0 e n = 0
 * - A(m - 1, A(m, n - 1))       se m > 0 e n > 0
 *
 * ENTRADA E SAÍDA:
 * - O programa solicita dois valores inteiros, m e n.
 * - Calcula o resultado recursivamente e o exibe.
 * - Encerra a execução quando o usuário digita 0 para ambos os valores (0 0).
 */

#include <stdio.h>

// Protótipo da função recursiva de Ackermann
int calculateAckermann(int m, int n);

int main()
{
    // Variáveis inteiras para armazenar os argumentos m e n fornecidos pelo usuário
    int valM, valN;

    // Loop 'do-while' que continua executando até que ambos valM e valN sejam 0
    do {
        // Solicita ao usuário os valores de m e n
        printf("Ackermann m e n? \n");
        scanf(" %d %d", &valM, &valN);
        
        // Verifica se o usuário não digitou 0 0 (condição de saída do programa)
        if (valM != 0 || valN != 0) {
            // Chama a função Ackermann com os valores fornecidos e imprime o resultado
            printf("Ackermann: %d\n", calculateAckermann(valM, valN));
        }
    // O loop repete enquanto valM ou valN forem diferentes de 0
    } while (valM != 0 || valN != 0);
    
    return 0;
}

// Implementação da Função de Ackermann
// É uma função matemática recursiva que cresce muito rapidamente
int calculateAckermann(int m, int n) {
    // Caso base: Se m é 0, retorna n + 1
    if (m == 0) {
        return n + 1;
    } 
    // Se m é maior que 0 e n é 0, chama a função recursivamente para (m-1, 1)
    else if (n == 0) {
        return calculateAckermann(m - 1, 1);
    } 
    // Se m e n são maiores que 0, faz a chamada recursiva dupla (recursão aninhada)
    else {
        return calculateAckermann(m - 1, calculateAckermann(m, n - 1));
    }
}