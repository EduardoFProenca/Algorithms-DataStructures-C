#include <stdio.h>
#include <math.h>

// Protótipos das funções que calculam as estatísticas
double calcularMedia(int numeros[], int tamanho);
double calcularVariancia(int numeros[], int tamanho, double media);
double calcularDesvioPadrao(double variancia);
int encontrarModa(int numeros[], int tamanho);

int main() {
    // Array para armazenar os 15 números inteiros
    int numeros[15];
    // Variáveis para armazenar os resultados estatísticos
    double media, desvioPadrao, variancia;
    int moda;
    
    // Loop para ler os 15 números do usuário
    for(int i = 0; i < 15; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }
    
    // Chamada das funções para calcular cada estatística
    media = calcularMedia(numeros, 15);
    variancia = calcularVariancia(numeros, 15, media);
    desvioPadrao = calcularDesvioPadrao(variancia);
    moda = encontrarModa(numeros, 15);
    
    // Impressão dos resultados formatados com 2 casas decimais onde necessário
    printf("\nMédia: %.2f\n", media);
    printf("Variância: %.2f\n", variancia);
    printf("Desvio Padrão: %.2f\n", desvioPadrao);
    printf("Moda: %d\n", moda);
    
    return 0;
}

// Função que calcula a média aritmética dos valores do array
double calcularMedia(int numeros[], int tamanho) {
    double soma = 0;
    // Acumula a soma de todos os elementos
    for(int i = 0; i < tamanho; i++) {
        soma += numeros[i];
    }
    // Retorna a soma dividida pela quantidade de elementos
    return soma / tamanho;
}

// Função que calcula a variância (média dos quadrados das diferenças em relação à média)
double calcularVariancia(int numeros[], int tamanho, double media) {
    double somaQuadrados = 0;
    for(int i = 0; i < tamanho; i++) {
        // Soma o quadrado da diferença entre cada número e a média geral
        somaQuadrados += pow((numeros[i] - media), 2);
    }
    // Retorna a soma dos quadrados dividida pelo tamanho
    return somaQuadrados / tamanho;
}

// Função que calcula o desvio padrão (raiz quadrada da variância)
double calcularDesvioPadrao(double variancia) {
    return sqrt(variancia);
}

// Função que encontra o valor que mais se repete (moda)
// Em caso de empate de frequência, retorna o maior valor numérico
int encontrarModa(int numeros[], int tamanho) {
    int moda = numeros[0];
    int maiorFrequencia = 0;
    
    // Loop principal: percorre cada número para verificar sua frequência
    for(int primeiro  = 0; primeiro  < tamanho; primeiro ++) {
        int frequenciaAtual = 0;
        // Loop secundário: conta quantas vezes o número 'primeiro' aparece no array
        for(int segundo = 0; segundo < tamanho; segundo++) {
            if(numeros[primeiro ] == numeros[segundo]) {
                frequenciaAtual++;
            }
        }
        // Atualiza a moda se a frequência atual for maior que a maior encontrada até agora.
        // Se a frequência for igual, escolhe o número maior (conforme a lógica: numeros[primeiro] > moda)
        if(frequenciaAtual > maiorFrequencia || (frequenciaAtual == maiorFrequencia && numeros[primeiro ] > moda)) {
            maiorFrequencia = frequenciaAtual;
            moda = numeros[primeiro ];
        }
    }
    return moda;
}