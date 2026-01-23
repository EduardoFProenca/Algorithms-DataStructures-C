/*
 * Este programa realiza uma análise estatística básica sobre um conjunto de
 * 15 números inteiros fornecidos pelo usuário.
 *
 * ESTATÍSTICAS CALCULADAS:
 * 1. MÉDIA ARITMÉTICA (Mean): A soma de todos os valores dividida pelo número de elementos.
 * 2. VARIÂNCIA (Variance): A média dos quadrados das diferenças entre cada valor
 *    e a média geral. Indica o quão dispersos os dados estão.
 * 3. DESVIO PADRÃO (Standard Deviation): A raiz quadrada da variância.
 * 4. MODA (Mode): O valor que aparece com maior frequência no conjunto de dados.
 *    - Critério de Desempate: Se houver empate na frequência, o programa retorna
 *      o maior valor numérico entre os que empataram.
 */

#include <stdio.h>
#include <math.h>

// Protótipos das funções que calculam as estatísticas
double calculateMean(int numbers[], int size);
double calculateVariance(int numbers[], int size, double mean);
double calculateStandardDeviation(double variance);
int findMode(int numbers[], int size);

int main() {
    // Array para armazenar os 15 números inteiros
    int numbers[15];
    // Variáveis para armazenar os resultados estatísticos
    double mean, standardDeviation, variance;
    int mode;
    
    // Loop para ler os 15 números do usuário
    for(int i = 0; i < 15; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }
    
    // Chamada das funções para calcular cada estatística
    mean = calculateMean(numbers, 15);
    variance = calculateVariance(numbers, 15, mean);
    standardDeviation = calculateStandardDeviation(variance);
    mode = findMode(numbers, 15);
    
    // Impressão dos resultados formatados com 2 casas decimais onde necessário
    printf("\nMedia: %.2f\n", mean);
    printf("Variancia: %.2f\n", variance);
    printf("Desvio Padrao: %.2f\n", standardDeviation);
    printf("Moda: %d\n", mode);
    
    return 0;
}

// Função que calcula a média aritmética dos valores do array
double calculateMean(int numbers[], int size) {
    double sum = 0;
    // Acumula a soma de todos os elementos
    for(int i = 0; i < size; i++) {
        sum += numbers[i];
    }
    // Retorna a soma dividida pela quantidade de elementos
    return sum / size;
}

// Função que calcula a variância (média dos quadrados das diferenças em relação à média)
double calculateVariance(int numbers[], int size, double mean) {
    double sumOfSquares = 0;
    for(int i = 0; i < size; i++) {
        // Soma o quadrado da diferença entre cada número e a média geral
        sumOfSquares += pow((numbers[i] - mean), 2);
    }
    // Retorna a soma dos quadrados dividida pelo tamanho
    return sumOfSquares / size;
}

// Função que calcula o desvio padrão (raiz quadrada da variância)
double calculateStandardDeviation(double variance) {
    return sqrt(variance);
}

// Função que encontra o valor que mais se repete (moda)
// Em caso de empate de frequência, retorna o maior valor numérico
int findMode(int numbers[], int size) {
    int mode = numbers[0];
    int highestFrequency = 0;
    
    // Loop principal: percorre cada número para verificar sua frequência
    for(int outer = 0; outer < size; outer++) {
        int currentFrequency = 0;
        
        // Loop secundário: conta quantas vezes o número atual ('outer') aparece no array
        for(int inner = 0; inner < size; inner++) {
            if(numbers[outer] == numbers[inner]) {
                currentFrequency++;
            }
        }
        
        // Atualiza a moda se:
        // 1. A frequência atual for maior que a maior encontrada até agora.
        // 2. OU se a frequência for igual, escolhe o número maior (lógica de desempate).
        if(currentFrequency > highestFrequency || (currentFrequency == highestFrequency && numbers[outer] > mode)) {
            highestFrequency = currentFrequency;
            mode = numbers[outer];
        }
    }
    return mode;
}