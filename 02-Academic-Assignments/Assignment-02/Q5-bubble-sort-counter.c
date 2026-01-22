/*
 * Este programa implementa o algoritmo de ordenação "Bubble Sort" (ou
 * Método da Bolha) para organizar um vetor de 10 números inteiros em ordem
 * crescente. Além de ordenar, ele conta quantas trocas de posição foram
 * necessárias e verifica se o vetor já estava ordenado.
 *
 * 1. ENTRADA DE DADOS:
 *    - O usuário deve digitar 10 números inteiros, que são armazenados em um vetor (array).
 *
 * 2. LÓGICA DE ORDENAÇÃO (Bubble Sort Otimizado):
 *    - O programa utiliza um laço `do-while` que continua rodando enquanto
 *      trocas estão sendo feitas.
 *    - Dentro de cada passada pelo vetor, o programa compara elementos adjacentes.
 *    - Se o elemento da esquerda for maior que o da direita, eles trocam de lugar.
 *    - Uma flag booleana `isUnsorted` é usada para verificar se houve alguma
 *      troca na passada atual. Se nenhuma troca ocorrer, significa que o vetor
 *      já está ordenado e o loop para imediatamente.
 *
 * 3. CONTAGEM DE TROCAS:
 *    - Cada vez que dois números trocam de lugar, a variável `totalSwaps`
 *      é incrementada.
 *
 * 4. SAÍDA:
 *    - Se `totalSwaps` for zero, imprime "Vetor ja ordenado".
 *    - Caso contrário, exibe o vetor ordenado e o total de trocas realizadas.
 */

#include <stdio.h>
#include <stdbool.h>

int main()
{
    // Vetor para armazenar os 10 números
    int numbersArray[10];
    
    // Flag para controlar o loop de ordenação (true = ainda desordenado)
    bool isUnsorted;
    
    // Variável para contar o total de trocas e variável auxiliar para troca
    int totalSwaps = 0, temp = 0;
    
    // --- BLOCO 1: Leitura dos dados ---
    for(int i = 0; i < 10; i++ ){
        printf("Digite o %dº número: ", i + 1);
        scanf("%d", &numbersArray[i]); 
    }
    
    // --- BLOCO 2: Algoritmo de Ordenação (Bubble Sort) ---
    do {
        // Assume no início de cada passada que o vetor está ordenado
        isUnsorted = false;
        
        // Percorre o vetor até a penúltima posição (porque compara com i+1)
        for(int i = 0; i < 9; i++){
            
            // Verifica se o elemento atual é maior que o próximo
            if(numbersArray[i] > numbersArray[i + 1]){
                
                // --- Lógica de Troca (Swap) ---
                temp = numbersArray[i];          // Guarda o valor atual em temp
                numbersArray[i] = numbersArray[i + 1]; // Move o próximo para a posição atual
                numbersArray[i + 1] = temp;      // Move o valor de temp para a próxima posição
                
                // Atualiza as variáveis de controle
                totalSwaps++;       // Incrementa o contador de trocas
                isUnsorted = true;  // Indica que houve troca, logo o vetor estava desordenado
            }
        }
    } while(isUnsorted); // Repete o processo se houve alguma troca na passada anterior
    
    // --- BLOCO 3: Exibição dos Resultados ---
    if (totalSwaps == 0){
        // Se não houve trocas, o vetor já estava ordenado desde o início
        printf("\n Vetor ja ordenado ");
    }
    else{
        // Imprime o vetor agora ordenado
        for(int i = 0; i < 10; i++ ){
            printf("%i ", numbersArray[i]);
        }
        // Imprime o total de trocas realizadas
        printf("\n %i  Trocas foram necessarias", totalSwaps);
    }
    
    return 0;
}